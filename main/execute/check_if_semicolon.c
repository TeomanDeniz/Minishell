/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_semicolon.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 22:18:57 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/08 22:18:58 by hdeniz           ###   ########.fr       */
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
	check_if_semicolon(t_shell shell)
{
	if (!shell->arg[shell->index].this || (shell->arg[shell->index].operator \
		&& ft_strboolcmp(shell->arg[shell->index].this, ";")))
	{
		if (!!shell->arg[shell->index].this)
			shell->index++;
		return (1);
	}
	return (0);
}
