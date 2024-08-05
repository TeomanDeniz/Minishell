/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_to_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:57:12 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/07 17:57:13 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
# define MALLOC_ERROR;
#typedef t_shell;
#typedef t_variable;
#   void error_shell(t_shell, char *, int, char *);
#*/
#include "../../libft/libft.h" /*
#   bool ft_free_matrix(char ***);
#   void *ft_calloc(Uint, Uint);
#    int ft_strlen(char *);
#   bool ft_safe_free(char **);
#*/
#include <stdlib.h> /*
#   void *malloc(size_t);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
static int	calculate_size(t_shell shell);
static int	overwrite(char *string, char *add, int *char_index);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	variable_to_env(t_shell shell)
{
	int				char_index;
	register int	index;
	t_variable		variable;

	if (!!shell->env)
		ft_free_matrix(&shell->env);
	index = -1;
	variable = shell->variable;
	shell->env = (char **) malloc(sizeof(char *) * calculate_size(shell));
	if (!shell->env)
		error_shell(shell, MALLOC_ERROR, (__LINE__ - 2), "malloc()");
	while (++index, !!variable)
	{
		shell->env[index] = (char *) ft_calloc(sizeof(char), \
			ft_strlen(variable->name) + ft_strlen(variable->value) + 2);
		if (!shell->env[index])
			error_shell(shell, MALLOC_ERROR, (__LINE__ - 3), "ft_calloc()");
		char_index = 0;
		overwrite(shell->env[index], variable->name, &char_index);
		overwrite(shell->env[index], "=", &char_index);
		index -= overwrite(shell->env[index], variable->value, &char_index);
		variable = variable->next;
	}
	shell->env[index] = NULL;
}

static int
	calculate_size(t_shell shell)
{
	register int	result;
	t_variable		event_variable;

	result = 0;
	event_variable = shell->variable;
	while (!!event_variable)
	{
		event_variable = event_variable->next;
		++result;
	}
	return (result + 1);
}

static int
	overwrite(char *string, char *add, int *char_index)
{
	register int	index;

	index = 0;
	if ((!(*char_index) && !add) || !add)
	{
		ft_safe_free(&string);
		return (1);
	}
	while (!!add && !!add[index])
	{
		string[(*char_index)] = add[index];
		++index;
		++(*char_index);
	}
	string[(*char_index)] = 0;
	return (0);
}
