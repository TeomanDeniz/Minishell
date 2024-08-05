/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:56:06 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/08 16:56:09 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#typedef t_shell;
#    int check_next_syntax(char *);
#    int skip_docs(t_shell);
#   void remove_variable(char *, t_shell);
#    int not_a_valid_identifier(t_shell, char *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ int	check_variable_name(t_shell shell);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	command_unset(t_shell shell)
{
	shell->index++;
	shell->errorlevel = 0;
	while (!!shell->arg[shell->index].this && \
		!(shell->arg[shell->index].operator && \
		check_next_syntax(shell->arg[shell->index].this)))
	{
		skip_docs(shell);
		if (!check_variable_name(shell))
		{
			not_a_valid_identifier(shell, "unset");
			shell->index++;
			continue ;
		}
		remove_variable(shell->arg[shell->index].this, shell);
		shell->index++;
	}
}

extern __inline__ int
	check_variable_name(t_shell shell)
{
	char	*this;

	this = shell->arg[shell->index].this;
	if (!this)
		return (0);
	this = shell->arg[shell->index].this;
	if (*this != '_' && !(*this >= 'a' && *this <= 'z') && \
		!(*this >= 'A' && *this <= 'Z'))
		return (0);
	return (1);
}
