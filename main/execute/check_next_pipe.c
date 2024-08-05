/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_next_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 22:17:12 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/08 22:17:13 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#typedef t_shell;
#        */
#include "../../libft/libft.h" /*
#    int ft_strboolcmp(char *, char *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

int
	check_next_pipe(t_shell shell)
{
	register int	index;

	index = shell->index;
	while (++index, !!shell->arg[index].this)
	{
		if (shell->arg[index].operator && \
			ft_strboolcmp(shell->arg[index].this, "|"))
			return (1);
		if (shell->arg[index].operator && \
			ft_strboolcmp(shell->arg[index].this, ";"))
			return (0);
	}
	return (0);
}
