/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_not_found.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:05:45 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/08 17:05:46 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
# define INCORRECT_COMMAND;
#typedef t_shell;
#   void error_shell(t_shell, char *, int, char *);
#   bool there_is_slash_on_command(char *);
#   bool file_checker(char *, bool, t_shell);
#   void werror_shell(t_shell, char *, int, char *);
#*/
#include <unistd.h> /*
# define STDOUT_FILENO;
#    int dup2(int, int);
#*/
#include "../../libft/libft.h" /*
#   bool ft_strboolcmp(char *, char *);
#*/
#include <stdbool.h> /*
# define true;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	command_not_found(t_shell shell)
{
	if (shell->index < 0)
		shell->index = 0;
	shell->errorlevel = 127U;
	if (dup2(shell->std_out_fd, STDOUT_FILENO) == -1)
		error_shell(shell, NULL, (__LINE__ - 1), "dup2()");
	if (there_is_slash_on_command(shell->arg[shell->index].this) && \
		!file_checker(shell->arg[shell->index].this, true, shell))
		(void)0;
	else if (g_signal != SIGINT && !!shell->arg[shell->index].this)
		werror_shell(shell, INCORRECT_COMMAND, 0, \
			shell->arg[shell->index].this);
	shell->index++;
	while (!!shell->arg[shell->index].this && \
		!ft_strboolcmp(shell->arg[shell->index].this, ";"))
		shell->index++;
	shell->command_not_found = true;
}
