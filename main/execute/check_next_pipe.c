/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_next_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 22:17:12 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/08 22:17:13 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdbool.h> /*
# define true;
# define false;
#typedef bool;
#*/
#include "../main.h" /*
#typedef t_shell;
#*/
#include "../../libft/libft.h" /*
#   bool ft_strboolcmp(char *, char *);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

bool
	check_next_pipe(t_shell shell)
{
	register int	index;

	index = shell->index;
	while (++index, !!shell->arg[index].this)
	{
		if (shell->arg[index].operator && \
			ft_strboolcmp(shell->arg[index].this, "|"))
			return (true);
		if (shell->arg[index].operator && \
			ft_strboolcmp(shell->arg[index].this, ";"))
			return (false);
	}
	return (false);
}
