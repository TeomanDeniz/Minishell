/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe_doc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:34:52 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/07 18:34:53 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdbool.h> /*
#typedef bool;
# define true;
# define false;
#*/
#include "../main.h" /*
# define PIPE_READ;
# define PIPE_WRITE;
# struct s_arg;
#typedef t_shell;
#   bool check_next_syntax(char *);
#   void reset_pipe(t_shell, int [2]);
#   void error_shell(t_shell, char *, int, char *);
#   void reset_content_pipe(int [2]);
#*/
#include "../../libft/libft.h" /*
#   bool ft_strboolcmp(char *, char *);
#    int ft_strlen(char *);
#*/
#include <unistd.h> /*
# define STDOUT_FILENO;
#    int dup2(int, int);
#ssize_t write(int, void *, size_t);
#    int close(int);
#*/
#include <fcntl.h> /*
# define O_RDWR;
# define O_CREAT;
# define O_TRUNC;
# define O_APPEND;
#    int open(char *, int, ...);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
static void	prepare_heredoc(t_shell shell, int arg_pipe[2], int index);
static bool	pipe_file_doc(t_shell shell, struct s_arg arg, int arg_pipe[2], \
int index);
static bool	prepare_output(t_shell shell, struct s_arg arg, int c_pipe[2], \
int index);
static bool	prepare_append(t_shell shell, struct s_arg arg, int c_pipe[2], \
int index);
/* *************************** [^] PROTOTYPES [^] *************************** */

bool
	check_pipe_doc(t_shell shell, int arg_pipe[2], int current_pipe[2])
{
	register int	index;
	struct s_arg	arg;

	index = shell->index;
	arg = shell->arg[index];
	while (!!arg.this && !(arg.operator && check_next_syntax(arg.this)))
	{
		arg = shell->arg[index];
		if (arg.operator && ft_strboolcmp(arg.this, "<"))
			if (pipe_file_doc(shell, arg, arg_pipe, index))
				return (false);
		if (arg.operator && ft_strboolcmp(arg.this, "<<"))
			prepare_heredoc(shell, arg_pipe, index);
		if (arg.operator && ft_strboolcmp(arg.this, ">"))
			if (prepare_output(shell, arg, current_pipe, index))
				return (false);
		if (arg.operator && ft_strboolcmp(arg.this, ">>"))
			if (prepare_append(shell, arg, current_pipe, index))
				return (false);
		++index;
	}
	return (true);
}

static bool
	pipe_file_doc(t_shell shell, struct s_arg arg, int arg_pipe[2], int index)
{
	register int	file_pid;

	arg = shell->arg[index + 1];
	if (arg.operator)
		return (true);
	file_pid = *((int *)arg.this);
	reset_pipe(shell, arg_pipe);
	if (dup2(file_pid, arg_pipe[PIPE_READ]) == -1)
		error_shell(shell, NULL, (__LINE__ - 1), "dup2()");
	return (false);
}

static void
	prepare_heredoc(t_shell shell, int arg_pipe[2], int index)
{
	++index;
	reset_pipe(shell, arg_pipe);
	write(arg_pipe[PIPE_WRITE], shell->arg[index].this, \
		ft_strlen(shell->arg[index].this));
}

static bool
	prepare_output(t_shell shell, struct s_arg arg, int c_pipe[2], int index)
{
	register int	temp_fd;

	reset_pipe(shell, c_pipe);
	shell->fucking_filedock_happend = true;
	++index;
	arg = shell->arg[index];
	if (!arg.this)
		return (false);
	temp_fd = open(arg.this, O_RDWR | O_CREAT | O_TRUNC, 0777);
	while (!!shell->arg[index].this && !(shell->arg[index].operator && \
		check_next_syntax(shell->arg[index].this)))
	{
		if (ft_strboolcmp(shell->arg[index].this, ">") || \
			ft_strboolcmp(shell->arg[index].this, ">>"))
		{
			close(temp_fd);
			return (false);
		}
		++index;
	}
	if (dup2(temp_fd, STDOUT_FILENO) == -1)
		error_shell(shell, NULL, (__LINE__ - 1), "dup2()");
	return (false);
}

static bool
	prepare_append(t_shell shell, struct s_arg arg, int c_pipe[2], int index)
{
	register int	temp_file_fd;

	reset_pipe(shell, c_pipe);
	shell->fucking_filedock_happend = true;
	++index;
	arg = shell->arg[index];
	temp_file_fd = open(arg.this, O_RDWR | O_CREAT | O_APPEND, 0777);
	dup2(temp_file_fd, STDOUT_FILENO);
	return (false);
}
