/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:54:30 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/07 17:54:31 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#typedef t_shell;
#typedef t_variable;
#*/
#include "../../libft/libft.h" /*
#   bool ft_strboolcmp(char *, char *);
#   bool ft_safe_free(char **);
#*/
#include <stdlib.h> /*
#   void free(void *);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	remove_variable(const char *name, t_shell shell)
{
	t_variable	prior;
	t_variable	event_variable;

	event_variable = shell->variable;
	prior = NULL;
	while (!!event_variable)
	{
		if (ft_strboolcmp(event_variable->name, name))
		{
			ft_safe_free(&event_variable->name);
			ft_safe_free(&event_variable->value);
			if (!!prior)
				prior->next = event_variable->next;
			else
				shell->variable = event_variable->next;
			free(event_variable);
			return ;
		}
		prior = event_variable;
		if (!!event_variable->next)
			event_variable = event_variable->next;
		else
			break ;
	}
}
