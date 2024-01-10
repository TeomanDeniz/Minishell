/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:24:13 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/07 15:24:14 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#typedef t_shell;
#   void error_shell(t_shell, char *, int, char *);
#*/
#include <unistd.h> /*
#    int close(int);
#    int pipe(int [2]);
*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	reset_pipe(t_shell shell, int pipe_fd[2])
{
	if (pipe_fd[PIPE_WRITE] < 0 && pipe_fd[PIPE_WRITE] < 0)
	{
		if (pipe(pipe_fd) == -1)
			error_shell(shell, NULL, (__LINE__ - 1), "pipe()");
		return ;
	}
	if (pipe_fd[PIPE_READ] != -1)
		close(pipe_fd[PIPE_READ]);
	if (pipe_fd[PIPE_WRITE] != -1)
		close(pipe_fd[PIPE_WRITE]);
	if (pipe(pipe_fd) == -1)
		error_shell(shell, NULL, (__LINE__ - 1), "pipe()");
}
