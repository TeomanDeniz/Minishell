/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operate_doc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:32:10 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 18:32:11 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdbool.h> /*
#typedef bool;
#*/
#include "../../main.h" /*
# struct s_operator;
#typedef t_shell;
#    int reset_here_doc_operator(char *, t_operator);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

bool
	check_operate_doc(t_shell shell)
{
	struct s_operator	operator;

	shell->number_of_parentheses = \
		reset_here_doc_operator(shell->input, &operator);
	return (operator.double_quote || operator.single_quote || operator.pipe || \
		!!shell->number_of_parentheses);
}
