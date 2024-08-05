/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_executable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 22:20:49 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/08 22:20:50 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#typedef t_shell;
#    int there_is_slash_on_command(char *);
#    int file_checker(char *, int, t_shell);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

int
	is_executable(char *command, t_shell shell)
{
	if (there_is_slash_on_command(command))
		if (file_checker(command, 0, shell))
			return (1);
	return (0);
}
