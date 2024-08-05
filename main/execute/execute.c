/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:48:09 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/07 13:48:12 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#typedef t_shell;
#   void execute_recursive(t_shell, int [2]);
#   void error_shell(t_shell, char *, int, char *);
#        */
#include <unistd.h> /*
# define STDOUT_FILENO
#    int close(int);
#    int dup2(int, int);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	execute(t_shell shell)
{
	int	arg_pipe[2];

	arg_pipe[PIPE_READ] = -1;
	arg_pipe[PIPE_WRITE] = -1;
	shell->last_pid = 0;
	shell->status_actknowledge = 0;
	shell->fork_job = 0;
	shell->fucking_filedock_happend = 0;
	execute_recursive(shell, arg_pipe);
	if (arg_pipe[PIPE_READ] != -1)
		close(arg_pipe[PIPE_READ]);
	if (arg_pipe[PIPE_WRITE] != -1)
		close(arg_pipe[PIPE_WRITE]);
	if (dup2(shell->std_out_fd, STDOUT_FILENO) == -1)
		error_shell(shell, ((void *)0), (__LINE__ - 1), "dup2()");
}
