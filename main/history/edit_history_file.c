/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_history_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 22:37:08 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/21 22:37:11 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
# define HISTFILE_LIMIT
#typedef t_shell;
#        */
#include "../../libft/libft.h" /*
#    int ft_strlen(char *);
#    int ft_safe_free(char **);
#    int ft_free_matrix(char ***);
#   char *get_next_line(int);
#        */
#include <unistd.h> /*
#ssize_t write(int, void *, size_t);
#    int close(int);
#        */
#include <fcntl.h> /*
# define O_RDWR;
# define O_CREAT;
# define O_TRUNC;
#    int open(char *, int, ...);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ int	save_history(t_shell shell, char **history_lines, \
register int fd);
extern __inline__ void	load_history(t_shell shell, char **history_lines);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	edit_history_file(t_shell shell)
{
	register int	fd;
	char			*history_lines[HISTFILE_LIMIT];

	if (shell->history_number_of_commands_in_file < HISTFILE_LIMIT)
		return ;
	fd = open(shell->histfile, O_RDWR);
	if (!fd || fd < 0)
		return ;
	save_history(shell, history_lines, fd);
	close(fd);
	load_history(shell, history_lines);
	ft_free_matrix((char ***)&history_lines);
}

extern __inline__ int
	save_history(t_shell shell, char **history_lines, register int fd)
{
	char			*line;
	register int	index;

	while (shell->history_number_of_commands_in_file > (HISTFILE_LIMIT / 2))
	{
		shell->history_number_of_commands_in_file--;
		line = get_next_line(fd);
		ft_safe_free(&line);
	}
	index = -1;
	line = get_next_line(fd);
	while (++index, !!line)
	{
		history_lines[index] = line;
		line = get_next_line(fd);
	}
	history_lines[index] = ((void *)0);
	return (1);
}

extern __inline__ void
	load_history(t_shell shell, char **history_lines)
{
	register int	index;

	close(shell->histfile_fd);
	shell->histfile_fd = open(shell->histfile, \
		O_RDWR | O_CREAT | O_TRUNC, 0600);
	if (!shell->histfile_fd || shell->histfile_fd < 0)
		return ;
	index = -1;
	while (++index, !!history_lines[index])
	{
		write(shell->histfile_fd, history_lines[index], \
			ft_strlen(history_lines[index]));
	}
}
