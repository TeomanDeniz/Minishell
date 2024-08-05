/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:16:36 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/08 18:16:37 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
# define PIPE_READ;
# define PIPE_WRITE;
#*/
#include <unistd.h> /*
#    int close(int);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	parent_process(int next_pipe[2], int current_pipe[2], int arg_pipe[2])
{
	if (arg_pipe[PIPE_READ] != -1)
		close(arg_pipe[PIPE_READ]);
	if (arg_pipe[PIPE_WRITE] != -1)
		close(arg_pipe[PIPE_WRITE]);
	next_pipe[PIPE_READ] = current_pipe[PIPE_READ];
	next_pipe[PIPE_WRITE] = current_pipe[PIPE_WRITE];
}
