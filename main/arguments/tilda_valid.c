/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilda_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:56:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 12:56:03 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#typedef t_shell;
#typedef t_operator;
#    int char_whitespace_o(char, t_operator);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

int
	tilda_valid(t_shell shell, t_operator op, register int index)
{
	if (shell->input != shell->org_input)
		if (shell->input[index - 1] != '=' && \
			!char_whitespace_o(shell->input[index - 1], op))
			return (0);
	if (!!shell->input[index + 1])
		if (!char_whitespace_o(shell->input[index + 1], op) && \
			shell->input[index + 1] != '/')
			return (0);
	return (1);
}
