/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_execute_program.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:38:49 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/08 17:38:50 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
# define MALLOC_ERROR;
# define UNEXPECTED_PATH_ERROR;
#typedef t_shell;
#   bool check_command_found_in_path(t_shell);
#   void error_shell(t_shell, char *, int, char *);
#   void perror_shell(t_shell, char *, int, char *);
#   char *get_variable_direct_value(char *, t_shell);
#*/
#include "../../libft/libft.h" /*
#   char *ft_strdup(char *);
#   char *ft_strjoin(char *, char *);
#   bool ft_free_matrix(char ***);
#   bool ft_safe_free(char **);
#   char **ft_split(char *, char);
#   char *ft_strjoinfree(char *, char *);
#*/
#include <unistd.h> /*
# define X_OK;
#    int access(char *, int);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
static char	*prepare_command_from_path(t_shell shell);
/* *************************** [^] PROTOTYPES [^] *************************** */

char
	*prepare_execute_program(t_shell shell)
{
	char	*result;

	if (!check_command_found_in_path(shell))
	{
		result = ft_strdup(shell->arg[shell->index].this);
		if (!result)
			error_shell(shell, MALLOC_ERROR, (__LINE__ - 2), "ft_strdup()");
		return (result);
	}
	return (prepare_command_from_path(shell));
}

static char
	*prepare_command_from_path2(char *command, char **path_array, t_shell shell)
{
	char			*test_command;
	register int	index;

	index = -1;
	while (++index, !!path_array[index])
	{
		test_command = ft_strjoin(path_array[index], command);
		if (!test_command && ft_free_matrix(&path_array))
			error_shell(shell, MALLOC_ERROR, (__LINE__ - 2), "ft_strjoin()");
		if (access(test_command, X_OK) == 0)
		{
			ft_free_matrix(&path_array);
			return (test_command);
		}
		ft_safe_free(&test_command);
	}
	ft_safe_free(&test_command);
	ft_free_matrix(&path_array);
	perror_shell(shell, UNEXPECTED_PATH_ERROR, __LINE__, "PATH");
	return (NULL);
}

static char
	*prepare_command_from_path(t_shell shell)
{
	char			**path_array;
	char			*command;
	register int	index;

	command = shell->arg[shell->index].this;
	path_array = ft_split(get_variable_direct_value("PATH", shell), ':');
	if (!path_array)
		error_shell(shell, MALLOC_ERROR, (__LINE__ - 2), "ft_split()");
	index = -1;
	while (++index, path_array[index])
	{
		path_array[index] = ft_strjoinfree(path_array[index], "/");
		if (!path_array[index])
		{
			ft_free_matrix(&path_array);
			error_shell(shell, MALLOC_ERROR, (__LINE__ - 4), \
				"ft_strjoinfree()");
		}
	}
	return (prepare_command_from_path2(command, path_array, shell));
}
