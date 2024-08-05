/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_direct_variable_creation.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:59:41 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/08 16:59:41 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#typedef t_shell;
#    int skip_docs(t_shell);
#    int check_next_syntax(char *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ int	check_variable_valid(char *arg);
/* *************************** [^] PROTOTYPES [^] *************************** */

int
	check_direct_variable_creation(t_shell shell)
{
	register int	index;

	index = shell->index;
	while (skip_docs(shell), !!shell->arg[index].this && \
		!(shell->arg[index].operator && \
		check_next_syntax(shell->arg[index].this)))
	{
		if (!check_variable_valid(shell->arg[index].this))
		{
			shell->index += index - shell->index;
			return (0);
		}
		index++;
	}
	return (1);
}

extern __inline__ int
	check_variable_valid(char *arg)
{
	if (*arg != '_' && !(*arg >= 'a' && *arg <= 'z') && \
		!(*arg >= 'A' && *arg <= 'Z'))
		return (0);
	while (++arg, !!*arg && *arg != '=')
	{
		if (*arg != '=' && *arg != '_' && !(*arg >= 'a' && *arg <= 'z') && \
			!(*arg >= 'A' && *arg <= 'Z') && !(*arg >= '0' && *arg <= '9'))
			return (0);
	}
	if (*arg == '=')
		return (1);
	return (0);
}
