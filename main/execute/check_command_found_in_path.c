/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command_found_in_path.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:34:56 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/08 15:34:58 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
# define MALLOC_ERROR
#typedef t_shell;
#    int command_if_builtin(char *);
#   char *get_variable_direct_value(char *, t_shell);
#   void error_shell(t_shell, char *, int, char *);
#        */
#include "../../libft/libft.h" /*
#   char **ft_split(char *, char);
#   char *ft_strjoinfree(char *, char *);
#    int ft_free_matrix(char ***);
#   char *ft_strjoin(char *, char *);
#        */
#include <unistd.h> /*
# define X_OK
#    int access(char *, int);
#        */
#include <sys/stat.h> /*
# define S_ISDIR(st_mode)
# struct stat;
#    int lstat(char *, struct stat *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ int	search_paths(char *command, char **path_array, \
t_shell shell);
extern __inline__ int	is_dir(char *command);
extern __inline__ int	check_variable_equal_syntax_valid(char *arg);
/* *************************** [^] PROTOTYPES [^] *************************** */

int
	check_command_found_in_path(t_shell shell)
{
	char			**path_array;
	char			*command;
	register int	index;

	command = shell->arg[shell->index].this;
	if (!command || !*command || command_if_builtin(command) || \
		!get_variable_direct_value("PATH", shell) || \
		check_variable_equal_syntax_valid(command))
		return (0);
	path_array = ft_split(get_variable_direct_value("PATH", shell), ':');
	if (!path_array && !*path_array)
		error_shell(shell, MALLOC_ERROR, (__LINE__ - 2), "ft_split()");
	index = -1;
	while (++index, !!path_array[index])
	{
		path_array[index] = ft_strjoinfree(path_array[index], "/");
		if (!path_array[index] && ft_free_matrix(&path_array))
			error_shell(shell, MALLOC_ERROR, (__LINE__ - 2), \
				"ft_strjoinfree()");
	}
	return (search_paths(command, path_array, shell));
}

extern __inline__ int
	search_paths(char *command, char **path_array, t_shell shell)
{
	char			*test_command;
	register int	index;

	index = -1;
	while (++index, !!path_array[index])
	{
		test_command = ft_strjoin(path_array[index], command);
		if (!test_command && ft_free_matrix(&path_array))
			error_shell(shell, MALLOC_ERROR, (__LINE__ - 2), "ft_strjoin()");
		if (access(test_command, X_OK) == 0 && !is_dir(test_command))
		{
			ft_safe_free(&test_command);
			ft_free_matrix(&path_array);
			return (1);
		}
		ft_safe_free(&test_command);
	}
	ft_safe_free(&test_command);
	ft_free_matrix(&path_array);
	return (0);
}

extern __inline__ int
	is_dir(char *command)
{
	struct stat	file_stats;

	lstat(command, &file_stats);
	if (S_ISDIR(file_stats.st_mode))
		return (1);
	return (0);
}

extern __inline__ int
	check_variable_equal_syntax_valid(char *arg)
{
	if (*arg != '_' && !(*arg >= 'a' && *arg <= 'z') && \
		!(*arg >= 'A' && *arg <= 'Z'))
		return (0);
	while (++arg, !!*arg && *arg != '=')
	{
		if (*arg != '=' && *arg != '_' && !(*arg >= 'a' && *arg <= 'z') && \
			!(*arg >= 'A' && *arg <= 'Z') && !(*arg >= '0' && *arg <= '9'))
			return (0);
	}
	if (*arg == '=')
		return (1);
	return (0);
}
