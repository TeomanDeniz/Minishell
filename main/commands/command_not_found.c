/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_not_found.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:05:45 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/08 17:05:46 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
# define INCORRECT_COMMAND
#typedef t_shell;
#   void error_shell(t_shell, char *, int, char *);
#    int there_is_slash_on_command(char *);
#    int file_checker(char *, int, t_shell);
#   void werror_shell(t_shell, char *, int, char *);
#        */
#include <unistd.h> /*
# define STDOUT_FILENO
#    int dup2(int, int);
#        */
#include "../../libft/libft.h" /*
#    int ft_strboolcmp(char *, char *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	command_not_found(t_shell shell)
{
	shell->errorlevel = (unsigned int)127;
	if (dup2(shell->std_out_fd, STDOUT_FILENO) == -1)
		error_shell(shell, ((void *)0), (__LINE__ - 1), "dup2()");
	if (there_is_slash_on_command(shell->arg[shell->index].this) && \
		!file_checker(shell->arg[shell->index].this, 1, shell))
		(void)0;
	else if (g_signal != SIGINT && !!shell->arg[shell->index].this)
		werror_shell(shell, INCORRECT_COMMAND, 0, \
			shell->arg[shell->index].this);
	shell->index++;
	while (!!shell->arg[shell->index].this && \
		!ft_strboolcmp(shell->arg[shell->index].this, ";"))
		shell->index++;
	shell->command_not_found = 1;
}
