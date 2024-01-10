/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_job.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:17:55 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/08 17:17:56 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
# define PIPE_READ;
# define PIPE_WRITE;
#typedef t_shell;
#   void process_command(t_shell);
#*/
#include <unistd.h> /*
#    int close(int);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	normal_job(t_shell shell, int arg_pipe[2])
{
	if (arg_pipe[PIPE_READ] != -1)
		close(arg_pipe[PIPE_READ]);
	if (arg_pipe[PIPE_WRITE] != -1)
		close(arg_pipe[PIPE_WRITE]);
	process_command(shell);
}
