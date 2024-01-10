/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sigint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:51:47 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/07 15:51:48 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#GLOBAL# sig_atomic_t g_signal;
#typedef t_shell;
#typedef t_converter;
#   char *get_variable(char *, t_shell);
#   bool move_cursor_up(void);
#*/
#include <signal.h> /*
# define SIGINT;
#*/
#include <stdio.h> /*
#typedef FILE;
^------> <readline/readline.h>
#*/
#include <readline/readline.h> /*
@ <----- <stdio.h> REQUIRED
@ +----+ +------------+
@ |FLAG| | -lreadline |
@ +----+ +------------+
#   void rl_replace_line(char *, int);
#   void rl_redisplay(void);
#*/
#include "../../libft/libft.h" /*
#    int ft_strlen(char *);
#*/
#include <unistd.h> /*
#ssize_t write(int, void *, size_t);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
static t_shell	save_shell_struct(char counter, int signal);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	handle_sigint(int signal)
{
	static t_shell	shell = NULL;
	static char		counter = 0;

	if (counter < 2)
	{
		shell = save_shell_struct(counter, signal);
		++counter;
		return ;
	}
	if (signal == SIGINT)
		shell->errorlevel = 1;
	if (signal == SIGINT)
		prompt_preparer(shell, get_variable("PS1", shell));
	if (shell->fix_extra_fucking_newline)
		move_cursor_up();
	if (shell->fork_job)
		return ;
	rl_replace_line("", 0);
	rl_redisplay();
	write(shell->std_out_fd, "\n", 1);
	write(shell->std_out_fd, shell->prompt, ft_strlen(shell->prompt));
	g_signal = signal;
}

static t_shell
	save_shell_struct(char counter, int signal)
{
	t_converter				converter;
	static unsigned long	struct_address = 0U;

	if (counter == 0)
	{
		struct_address = signal;
		struct_address = struct_address << 32;
		return (NULL);
	}
	else
	{
		struct_address = struct_address + (unsigned)signal;
		converter.ul_var = struct_address;
		return ((t_shell)converter.p_var);
	}
}
