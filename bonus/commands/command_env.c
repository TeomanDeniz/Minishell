/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:19:07 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/08 16:19:08 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#typedef t_shell;
#typedef t_variable;
#*/
#include <unistd.h> /*
# define STDOUT_FILENO;
#ssize_t write(int, void *, size_t);
#*/
#include "../../libft/libft.h" /*
#    int ft_strlen(char *);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	command_env(t_shell shell)
{
	t_variable	org_variable;

	shell->errorlevel = 0U;
	org_variable = shell->variable;
	while (shell->variable != NULL)
	{
		if (shell->variable->value)
		{
			write(STDOUT_FILENO, shell->variable->name, \
				ft_strlen(shell->variable->name));
			write(STDOUT_FILENO, "=", 1);
			if (!!shell->variable->value)
				write(STDOUT_FILENO, shell->variable->value, \
					ft_strlen(shell->variable->value));
			write(STDOUT_FILENO, "\n", 1);
		}
		shell->variable = shell->variable->next;
	}
	shell->variable = org_variable;
}
