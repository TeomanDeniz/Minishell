/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_filedoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:40:57 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 17:40:58 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../../main.h" /*
# define MALLOC_ERROR;
# define PIPE_READ;
#typedef t_shell;
#   void error_shell(t_shell, char *, int, char *);
#*/
#include "../../../libft/libft.h" /*
#   void *ft_calloc(Uint, Uint);
#   bool ft_safe_free(char **);
#*/
#include <unistd.h> /*
#    int pipe(int [2]);
#    int dup2(int, int);
#    int close(int);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	prepare_filedoc(char **this, int fd, char *file, t_shell shell)
{
	int		pipe_fd[2];
	char	*start_temp;

	start_temp = (char *) ft_calloc(sizeof(int), 3);
	if (!start_temp && ft_safe_free(&file))
		error_shell(shell, MALLOC_ERROR, (__LINE__ - 2), "ft_calloc()");
	(*this) = (ft_safe_free(this), start_temp);
	if (pipe(pipe_fd) == -1 && ft_safe_free(&file))
		error_shell(shell, NULL, (__LINE__ - 1), "pipe()");
	if (dup2(fd, pipe_fd[PIPE_READ]) == -1 && ft_safe_free(&file))
		error_shell(shell, NULL, (__LINE__ - 1), "dup2()");
	close(pipe_fd[PIPE_WRITE]);
	(*this)[3] = (unsigned)pipe_fd[PIPE_READ] >> 24;
	(*this)[2] = (unsigned)pipe_fd[PIPE_READ] << 8 >> 24;
	(*this)[1] = (unsigned)pipe_fd[PIPE_READ] << 16 >> 24;
	(*this)[0] = (unsigned)pipe_fd[PIPE_READ] << 24 >> 24;
}
