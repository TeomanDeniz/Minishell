/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_variable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:44:43 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/07 17:44:44 by hdeniz           ###   ########.fr       */
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
	*get_variable(const char *name, t_shell shell)
{
	t_variable	event_variable;

	event_variable = shell->variable;
	while (!!event_variable)
	{
		if (ft_strboolcmp(name, event_variable->name))
		{
			if (!event_variable->value)
				return ("");
			return (event_variable->value);
		}
		if (!!event_variable->next)
			event_variable = event_variable->next;
		else
			return ("");
	}
	return ("");
}
