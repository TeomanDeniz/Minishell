/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:21:53 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/07 16:21:54 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#typedef t_shell;
#typedef t_variable;
#*/
#include <stdbool.h> /*
#typedef bool;
# define true;
# define false;
*/
#include "../../libft/libft.h" /*
#   char ft_strcmp(char *, char *);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
static void	swap_variables(t_variable *variable);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	sort_variables(t_shell shell)
{
	bool		swapped;
	t_variable	*ptr;
	t_variable	last;

	last = NULL;
	swapped = true;
	while (swapped)
	{
		swapped = false;
		ptr = &(shell->variable);
		while (!!(*ptr) && (*ptr)->next != last)
		{
			if (ft_strcmp((*ptr)->name, (*ptr)->next->name) > 0)
			{
				swap_variables(ptr);
				swapped = true;
			}
			if (!!(*ptr)->next)
				ptr = &((*ptr)->next);
			else
				return ;
		}
		last = (*ptr);
	}
}

static void
	swap_variables(t_variable *variable)
{
	t_variable	temp;

	if (*variable == NULL || (*variable)->next == NULL)
		return ;
	temp = (*variable)->next;
	(*variable)->next = temp->next;
	temp->next = *variable;
	*variable = temp;
}
