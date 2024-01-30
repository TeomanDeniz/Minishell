/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_here_doc_operator.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:51:15 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 17:51:16 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#typedef t_operator;
#    int set_here_doc_operator(char *, t_operator);
#*/
#include <stdbool.h> /*
# define false;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

int
	reset_here_doc_operator(char *input, t_operator operator)
{
	int	result;

	operator->double_quote = false;
	operator->single_quote = false;
	operator->pipe = false;
	result = set_here_doc_operator(input, operator);
	if (result < 0)
	{
		operator->double_quote = false;
		operator->single_quote = false;
		operator->pipe = false;
		return (0);
	}
	return (result);
}
