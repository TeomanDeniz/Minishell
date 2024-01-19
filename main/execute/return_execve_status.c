/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_execve_status.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:30:55 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/07 15:30:56 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#typedef t_shell;
#   void error_shell(t_shell, char *, int, char *);
#   void suppress_cat_io(bool);
#   void signals_setup(void);
#   char *get_variable(char *, t_shell);
#*/
#include <stdbool.h> /*
# define true;
# define false;
#*/
#include <unistd.h> /*
#    int close(int);
#    int dup2(int, int);
#ssize_t write(int, void *, size_t);
#*/
#include <sys/wait.h> /*
#  pid_t waitpid(pid_t, int *, int);
# define WIFEXITED(stat_val);
# define WEXITSTATUS(stat_val);
#*/
#include "../../libft/libft.h" /*
#    int ft_strlen(char *);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
static void	handle_return_status(t_shell shell, int wait_status);
static void	warn_segmentation_error(t_shell shell);
static void	warn_interrupt_error(t_shell shell);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	return_execve_status(t_shell shell)
{
	register int	wait_status;

	if (shell->fork_job == false)
	{
		close(STDOUT_FILENO);
		if (dup2(shell->std_out_fd, STDOUT_FILENO) == -1)
			error_shell(shell, NULL, (__LINE__ - 1), "dup2()");
		return ;
	}
	if (shell->last_pid == 0 && wait(NULL))
		return ;
	suppress_cat_io(true);
	wait_status = 0;
	handle_return_status(shell, wait_status);
	signals_setup();
	close(STDOUT_FILENO);
	shell->last_pid = 0;
	if (dup2(shell->std_out_fd, STDOUT_FILENO) == -1)
		error_shell(shell, NULL, (__LINE__ - 1), "dup2");
}

static void
	handle_return_status(t_shell shell, int wait_status)
{
	register int	status;

	status = (waitpid(shell->last_pid, &wait_status, 0), 0);
	if (!shell->status_actknowledge && WIFEXITED(wait_status))
	{
		status = WEXITSTATUS(wait_status);
		if (wait_status >= 1 && wait_status <= 27)
			shell->errorlevel = 0X80 + status;
		else
			shell->errorlevel = status;
		shell->status_actknowledge = true;
	}
	else
		shell->errorlevel = 0X80 + wait_status;
	if (wait_status == 11)
		warn_segmentation_error(shell);
	if (wait_status == 2)
		warn_interrupt_error(shell);
}

static void
	warn_segmentation_error(t_shell shell)
{
	char	*cmd42_name;

	cmd42_name = get_variable("CMD42_NAME", shell);
	write(shell->std_out_fd, "-", 1);
	write(shell->std_out_fd, cmd42_name, ft_strlen(cmd42_name));
	write(shell->std_out_fd, ": segmentation fault `", 22);
	write(shell->std_out_fd, shell->execute_program, \
		ft_strlen(shell->execute_program));
	write(shell->std_out_fd, "' [11]", 6);
}

static void
	warn_interrupt_error(t_shell shell)
{
	char	*cmd42_name;

	cmd42_name = get_variable("CMD42_NAME", shell);
	write(shell->std_out_fd, "\n-", 2);
	write(shell->std_out_fd, cmd42_name, ft_strlen(cmd42_name));
	write(shell->std_out_fd, ": process interrupted `", 23);
	write(shell->std_out_fd, shell->execute_program, \
		ft_strlen(shell->execute_program));
	write(shell->std_out_fd, "' [2]", 5);
}
