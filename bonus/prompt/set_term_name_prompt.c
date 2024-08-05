/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_term_name_prompt.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:47:53 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 16:47:54 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#typedef t_shell;
#   char *get_variable_direct_value(char *, t_shell);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	set_term_name_prompt(t_shell shell, int *prompt_index, char **ps)
{
	register int	index;
	char			*cmd42_name;

	index = 0;
	shell->prompt[*prompt_index] = '-';
	*prompt_index += 1;
	cmd42_name = get_variable("CMD42_NAME", shell);
	while (!!cmd42_name && !!cmd42_name[index])
	{
		shell->prompt[*prompt_index] = cmd42_name[index];
		*prompt_index += 1;
		++index;
	}
	*ps += 2;
}
