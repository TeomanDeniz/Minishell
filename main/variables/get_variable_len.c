/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_variable_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:52:47 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/07 17:52:48 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#typedef t_shell;
#typedef t_variable;
#        */
#include "../../libft/libft.h" /*
#    int ft_strboolcmp(char *, char *);
#    int ft_strlen(char *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

int
	get_variable_len(const char *name, t_shell shell)
{
	t_variable	event_variable;

	event_variable = shell->variable;
	while (!!event_variable)
	{
		if (ft_strboolcmp(name, event_variable->name))
		{
			if (!event_variable->value)
				return (0);
			return (ft_strlen(event_variable->value));
		}
		if (!!event_variable->next)
			event_variable = event_variable->next;
		else
			return (0);
	}
	return (0);
}
