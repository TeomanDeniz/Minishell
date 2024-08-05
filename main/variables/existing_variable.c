/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   existing_variable.c                                :+:      :+:    :+:   */
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
#        */
#include "../../libft/libft.h" /*
#   char *ft_strdup(char *);
#    int ft_strboolcmp(char *, char *);
#    int ft_safe_free(char **);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

int
	existing_variable(const char *name, const char *value, t_shell shell, \
register int check_value_null)
{
	t_variable	temp;

	temp = ((void *)0);
	temp = shell->variable;
	while (temp != ((void *)0))
	{
		if (ft_strboolcmp(temp->name, name))
		{
			ft_safe_free(&temp->value);
			temp->value = ft_strdup(value);
			if (!temp->value && (check_value_null && !!value))
				error_shell(shell, MALLOC_ERROR, (__LINE__ - 2), "ft_strdup()");
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}