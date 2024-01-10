/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:45:10 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/08 15:45:11 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdbool.h> /*
# define true;
# define false;
#typedef bool;
#*/
#include "../main.h" /*
# define UNEX_TOKEN;
# define UNEX_TOKEN_NEWLINE;
# struct s_arg;
#typedef t_shell;
#   char *get_variable(char *, t_shell);
#*/
#include <stdio.h> /*
#    int printf(char *, ...);
#*/
#include "../../libft/libft.h" /*
#   bool ft_strboolcmp(char *, char *);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
static bool	ft_strmorecmp(const char *string, const char *compare);
static bool	if_check_syntax_error(struct s_arg *arg, int *index);
static bool	if_check_newline_syntax(struct s_arg *arg, register int index);
/* *************************** [^] PROTOTYPES [^] *************************** */

bool
	check_syntax_error(t_shell shell)
{
	int	index;

	index = 0;
	while (!!shell->arg[index].this)
	{
		if (shell->arg[index].operator && \
			if_check_syntax_error(shell->arg, &index))
		{
			printf(UNEX_TOKEN, get_variable("CMD42_NAME", shell), \
				shell->arg[index].this);
			shell->errorlevel = 258U;
			return (true);
		}
		if (shell->arg[index].operator && \
			if_check_newline_syntax(shell->arg, index))
		{
			printf(UNEX_TOKEN_NEWLINE, get_variable("CMD42_NAME", shell));
			shell->errorlevel = 258U;
			return (true);
		}
		++index;
	}
	return (false);
}

static bool
	ft_strmorecmp(const char *string, const char *compare)
{
	if (string == compare)
		return (true);
	if (!string || !compare)
		return (false);
	while (!!*string && !!*compare && *string == *compare)
		string += (++compare, 1);
	if (!*compare && *(compare - 1) == *string)
		return (true);
	return (false);
}

static bool
	if_check_syntax_error(struct s_arg *arg, int *index)
{
	char	*this;
	bool	past_is_operator;
	bool	next_is_operator;

	this = arg[*index].this;
	past_is_operator = !!*index && arg[*index - 1].operator;
	next_is_operator = arg[*index + 1].operator;
	if (arg[*index].operator && (\
		(ft_strboolcmp(this, "|") && !*index) || \
		(ft_strboolcmp(this, ";") && !*index) || \
		ft_strmorecmp(this, "|") || ft_strmorecmp(this, ";") || \
		ft_strmorecmp(this, "<<") || ft_strmorecmp(this, ">>") || \
		(ft_strboolcmp(this, ";") && past_is_operator) || \
		(ft_strboolcmp(this, "|") && next_is_operator) || \
		(ft_strboolcmp(this, ">>") && next_is_operator && ++*index) || \
		(ft_strboolcmp(this, ">") && next_is_operator && ++*index) || \
		(ft_strboolcmp(this, "<<") && next_is_operator && ++*index) || \
		(ft_strboolcmp(this, "<") && next_is_operator && ++*index)))
		return (true);
	return (false);
}

static bool
	if_check_newline_syntax(struct s_arg *arg, register int index)
{
	char	*this;
	bool	next_is_null;

	this = arg[index].this;
	if (!this)
		return (false);
	next_is_null = false;
	if (!arg[index + 1].this)
		next_is_null = true;
	if (arg[index].operator && (\
		(ft_strboolcmp(this, "|") && next_is_null) || \
		(ft_strboolcmp(this, "<<") && next_is_null) || \
		(ft_strboolcmp(this, ">>") && next_is_null) || \
		(ft_strboolcmp(this, "<") && next_is_null) || \
		(ft_strboolcmp(this, ">") && next_is_null)))
		return (true);
	return (false);
}
