/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_variable_direct_value.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:42:00 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/07 17:42:01 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#typedef t_shell;
#typedef t_variable;
#*/
#include "../../libft/libft.h" /*
#   bool ft_strboolcmp(char *, char *);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

char
	*get_variable_direct_value(const char *name, t_shell shell)
{
	t_variable	event_variable;

	event_variable = shell->variable;
	while (!!event_variable)
	{
		if (ft_strboolcmp(name, event_variable->name))
			return (event_variable->value);
		if (!!event_variable->next)
			event_variable = event_variable->next;
		else
			return (NULL);
	}
	return (NULL);
}
