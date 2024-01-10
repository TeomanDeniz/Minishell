/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_arg_file_doc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:34:30 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 17:34:31 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../../main.h" /*
#typedef t_shell;
#   void arg_file_document(t_shell, int);
#*/
#include "../../../libft/libft.h" /*
#   bool ft_strboolcmp(char *, char *);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	prepare_arg_file_doc(t_shell shell)
{
	register int	index;

	index = 0;
	while (!!shell->arg[index].this)
	{
		if (shell->arg[index].operator && \
			ft_strboolcmp(shell->arg[index].this, "<"))
		{
			++index;
			arg_file_document(shell, index);
		}
		++index;
	}
}
