/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_and_free_variable.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:53:55 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 20:53:56 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
# define MALLOC_ERROR;
#typedef t_shell;
#   void variable_setup(t_shell);
#   void error_shell(t_shell, char *, int, char *);
#   void sort_variables(t_shell);
#*/
#include <stdbool.h> /*
#typedef bool;
# define true;
# define false;
*/
#include <stdlib.h> /*
#   void *malloc(size_t);
#*/
#include "../../libft/libft.h" /*
#   char *ft_strdup(char *);
#   bool ft_strboolcmp(char *, char *);
#   bool ft_safe_free(char **);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
static bool	first_creating_variable(const char *name, const char *value, \
t_shell shell);
static bool	existing_variable(const char *name, const char *value, \
t_shell shell);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	set_and_free_variable(char *name, char *value, t_shell shell)
{
	t_variable	event_variable;

	if (!shell->variable)
		variable_setup(shell);
	event_variable = shell->variable;
	if (first_creating_variable(name, value, shell) || \
		existing_variable(name, value, shell))
		return ;
	while (!!event_variable && !!event_variable->next)
		event_variable = event_variable->next;
	event_variable->next = (t_variable) malloc(sizeof(struct s_variable));
	if (!event_variable->next)
		error_shell(shell, MALLOC_ERROR, (__LINE__ - 2), "malloc()");
	event_variable->next->name = ft_strdup(name);
	if (!event_variable->next->name && ft_safe_free(&name))
		error_shell(shell, MALLOC_ERROR, (__LINE__ - 2), "ft_strdup()");
	event_variable->next->value = ft_strdup(value);
	if (!event_variable->next->value && !!value && ft_safe_free(&value))
		error_shell(shell, MALLOC_ERROR, (__LINE__ - 2), "ft_strdup()");
	event_variable->next->next = NULL;
	if (!shell->variable || !shell->variable->next)
		return ;
	sort_variables(shell);
}

static bool
	first_creating_variable(const char *name, const char *value, t_shell shell)
{
	if (!!shell->variable && !shell->variable->name)
	{
		shell->variable->name = ft_strdup(name);
		if (!shell->variable->name)
			error_shell(shell, MALLOC_ERROR, (__LINE__ - 2), "ft_strdup()");
		shell->variable->value = ft_strdup(value);
		if (!shell->variable->value)
			error_shell(shell, MALLOC_ERROR, (__LINE__ - 2), "ft_strdup()");
		shell->variable->next = NULL;
		return (true);
	}
	return (false);
}

static bool
	existing_variable(const char *name, const char *value, t_shell shell)
{
	t_variable	temp;

	temp = NULL;
	temp = shell->variable;
	while (temp != NULL)
	{
		if (ft_strboolcmp(temp->name, name))
		{
			ft_safe_free(&temp->value);
			temp->value = ft_strdup(value);
			if (!temp->value && !!value)
				error_shell(shell, MALLOC_ERROR, (__LINE__ - 2), "ft_strdup()");
			return (true);
		}
		temp = temp->next;
	}
	return (false);
}
