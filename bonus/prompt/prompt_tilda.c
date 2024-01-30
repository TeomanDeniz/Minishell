/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_tilda.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:54:20 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 16:54:21 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#typedef t_shell;
#   char *get_variable_direct_value(char *, t_shell);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

int
	prompt_tilda(char *var, t_shell shell, int *prompt_index)
{
	char			*home;
	register int	tilda_len;

	tilda_len = -1;
	home = get_variable("HOME", shell);
	if (!!home && *home == 0)
		return (0);
	while (++tilda_len, !!home[tilda_len] && !!var[tilda_len])
		if (!!home[tilda_len] && home[tilda_len] != var[tilda_len])
			return (0);
	if (!!home[tilda_len])
		return (0);
	shell->prompt[*prompt_index] = '~';
	(*prompt_index)++;
	return (tilda_len);
}
