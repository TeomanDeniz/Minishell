/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:18:38 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/08 15:18:39 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/****************************************************************************\
|*                                                                          *|
|* I'm skipping these first << operators because the command may work like  *|
|* "<< asd cat" or "< asd.txt << 123 >> file1.txt cat"                      *|
|*  ^^ ^^^ ###      ^ ^^^^^^^ ^^ ^^^ ^^ ^^^^^^^^^ ###                       *|
|*  SKIP>>>BINGO    SKIP>SKIP>SKIP>SKIP>SKIP>SKIP>BINGO                     *|
|*                                                                          *|
|* The purpose is reching the command and running it.                       *|
|*                                                                          *|
\****************************************************************************/

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdbool.h> /*
#typedef bool;
# define true;
# define false;
*/
#include "../main.h" /*
# define PIPE_READ;
# define PIPE_WRITE;
#typedef t_shell;
#   bool check_next_syntax(char *);
#   void reset_pipe(t_shell, int [2]);
#   void reset_content_pipe(int [2]);
#   bool check_if_semicolon(t_shell);
#   void execute_recursive(t_shell, int [2]);
#   bool check_next_pipe(t_shell);
#   bool is_executable(char *, t_shell);
#   bool check_command_found_in_path(t_shell);
#   void fork_job(t_shell, int [2], int [2]);
#   void normal_job(t_shell, int [2]);
#*/
#include "../../libft/libft.h" /*
#   bool ft_strboolcmp(char *, char *);
#    int ft_strlen(char *);
#*/
#include <unistd.h> /*
#    int close(int);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
static bool	close_pipe(int pipe[2]);
/* *************************** [^] PROTOTYPES [^] *************************** */

bool
	do_the_event(t_shell shell, int current_pipe[2], int arg_pipe[2])
{
	while (shell->arg[shell->index].operator && (\
		ft_strboolcmp(shell->arg[shell->index].this, "<") || \
		ft_strboolcmp(shell->arg[shell->index].this, "<<") || \
		ft_strboolcmp(shell->arg[shell->index].this, ">") || \
		ft_strboolcmp(shell->arg[shell->index].this, ">>")))
		shell->index += 2;
	if (check_if_semicolon(shell) && close_pipe(current_pipe))
		return (false);
	if (check_next_syntax(shell->arg[shell->index].this))
	{
		close_pipe(current_pipe);
		reset_pipe(shell, arg_pipe);
		reset_content_pipe(arg_pipe);
		execute_recursive(shell, arg_pipe);
		return (false);
	}
	if (check_next_pipe(shell) || shell->fork_job || \
		is_executable(shell->arg[shell->index].this, shell) || \
		check_command_found_in_path(shell))
		fork_job(shell, current_pipe, arg_pipe);
	else
		normal_job(shell, arg_pipe);
	return (true);
}

static bool
	close_pipe(int pipe[2])
{
	if (pipe[PIPE_READ] != -1)
		close(pipe[PIPE_READ]);
	if (pipe[PIPE_WRITE] != -1)
		close(pipe[PIPE_WRITE]);
	return (true);
}
