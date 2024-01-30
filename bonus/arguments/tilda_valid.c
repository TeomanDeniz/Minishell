/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilda_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:56:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 12:56:03 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdbool.h> /*
# define true;
# define false;
#typedef bool;
#typedef t_operator;
#*/
#include "../main.h" /*
#typedef t_shell;
#   bool char_whitespace_o(char, t_operator);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

bool
	tilda_valid(t_shell shell, t_operator op, int index)
{
	if (shell->input != shell->org_input)
		if (shell->input[index - 1] != '=' && \
			!char_whitespace_o(shell->input[index - 1], op))
			return (false);
	if (!!shell->input[index + 1])
		if (!char_whitespace_o(shell->input[index + 1], op) && \
			shell->input[index + 1] != '/')
			return (false);
	return (true);
}
