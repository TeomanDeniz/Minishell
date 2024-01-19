/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_variables.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:21:10 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/07 15:21:11 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#typedef t_variable;
#typedef t_shell;
#*/
#include "../../libft/libft.h" /*
#   bool ft_safe_free(char **);
#*/
#include <stdlib.h> /*
#   void free(void *);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	free_all_variables(t_shell shell)
{
	t_variable	event_variable;
	t_variable	next_variable;

	event_variable = shell->variable;
	while (!!event_variable)
	{
		ft_safe_free(&event_variable->value);
		ft_safe_free(&event_variable->name);
		next_variable = event_variable->next;
		free(event_variable);
		event_variable = next_variable;
	}
	shell->variable = NULL;
}
