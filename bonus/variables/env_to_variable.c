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
# define MALLOC_ERROR;
#typedef t_shell;
#   void set_and_free_variable(char *, char *, t_shell);
#   void error_shell(t_shell, char *, int, char *);
#*/
#include "../../libft/libft.h" /*
#   bool ft_safe_free(char **);
#   void *ft_calloc(Uint, Uint);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
static void	prepare_name(char **name, char *env);
static void	prepare_value(char **value, char *env);
/* *************************** [^] PROTOTYPES [^] *************************** */

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

static void
	prepare_name(char **name, char *env)
{
	register int	index;

	index = 0;
	while (!!env && !!env[index] && env[index] != '=')
		++index;
	*name = (char *) ft_calloc(sizeof(char), index + 1);
	if (!(*name))
		return ;
	index = -1;
	while (++index, !!env && !!env[index] && env[index] != '=')
		(*name)[index] = env[index];
	(*name)[index] = 0;
}

static void
	prepare_value(char **value, char *env)
{
	register int	index;

	while (!!env && !!*env && *env != '=')
		env += 1;
	if (!*env)
	{
		*value = NULL;
		return ;
	}
	if (*env == '=')
		env += 1;
	index = 0;
	while (!!env && !!env[index] && env[index])
		++index;
	*value = (char *) ft_calloc(sizeof(char), index + 1);
	if (!(*value))
		return ;
	index = -1;
	while (++index, !!env && !!env[index] && env[index])
		(*value)[index] = env[index];
	(*value)[index] = 0;
}
