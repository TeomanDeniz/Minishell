/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_docs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:02:45 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/08 16:02:46 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#typedef t_shell;
#    int check_arrow_syntax(char *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

int
	skip_docs(t_shell shell)
{
	while (shell->arg[shell->index].this && \
		shell->arg[shell->index].operator && \
		check_arrow_syntax(shell->arg[shell->index].this))
		shell->index += 2;
	return (1);
}
