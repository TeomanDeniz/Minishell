/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_execute_arguments.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:46:40 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/08 17:46:41 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
# define MALLOC_ERROR;
#typedef t_shell;
#   void error_shell(t_shell, char *, int, char *);
#   bool check_next_syntax(char *);
#   bool check_heredoc_syntax(char *);
#   bool check_outpend_syntax(char *);
#   bool is_executable(char *, t_shell);
#*/
#include <stdlib.h> /*
#   void *malloc(size_t);
#   void free(void *);
#*/
#include "../../libft/libft.h" /*
#   bool ft_strboolcmp(char *, char *);
#   char *ft_strdup(char *);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
static int	calculate_index(t_shell shell);
static int	prepare_first_arg(char ***result, t_shell shell, int *arg_index);
static void	prepare_arg_event(t_shell shell, char **result, int index, \
char *this);
/* *************************** [^] PROTOTYPES [^] *************************** */

char
	**prepare_execute_arguments(t_shell shell, int arg_index)
{
	char			**result;
	register int	index;

	index = calculate_index(shell);
	result = (char **) malloc(sizeof(char *) * (index + 2));
	if (!result)
		error_shell(shell, MALLOC_ERROR, (__LINE__ - 2), "malloc()");
	index = prepare_first_arg(&result, shell, &arg_index);
	while (!!shell->arg[arg_index].this && !(shell->arg[arg_index].operator && \
		check_next_syntax(shell->arg[arg_index].this)))
	{
		if (shell->arg[arg_index].operator && \
			(check_heredoc_syntax(shell->arg[arg_index].this) || \
			check_outpend_syntax(shell->arg[arg_index].this)))
		{
			arg_index += 2;
			continue ;
		}
		prepare_arg_event(shell, result, index, shell->arg[arg_index].this);
		++arg_index;
		++index;
	}
	result[index] = NULL;
	return (result);
}

static int
	calculate_index(t_shell shell)
{
	register int	index;
	int				result;

	result = 0;
	index = shell->index;
	while (!!shell->arg[index].this && !(shell->arg[index].operator && \
		!check_next_syntax(shell->arg[index].this)))
	{
		if (shell->arg[index].operator && \
			!check_heredoc_syntax(shell->arg[index].this))
		{
			index += 2;
			continue ;
		}
		++result;
		++index;
	}
	return (result);
}

static int
	prepare_first_arg(char ***result, t_shell shell, int *arg_index)
{
	while (shell->arg[*arg_index].operator && (\
		ft_strboolcmp(shell->arg[*arg_index].this, "<") || \
		ft_strboolcmp(shell->arg[*arg_index].this, "<<") || \
		ft_strboolcmp(shell->arg[*arg_index].this, ">") || \
		ft_strboolcmp(shell->arg[*arg_index].this, ">>")))
		*arg_index += 2;
	if (!is_executable(shell->arg[*arg_index].this, shell))
		return (0);
	*result[0] = ft_strdup(shell->arg[*arg_index].this);
	if (!*result[0])
	{
		free(*result);
		*result = NULL;
		error_shell(shell, MALLOC_ERROR, (__LINE__ - 3), "ft_strdup()");
	}
	*arg_index += 1;
	return (1);
}

static void
	prepare_arg_event(t_shell shell, char **result, int index, char *this)
{
	result[index] = ft_strdup(this);
	if (!result[index])
	{
		while (--index, index)
			free(result[index]);
		free(result);
		error_shell(shell, MALLOC_ERROR, (__LINE__ - 6), "ft_strdup()");
	}
}
