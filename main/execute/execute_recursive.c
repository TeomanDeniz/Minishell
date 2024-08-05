/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_recursive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:48:19 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/07 13:48:20 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../../libft/libft.h" /*
#    int ft_strboolcmp(char *, char *);
#        */
#include "../main.h" /*
#typedef t_shell;
#    int check_if_semicolon(t_shell);
#   void error_shell(t_shell, char *, int, char *);
#    int check_pipe_doc(t_shell, int [2], int [2]);
#    int do_the_event(t_shell, int [2], int [2]);
#   void parent_process(int [2], int [2], int [2]);
#   void return_execve_status(t_shell);
#    int check_next_syntax(char *);
#   void reset_content_pipe(int [2]);
#        */
#include <unistd.h> /*
#    int pipe(int [2]);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ void	skip_till_pipe(t_shell shell);
extern __inline__ void	skip_this_execute(t_shell shell, int arg_pipe[2]);
extern __inline__ void	fix_std_out(t_shell shell);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	execute_recursive(t_shell shell, int arg_pipe[2])
{
	int	next_pipe[2];
	int	current_pipe[2];

	if (check_if_semicolon(shell))
		return ;
	if (shell->arg[shell->index].operator && \
		ft_strboolcmp(shell->arg[shell->index].this, "|"))
	{
		shell->index++;
		execute_recursive(shell, arg_pipe);
		return ;
	}
	if (pipe(current_pipe) == -1)
		error_shell(shell, ((void *)0), (__LINE__ - 1), "pipe()");
	if (!check_pipe_doc(shell, arg_pipe, current_pipe) && \
		(skip_this_execute(shell, arg_pipe), 1))
		return ;
	if (!shell->arg[shell->index].this || \
		!do_the_event(shell, current_pipe, arg_pipe))
		return ;
	parent_process(next_pipe, current_pipe, arg_pipe);
	skip_till_pipe(shell);
	fix_std_out(shell);
	execute_recursive(shell, next_pipe);
	return_execve_status(shell);
}

extern __inline__ void
	skip_till_pipe(t_shell shell)
{
	while (!!shell->arg[shell->index].this && \
		!(shell->arg[shell->index].operator && \
		check_next_syntax(shell->arg[shell->index].this)))
		shell->index++;
	if (shell->arg[shell->index].this && shell->arg[shell->index].operator && \
		ft_strboolcmp(shell->arg[shell->index].this, "|"))
		shell->index++;
}

extern __inline__ void
	skip_this_execute(t_shell shell, int arg_pipe[2])
{
	reset_content_pipe(arg_pipe);
	while (!!shell->arg[shell->index].this && \
		!(shell->arg[shell->index].operator && \
		check_next_syntax(shell->arg[shell->index].this)))
		shell->index++;
	execute_recursive(shell, arg_pipe);
}

extern __inline__ void
	fix_std_out(t_shell shell)
{
	close(STDOUT_FILENO);
	if (dup2(shell->std_out_fd, STDOUT_FILENO) == -1)
		error_shell(shell, ((void *)0), (__LINE__ - 1), "dup2()");
}
