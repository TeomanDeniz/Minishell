	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_set_varible.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:27:56 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/07 17:27:58 by hdeniz           ###   ########.fr       */
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
	command_set_varible(t_shell shell)
{
	char	*name;
	char	*value;

	shell->errorlevel = 0;
	prepare_name(&name, shell->arg[shell->index].this);
	if (!name && !!shell->arg[shell->index].this)
		error_shell(shell, MALLOC_ERROR, (__LINE__ - 2), "prepare_name()");
	prepare_value(&value, shell->arg[shell->index].this);
	if (!value && !!(shell->arg[shell->index].this[ft_strlen(name)]) && \
		ft_safe_free(&name))
		error_shell(shell, MALLOC_ERROR, (__LINE__ - 2), "prepare_value()");
	set_and_free_variable(name, value, shell);
	ft_safe_free(&name);
	ft_safe_free(&value);
}
