/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_here_doc_operator.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:51:15 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 17:51:16 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#typedef t_operator;
#   void set_here_doc_operator(char *, t_operator);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	reset_here_doc_operator(char *input, t_operator operator)
{
	operator->double_quote = 0;
	operator->single_quote = 0;
	operator->pipe = 0;
	set_here_doc_operator(input, operator);
}
