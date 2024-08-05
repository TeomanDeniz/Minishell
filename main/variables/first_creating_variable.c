/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_creating_variable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:53:55 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 20:53:56 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
# define MALLOC_ERROR;
#typedef t_shell;
#   void error_shell(t_shell, char *, int, char *);
#        */
#include "../../libft/libft.h" /*
#   char *ft_strdup(char *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

int
	first_creating_variable(const char *name, const char *value, \
t_shell shell, register int check_if_value_null)
{
	if (!!shell->variable && !shell->variable->name)
	{
		shell->variable->name = ft_strdup(name);
		if (!shell->variable->name)
			error_shell(shell, MALLOC_ERROR, (__LINE__ - 2), "ft_strdup()");
		shell->variable->value = ft_strdup(value);
		if (!shell->variable->value && (check_if_value_null && !!value))
			error_shell(shell, MALLOC_ERROR, (__LINE__ - 2), "ft_strdup()");
		shell->variable->next = ((void *)0);
		return (1);
	}
	return (0);
}
