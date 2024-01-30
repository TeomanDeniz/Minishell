/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct_variable_creation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:01:51 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/08 17:01:52 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#typedef t_shell;
#   bool skip_docs(t_shell);
#   bool check_next_syntax(char *);
#   void command_set_varible(t_shell);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	direct_variable_creation(t_shell shell)
{
	while (skip_docs(shell), !!shell->arg[shell->index].this && \
		!(shell->arg[shell->index].operator && \
		check_next_syntax(shell->arg[shell->index].this)))
	{
		command_set_varible(shell);
		shell->index++;
	}
}
