/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_variable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:33:10 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/07 17:33:11 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
# define MALLOC_ERROR
#typedef t_shell;
#   void variable_setup(t_shell);
#   void error_shell(t_shell, char *, int, char *);
#   void sort_variables(t_shell);
#    int first_creating_variable(char *, char *, t_shell, int);
#    int existing_variable(char *, char *, t_shell, int);
#        */
#include <stdlib.h> /*
#   void *malloc(size_t);
#        */
#include "../../libft/libft.h" /*
#   char *ft_strdup(char *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	set_variable(const char *name, const char *value, t_shell shell)
{
	t_variable	event_variable;

	if (!shell->variable)
		variable_setup(shell);
	event_variable = shell->variable;
	if (first_creating_variable(name, value, shell, 1) || \
		existing_variable(name, value, shell, 0))
		return ;
	while (!!event_variable && !!event_variable->next)
		event_variable = event_variable->next;
	event_variable->next = (t_variable) malloc(sizeof(struct s_variable));
	if (!event_variable->next)
		error_shell(shell, MALLOC_ERROR, (__LINE__ - 2), "malloc()");
	event_variable->next->name = ft_strdup(name);
	if (!event_variable->next->name)
		error_shell(shell, MALLOC_ERROR, (__LINE__ - 2), "ft_strdup()");
	event_variable->next->value = ft_strdup(value);
	if (!event_variable->next->value && !!value)
		error_shell(shell, MALLOC_ERROR, (__LINE__ - 2), "ft_strdup()");
	event_variable->next->next = (void *)0;
	if (!shell->variable || !shell->variable->next)
		return ;
	sort_variables(shell);
}
