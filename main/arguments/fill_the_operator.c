/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_the_operator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:41:29 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/08 23:41:30 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
# struct s_operator;
#typedef t_shell;
#   void skip_whitespaces(char **, t_operator);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	fill_the_operator(t_shell shell, register int index)
{
	register char		clone;
	register int		string_index;
	struct s_operator	skip_operators;

	string_index = 0;
	shell->arg[index].operator = 1;
	skip_operators.double_quote = 0;
	skip_operators.single_quote = 0;
	clone = *shell->input;
	while (!!*shell->input && *shell->input == clone)
	{
		shell->arg[index].this[string_index] = *shell->input;
		shell->input += 1;
		++string_index;
	}
	shell->arg[index].this[string_index] = 0;
	skip_whitespaces(&shell->input, &skip_operators);
}
