/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_base_pwd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:55:35 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 16:55:36 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#typedef t_shell;
#   char *get_variable(char *, t_shell);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	set_base_pwd(t_shell shell, int *prompt_index, char **ps)
{
	register int	index;
	char			*pwd;

	index = 0;
	*ps += 2;
	pwd = get_variable("PWD", shell);
	if ((pwd[0] == '/' || pwd[0] == '\\' || pwd[0] == '~') && !pwd[1])
	{
		shell->prompt[*prompt_index] = pwd[0];
		++*prompt_index;
		return ;
	}
	while (!!pwd[index])
		++index;
	--index;
	while (pwd[index] != '/' && pwd[index] != '\\')
		--index;
	++index;
	while (!!pwd[index])
	{
		shell->prompt[*prompt_index] = pwd[index];
		++index;
		++*prompt_index;
	}
}
