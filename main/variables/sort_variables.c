/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:21:53 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/07 16:21:54 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#typedef t_shell;
#typedef t_variable;
#        */
#include "../../libft/libft.h" /*
#   char ft_strcmp(char *, char *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ void	swap_variables(t_variable *variable);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	sort_variables(t_shell shell)
{
	register int	swapped;
	t_variable		*ptr;
	t_variable		last;

	last = ((void *)0);
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		ptr = &(shell->variable);
		while (!!(*ptr) && (*ptr)->next != last)
		{
			if (ft_strcmp((*ptr)->name, (*ptr)->next->name) > 0)
			{
				swap_variables(ptr);
				swapped = 1;
			}
			if (!!(*ptr)->next)
				ptr = &((*ptr)->next);
			else
				return ;
		}
		last = (*ptr);
	}
}

extern __inline__ void
	swap_variables(t_variable *variable)
{
	t_variable	temp;

	if (*variable == ((void *)0) || (*variable)->next == ((void *)0))
		return ;
	temp = (*variable)->next;
	(*variable)->next = temp->next;
	temp->next = *variable;
	*variable = temp;
}
