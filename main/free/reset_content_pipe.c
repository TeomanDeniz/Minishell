/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_content_pipe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:48:58 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/07 18:48:58 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <unistd.h> /*
#ssize_t write(int, void *, size_t);
#        */
#include "../main.h" /*
# define PIPE_READ
# define PIPE_WRITE
#        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	reset_content_pipe(int arg_pipe[2])
{
	char	null_pipe;

	if (arg_pipe[PIPE_READ] < 0)
		return ;
	null_pipe = 0;
	write(arg_pipe[PIPE_WRITE], &null_pipe, 1);
}
