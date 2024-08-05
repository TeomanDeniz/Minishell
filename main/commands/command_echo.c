/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:56:55 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/08 15:56:56 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#typedef t_shell;
#    int check_next_syntax(char *);
#    int skip_docs(t_shell);
#        */
#include "../../libft/libft.h" /*
#    int ft_strboolcmp(char *, char *);
#    int ft_strlen(char *);
#        */
#include <unistd.h> /*
# define STDOUT_FILENO
#ssize_t write(int, void *, size_t);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	command_echo(t_shell shell)
{
	register int	flag;

	flag = 0;
	if (++shell->index, ft_strboolcmp(shell->arg[shell->index].this, "-n"))
		flag = (shell->index++, 1);
	while (!!shell->arg[shell->index].this)
	{
		if (shell->arg[shell->index].operator && \
			check_next_syntax(shell->arg[shell->index].this))
			break ;
		skip_docs(shell);
		write(STDOUT_FILENO, shell->arg[shell->index].this, \
			ft_strlen(shell->arg[shell->index].this));
		shell->index++;
		if (!!shell->arg[shell->index].this)
			write(STDOUT_FILENO, " ", 1);
	}
	write(STDOUT_FILENO, "\n", !flag);
	shell->errorlevel = 0U;
}
