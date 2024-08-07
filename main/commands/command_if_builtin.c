/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_if_builtin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:16:26 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/08 17:16:27 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../../libft/libft.h" /*
#    int ft_strboolcmp(char *, char *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

int
	command_if_builtin(char *command)
{
	if (ft_strboolcmp(command, "echo") || ft_strboolcmp(command, "exit") || \
		ft_strboolcmp(command, "cd") || ft_strboolcmp(command, "pwd") || \
		ft_strboolcmp(command, "env") || ft_strboolcmp(command, "export") || \
		ft_strboolcmp(command, "unset"))
		return (1);
	return (0);
}
