/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:45:10 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/08 15:45:11 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
# define UNEX_TOKEN
# define UNEX_TOKEN_NEWLINE
# struct s_arg;
#typedef t_shell;
#   char *get_variable(char *, t_shell);
#    int check_next_syntax(char *);
#        */
#include <stdio.h> /*
#    int printf(char *, ...);
#        */
#include "../../libft/libft.h" /*
#    int ft_strboolcmp(char *, char *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ int	ft_strmorecmp(const char *string, const char *compare);
extern __inline__ int	if_check_syntax_error(struct s_arg *arg, int *index);
extern __inline__ int	if_check_newline_syntax(struct s_arg *arg, \
register int index);
/* *************************** [^] PROTOTYPES [^] *************************** */

int
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
			shell->errorlevel = (unsigned int)258;
			return (1);
		}
		if (shell->arg[index].operator && \
			if_check_newline_syntax(shell->arg, index))
		{
			printf(UNEX_TOKEN_NEWLINE, get_variable("CMD42_NAME", shell));
			shell->errorlevel = (unsigned int)258;
			return (1);
		}
		++index;
	}
	return (0);
}

extern __inline__ int
	ft_strmorecmp(const char *string, const char *compare)
{
	if (string == compare)
		return (1);
	if (!string || !compare)
		return (0);
	while (!!*string && !!*compare && *string == *compare)
		string += (++compare, 1);
	if (!*compare && *(compare - 1) == *string)
		return (1);
	return (0);
}

extern __inline__ int
	if_check_syntax_error(struct s_arg *arg, int *index)
{
	char			*this;
	register int	past_is_operator;
	register int	next_is_operator;

	this = arg[*index].this;
	past_is_operator = !!*index && arg[*index - 1].operator;
	next_is_operator = arg[*index + 1].operator;
	if (arg[*index].operator && (\
		(ft_strboolcmp(this, "|") && !*index) || \
		(ft_strboolcmp(this, ";") && !*index) || \
		ft_strmorecmp(this, "|") || ft_strmorecmp(this, ";") || \
		ft_strmorecmp(this, "<<") || ft_strmorecmp(this, ">>") || \
		(ft_strboolcmp(this, ";") && past_is_operator) || \
		(ft_strboolcmp(this, "|") && next_is_operator && \
		check_next_syntax(arg[*index + 1].this)) || \
		(ft_strboolcmp(this, ";") && next_is_operator && \
		check_next_syntax(arg[*index + 1].this)) || \
		(ft_strboolcmp(this, ">>") && next_is_operator && ++*index) || \
		(ft_strboolcmp(this, ">") && next_is_operator && ++*index) || \
		(ft_strboolcmp(this, "<<") && next_is_operator && ++*index) || \
		(ft_strboolcmp(this, "<") && next_is_operator && ++*index)))
		return (1);
	return (0);
}

extern __inline__ int
	if_check_newline_syntax(struct s_arg *arg, register int index)
{
	char			*this;
	register int	next_is_null;

	this = arg[index].this;
	if (!this)
		return (0);
	next_is_null = 0;
	if (!arg[index + 1].this)
		next_is_null = 1;
	if (arg[index].operator && (\
		(ft_strboolcmp(this, "<<") && next_is_null) || \
		(ft_strboolcmp(this, ">>") && next_is_null) || \
		(ft_strboolcmp(this, "<") && next_is_null) || \
		(ft_strboolcmp(this, ">") && next_is_null)))
		return (1);
	return (0);
}
