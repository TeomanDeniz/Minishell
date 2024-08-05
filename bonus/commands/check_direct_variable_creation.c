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
#   bool skip_docs(t_shell);
#   bool check_next_syntax(char *);
#*/
#include <stdbool.h> /*
# define true;
# define false;
#typedef bool;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
static bool	check_variable_valid(char *arg);
/* *************************** [^] PROTOTYPES [^] *************************** */

bool
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
			return (false);
		}
		index++;
	}
	return (true);
}

static bool
	check_variable_valid(char *arg)
{
	if (*arg != '_' && !(*arg >= 'a' && *arg <= 'z') && \
		!(*arg >= 'A' && *arg <= 'Z'))
		return (false);
	while (++arg, !!*arg && *arg != '=')
	{
		if (*arg != '=' && *arg != '_' && !(*arg >= 'a' && *arg <= 'z') && \
			!(*arg >= 'A' && *arg <= 'Z') && !(*arg >= '0' && *arg <= '9'))
			return (false);
	}
	if (*arg == '=')
		return (true);
	return (false);
}
