/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_arg_here_doc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:33:59 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 18:34:00 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../../main.h" /*
#typedef t_shell;
#   void arg_here_document(t_shell, int);
#*/
#include "../../../libft/libft.h" /*
#   bool ft_strboolcmp(char *, char *);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	prepare_arg_here_doc(t_shell shell)
{
	register int	index;

	index = 0;
	while (!!shell->arg[index].this)
	{
		if (shell->arg[index].operator && \
			ft_strboolcmp(shell->arg[index].this, "<<"))
		{
			++index;
			arg_here_document(shell, index);
		}
		++index;
	}
}
