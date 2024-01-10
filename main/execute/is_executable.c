/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_executable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 22:20:49 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/08 22:20:50 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdbool.h> /*
# define true;
# define false;
#typedef bool;
#*/
#include "../main.h" /*
#typedef t_shell;
#   bool there_is_slash_on_command(char *);
#   bool file_checker(char *, bool, t_shell);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

bool
	is_executable(char *command, t_shell shell)
{
	if (there_is_slash_on_command(command))
		if (file_checker(command, false, shell))
			return (true);
	return (false);
}
