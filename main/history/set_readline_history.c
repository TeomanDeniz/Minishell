/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_readline_history.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:07:49 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/07 16:07:50 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
# define HOME_FAILED;
# define CMD42_HISFILE;
# define MALLOC_ERROR;
#typedef t_shell;
#   void error_shell(t_shell, char *, int, char *);
#   void werror_shell(t_shell, char *, int, char *);
#   void env_to_variable(t_shell, char **);
#   char *get_variable_direct_value(char *, t_shell);
#   char *get_variable(char *, t_shell);
#   void set_variable(char *, char *, t_shell);
#   void set_history(t_shell);
#*/
#include <unistd.h> /*
# define F_OK;
# define R_OK;
# define X_OK;
#    int access(char *, int);
#*/
#include <stdbool.h> /*
#typedef bool;
# define false;
# define true;
#*/
#include "../../libft/libft.h" /*
#   char *get_next_line(int);
#   void *ft_calloc(uint, uint);
#    int ft_strlen(char *);
#*/
#include <fcntl.h> /*
# define O_RDONLY;
#    int open(char *, int, ...);
#*/
#include <stdio.h> /*
#typedef FILE;
^------> <readline/readline.h>
#    int printf(char *, ...);
#*/
#include <readline/history.h> /*
@ <----- <stdio.h> REQUIRED
@ +----+ +------------+
@ |FLAG| | -lreadline |
@ +----+ +------------+
#   void add_history(char *);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
static char	*prepare_cmd42_histfile(char *home);
static bool	fix_home_variable(t_shell shell);
static void	ft_stradd(char *string, const char *add);
static void	prepare_history(t_shell shell, char *histfile);
/* *************************** [^] PROTOTYPES [^] *************************** */

bool
	set_readline_history(t_shell shell)
{
	shell->histfile = NULL;
	if (!get_variable_direct_value("HOME", shell) || \
		access(get_variable("HOME", shell), F_OK | X_OK | R_OK) != 0)
		if (!fix_home_variable(shell))
			return (false);
	shell->histfile = prepare_cmd42_histfile(get_variable("HOME", shell));
	if (!shell->histfile)
		error_shell(shell, MALLOC_ERROR, 2, "prepare_cmd42_histfile()");
	if (access(shell->histfile, F_OK) != 0)
		close(open(shell->histfile, O_RDWR | O_CREAT | O_TRUNC, 0600));
	prepare_history(shell, shell->histfile);
	return (true);
}

static void
	prepare_history(t_shell shell, char *histfile)
{
	char	*line;

	shell->histfile_fd = open(histfile, O_RDWR);
	if (!shell->histfile_fd || shell->histfile_fd < 0)
	{
		werror_shell(shell, "Failed to open history file", 0, histfile);
		return ;
	}
	line = get_next_line(shell->histfile_fd);
	while (!!line)
	{
		if (*line != '\n' && !!*line)
		{
			shell->history_number_of_commands_in_file++;
			line[ft_strlen(line) - 1] = 0;
			add_history(line);
		}
		ft_safe_free(&line);
		line = get_next_line(shell->histfile_fd);
	}
}

static char
	*prepare_cmd42_histfile(char *home)
{
	char	*result;

	result = (char *) ft_calloc(sizeof(char), \
		(ft_strlen(home) + ft_strlen(CMD42_HISFILE) + 2));
	if (!result)
		return (NULL);
	ft_stradd(result, home);
	ft_stradd(result, "/");
	ft_stradd(result, CMD42_HISFILE);
	return (result);
}

static bool
	fix_home_variable(t_shell shell)
{
	if (!shell->home || access(shell->home, F_OK | X_OK | R_OK) != 0)
	{
		werror_shell(shell, HOME_FAILED, 0, "shell->home");
		return (false);
	}
	set_variable("HOME", shell->home, shell);
	return (true);
}

static void
	ft_stradd(char *string, const char *add)
{
	register int	index;

	index = 0;
	if (!string || !add)
		return ;
	while (string[index])
		++index;
	while (*add && index < PATH_MAX)
	{
		string[index] = *add;
		++add;
		++index;
	}
	string[index] = 0;
}
