/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:18:57 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/08 18:18:58 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
# define PIPE_READ
# define PIPE_WRITE
#typedef t_shell;
#    int there_is_slash_on_command(char *);
#    int file_checker(char *, int, t_shell);
#   void free_shell(t_shell);
#   void process_command(t_shell);
#   void error_shell(t_shell, char *, int, char *);
#    int check_next_pipe(t_shell);
#        */
#include <signal.h> /*
# define SIGINT
# define SIG_DFL
# define SIGQUIT
#sigh... signal(int, sighandler_t); ((sighandler_t))
#        */
#include <unistd.h> /*
# define F_OK
# define X_OK
# define STDIN_FILENO
# define STDOUT_FILENO
#    int execve(char *, char *[], char *[]);
#    int access(char *, int);
#    int dup2(int, int);
#    int close(int);
#        */
#include <stdlib.h> /*
#   void exit(int);
#        */
#include "../../libft/libft.h" /*
#    int ft_free_matrix(char ***);
#        */
#include <sys/stat.h> /*
# define S_ISDIR(st_mode)
# struct stat;
#    int lstat(char *, struct stat *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ void	c_access(t_shell shell, char *file);
extern __inline__ void	prepare_pipes(t_shell shell, int current_p[2], \
int arg_p[2], char **arg);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	child_process(t_shell shell, int current_p[2], int arg_p[2], char **arg)
{
	prepare_pipes(shell, current_p, arg_p, arg);
	if (there_is_slash_on_command(shell->execute_program))
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		if (file_checker(shell->execute_program, 1, shell))
			execve(shell->execute_program, arg, shell->env);
		c_access(shell, shell->execute_program);
		free_shell(shell);
		exit(shell->errorlevel);
	}
	process_command(shell);
}

extern __inline__ void
	c_access(t_shell shell, char *file)
{
	struct stat	file_stats;

	shell->errorlevel = 127;
	if (!file)
		return ;
	lstat(file, &file_stats);
	if (access(file, F_OK) != 0)
		return ;
	else if (access(file, F_OK) == 0 && \
		(access(file, X_OK) != 0 || S_ISDIR(file_stats.st_mode)))
		shell->errorlevel = 126;
}

extern __inline__ void
	prepare_pipes(t_shell shell, int current_p[2], int arg_p[2], char **arg)
{
	if (!!shell->arg[shell->index].this && arg_p[PIPE_READ] != -1)
	{
		if (dup2(arg_p[PIPE_READ], STDIN_FILENO) == -1)
		{
			close(arg_p[PIPE_READ]);
			close(arg_p[PIPE_WRITE]);
			ft_free_matrix(&arg);
			error_shell(shell, ((void *)0), (__LINE__ - 1), "dup2()");
		}
		close(arg_p[PIPE_READ]);
		close(arg_p[PIPE_WRITE]);
	}
	if (check_next_pipe(shell) && !shell->fucking_filedock_happend)
	{
		if (dup2(current_p[PIPE_WRITE], STDOUT_FILENO) == -1)
		{
			close(current_p[PIPE_WRITE]);
			close(current_p[PIPE_READ]);
			ft_free_matrix(&arg);
			error_shell(shell, ((void *)0), (__LINE__ - 1), "dup2()");
		}
		close(current_p[PIPE_WRITE]);
		close(current_p[PIPE_READ]);
	}
}
