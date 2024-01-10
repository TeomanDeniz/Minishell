/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_file_document.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:38:12 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 13:38:14 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../../main.h" /*
#typedef t_shell;

#*/
#include "../../../libft/libft.h" /*
#   char *ft_strdup(char *);
#   bool ft_safe_free(char **);
#    int ft_strlen(char *);
#   char *get_variable(char *, t_shell);
#   void error_shell(t_shell, char *, int, char *);
#   void prepare_filedoc(char **, int, char *, t_shell);
#*/
#include <unistd.h> /*
# define F_OK;
# define R_OK;
#    int access(char *, int);
#ssize_t write(int, void *, size_t);
#    int close(int);
#*/
#include <stdio.h> /*
#   void perror(char *);
#*/
#include <fcntl.h> /*
# define O_RDONLY;
#    int open(char *, int, ...);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	arg_file_document(t_shell shell, int index)
{
	char	*file;
	int		fd;

	file = ft_strdup(shell->arg[index].this);
	if (access(file, F_OK) || access(file, R_OK))
	{
		write(shell->std_out_fd, get_variable("CMD42_NAME", shell), \
			ft_strlen(get_variable("CMD42_NAME", shell)));
		write(shell->std_out_fd, ": ", 2);
		perror(file);
		ft_safe_free(&file);
		shell->arg[index].operator = true;
		return ;
	}
	fd = open(file, O_RDONLY);
	if (!fd || fd < 0)
	{
		ft_safe_free(&file);
		error_shell(shell, NULL, (__LINE__ - 1), "open()");
	}
	prepare_filedoc(&shell->arg[index].this, fd, file, shell);
	close(fd);
	ft_safe_free(&file);
}
