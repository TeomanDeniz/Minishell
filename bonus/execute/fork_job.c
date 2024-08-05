/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_job.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:32:10 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/08 17:32:11 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
# define UNABLE_TO_OPEN_FORK;
# define FORK_UNEXPECTED_END_ERROR;
# define CHILD_PROCESS;
#typedef t_shell;
#   char **prepare_execute_arguments(t_shell, int);
#   char *prepare_execute_program(t_shell);
#   void variable_to_env(t_shell);
#   void perror_shell(t_shell, char *, int, char *);
#   void child_process(t_shell, int [2], int [2], char **);
#   void error_shell(t_shell, char *, int, char *);
#*/
#include <unistd.h> /*
#typedef pid_t;
#  pid_t fork(void);
#*/
#include "../../libft/libft.h" /*
#   bool ft_safe_free(char **);
#   bool ft_free_matrix(char ***);
#*/
#include <signal.h> /*
#sigh... signal(int, sighandler_t); ((sighandler_t))
#*/
#include <stdlib.h> /*
#   void exit(int);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	fork_job(t_shell shell, int current_pipe[2], int arg_pipe[2])
{
	pid_t	pid;
	char	**arguments;

	ft_safe_free(&shell->execute_program);
	arguments = prepare_execute_arguments(shell, shell->index);
	shell->execute_program = prepare_execute_program(shell);
	shell->fork_job = true;
	variable_to_env(shell);
	signal(SIGINT, ignore_sigint_for_child);
	pid = fork();
	if (pid < 0)
		perror_shell(shell, UNABLE_TO_OPEN_FORK, (__LINE__ - 2), "fork()");
	if (pid == CHILD_PROCESS)
	{
		shell->i_am_a_fork = true;
		if (!shell->execute_program)
			exit(1);
		child_process(shell, current_pipe, arg_pipe, arguments);
		error_shell(shell, FORK_UNEXPECTED_END_ERROR, (__LINE__ - 1), NULL);
	}
	shell->last_pid = pid;
	ft_free_matrix(&arguments);
}
