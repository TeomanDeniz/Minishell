/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:26:46 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/07 15:26:47 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
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
	free_arg(t_shell shell)
{
	register int	index;

	index = -1;
	if (!shell->arg)
		return ;
	while (++index, !!shell->arg[index].this)
		ft_safe_free(&shell->arg[index].this);
	free(shell->arg);
	shell->arg = NULL;
}
