/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:00:34 by hdeniz            #+#    #+#             */
/*   Updated: 2023/11/12 18:00:35 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../libft/libft.h" /*
#   bool ft_strcasecmp(char *, char *);
#   bool ft_safe_free(char **);
#*/
#include "main.h" /*
#GLOBAL# sig_atomic_t g_signal;
# struct s_shell;
#   void shell_setup(t_shell, char **);
#   void signals_setup(void);
#   void print_header(t_shell);
#   void prompt_preparer(t_shell, char *);
#   bool check_quate_here_doc(t_shell);
#   void quote_here_doc(t_shell);
#   void free_arg(t_shell);
#   void prepare_args(t_shell);
#   bool check_syntax_error(t_shell);
#   void prepare_arg_here_doc(t_shell);
#   void prepare_arg_file_doc(t_shell);
#   bool check_term_env_exist(void);
#   bool move_cursor_up(void);
#   bool check_next_pipe(t_shell);
#   void command_exit(t_shell);
#   void execute(t_shell);
#   void free_shell(t_shell);
#   void set_history(t_shell);
#*/
#include <stdio.h> /*
#typedef FILE;
^------> <readline/readline.h>
#    int printf(char *, ...);
#*/
#include <stdlib.h> /*
#   void exit(int);
#*/
#include <readline/readline.h> /*
@ <----- <stdio.h> REQUIRED
@ +----+ +------------+
@ |FLAG| | -lreadline |
@ +----+ +------------+
#   char *readline(char *);
#*/
#include <unistd.h> /*
#ssize_t write(int, void *, size_t);
#*/
#include <stdbool.h> /*
#typedef bool;
# define false;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

volatile sig_atomic_t	g_signal = 0;

/* *************************** [v] PROTOTYPES [v] *************************** */
static void	argument_while(t_shell shell);
static void	ctrl_d(t_shell shell);
static void	main_events(t_shell shell);
/* *************************** [^] PROTOTYPES [^] *************************** */

int
	main(int argc, char **argv, char **env)
{
	struct s_shell	shell;

	(void)argc;
	if (!!argv[1] && printf(TOO_MANY_ARGUMENTS_ERROR, CMD42_NAME, argv[1]))
		exit(1);
	shell_setup(&shell, env);
	signals_setup();
	print_header(&shell);
	while (1)
	{
		prompt_preparer(&shell, get_variable("PS1", &shell));
		shell.index = 0;
		shell.input = readline(shell.prompt);
		if (!!shell.input && shell.input[0] == 0)
			shell.fix_extra_fucking_newline = false;
		g_signal = 0;
		if (!shell.input)
			ctrl_d(&shell);
		shell.org_input = shell.input;
		if (!!shell.input[0])
			main_events(&shell);
		shell.input = shell.org_input;
		ft_safe_free(&shell.input);
	}
	return (0);
}

static void
	main_events(t_shell shell)
{
	shell->org_input = shell->input;
	if (check_quate_here_doc(shell))
		quote_here_doc(shell);
	set_history(shell);
	if (g_signal == SIGINT)
		return ;
	free_arg(shell);
	prepare_args(shell);
	if (check_syntax_error(shell))
		return ;
	prepare_arg_here_doc(shell);
	if (g_signal == SIGINT)
		return ;
	prepare_arg_file_doc(shell);
	if (!!shell->arg && !!shell->arg[0].this)
		argument_while(shell);
	if (shell->command_not_found)
	{
		if (check_term_env_exist())
			write(shell->std_out_fd, "\n", 1);
		move_cursor_up();
	}
	shell->command_not_found = false;
}

static void
	argument_while(t_shell shell)
{
	if (!check_next_pipe(shell) && \
		ft_strcasecmp(shell->arg[shell->index].this, "exit"))
		command_exit(shell);
	while (!!shell->arg[shell->index].this)
		execute(shell);
	shell->fork_job = false;
	if (shell->errorlevel >= 129 && shell->errorlevel <= 155)
		write(shell->std_out_fd, "\n", 1);
}

static void
	ctrl_d(t_shell shell)
{
	bool	env_is_exist;

	env_is_exist = move_cursor_up();
	if (env_is_exist)
		printf("%sexit\n", shell->prompt);
	else
		printf("exit\n");
	free_shell(shell);
	exit(shell->errorlevel);
}
