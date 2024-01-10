/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:07:49 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/07 16:07:50 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
# define CMD42_PS1;
# define CMD42_PS2;
# define CMD42_PS3;
# define CMD42_PS4;
# define CMD42_NAME;
# define CMD42_VERSION;
# define CMD42_PATH;
# define PATH_MAX;
# define FAILED_HOME;
# define FAILED_TO_BACK;
# struct s_operator;
#  union u_converter;
#typedef t_shell;
#typedef t_variable;
#   void error_shell(t_shell, char *, int, char *);
#   void update_row_and_col_variables(int);
#   void variable_setup(t_shell);
#   void env_to_variable(t_shell, char **);
#   char *get_variable_direct_value(char *, t_shell);
#   void set_var_by_int(char *, int, t_shell);
#   char *get_variable(char *, t_shell);
#   void set_variable(char *, char *, t_shell);
#   void handle_sigint(int);
#*/
#include <unistd.h> /*
# define STDOUT_FILENO;
#   char *getcwd(char *, size_t);
#    int dup(int);
#    int chdir(char *);
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
#typedef rl_getc_function();
#*/
#include <stdbool.h> /*
# define false;
*/
#include "../../libft/libft.h" /*
#    int ft_atoi(char *);
#   bool ft_strboolcmp(char *, char *);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
static void	check_and_set(const char *name, const char *value, t_shell shell);
static void	prepare_home(t_shell shell);
static void	shell_setup_env(t_shell shell, char **env);
static void	send_t_shell_address(t_shell shell);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	shell_setup(t_shell shell, char **env)
{
	send_t_shell_address(shell);
	getcwd(shell->pwd, PATH_MAX);
	shell->original_rl_getc_function = rl_getc_function;
	shell->env = NULL;
	shell->index = 0;
	shell->variable = NULL;
	shell->prompt = NULL;
	shell->input = NULL;
	shell->arg = NULL;
	shell->execute_program = NULL;
	shell->errorlevel = 0U;
	shell->last_pid = 0;
	shell->history_number_of_commands = 0;
	shell->std_out_fd = dup(STDOUT_FILENO);
	if (shell->std_out_fd < 0)
		error_shell(shell, NULL, (__LINE__ - 2), "dup()");
	shell->i_am_a_fork = false;
	shell->fork_job = false;
	shell->command_not_found = false;
	shell->fix_extra_fucking_newline = false;
	shell->operator = (struct s_operator){false, false};
	shell_setup_env(shell, env);
	update_row_and_col_variables(0);
}

static void
	shell_setup_env(t_shell shell, char **env)
{
	variable_setup(shell);
	env_to_variable(shell, env);
	if (!!get_variable_direct_value("SHLVL", shell))
		set_var_by_int("SHLVL", 1 + ft_atoi(get_variable("SHLVL", shell)), \
			shell);
	check_and_set("PS1", CMD42_PS1, shell);
	set_variable("PS2", CMD42_PS2, shell);
	set_variable("PS3", CMD42_PS3, shell);
	set_variable("PS4", CMD42_PS4, shell);
	set_variable("CMD42_NAME", CMD42_NAME, shell);
	set_variable("CMD42_VERSION", CMD42_VERSION, shell);
	check_and_set("SHLVL", "1", shell);
	prepare_home(shell);
	if (ft_strboolcmp(get_variable("PATH", shell), ""))
		check_and_set("PATH", CMD42_PATH, shell);
	check_and_set("PWD", shell->pwd, shell);
}

static void
	check_and_set(const char *name, const char *value, t_shell shell)
{
	t_variable	event_variable;

	event_variable = shell->variable;
	while (!!event_variable)
	{
		if (ft_strboolcmp(name, event_variable->name))
			return ;
		event_variable = event_variable->next;
	}
	set_variable(name, value, shell);
}

static void
	prepare_home(t_shell shell)
{
	char	result_home[PATH_MAX];
	char	old_dir[PATH_MAX];

	if (!get_variable_direct_value("HOME", shell))
	{
		getcwd(old_dir, PATH_MAX);
		if (chdir("/") == -1)
			error_shell(shell, FAILED_HOME, (__LINE__ - 1), "chdir()");
		getcwd(result_home, PATH_MAX);
		set_variable("HOME", result_home, shell);
		if (chdir(old_dir) == -1)
			error_shell(shell, FAILED_TO_BACK, (__LINE__ - 1), "chdir()");
	}
}

static void
	send_t_shell_address(t_shell shell)
{
	union u_converter	converter;

	converter.p_var = shell;
	handle_sigint((int)(converter.ul_var >> 32));
	handle_sigint((int)(converter.ul_var << 32 >> 32));
	update_row_and_col_variables((int)(converter.ul_var >> 32));
	update_row_and_col_variables((int)(converter.ul_var << 32 >> 32));
}