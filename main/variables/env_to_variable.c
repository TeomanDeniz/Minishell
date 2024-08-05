/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:25:09 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/07 16:25:10 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
# define MALLOC_ERROR
#typedef t_shell;
#   void set_and_free_variable(char *, char *, t_shell);
#   void error_shell(t_shell, char *, int, char *);
#   void prepare_name(char **, char *);
#   void prepare_value(char **, char *);
#        */
#include "../../libft/libft.h" /*
#    int ft_safe_free(char **);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	env_to_variable(t_shell shell, char **env)
{
	register int	index;
	char			*name;
	char			*value;

	index = -1;
	while (++index, !!env && !!env[index])
	{
		prepare_name(&name, env[index]);
		if (!name && !!env[index])
			error_shell(shell, MALLOC_ERROR, (__LINE__ - 2), "prepare_name()");
		prepare_value(&value, env[index]);
		if (!value && !!env[index] && ft_safe_free(&name))
			error_shell(shell, MALLOC_ERROR, (__LINE__ - 2), "prepare_value()");
		set_and_free_variable(name, value, shell);
		ft_safe_free(&name);
		ft_safe_free(&value);
	}
}
