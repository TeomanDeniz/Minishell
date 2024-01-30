/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_equal_valid_true.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:21:25 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/08 23:21:26 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdbool.h> /*
# define true;
# define false;
#typedef bool;
#*/
#include "../main.h" /*
#typedef t_shell;
#   bool char_whitespace(char);
#   bool check_next_syntax(char *);
#   bool not_a_valid_identifier(t_shell, char *);
#*/
#include "../../libft/libft.h" /*
#   bool ft_strboolcmp(char *, char *);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
static bool	check_next_args(t_shell shell);
/* *************************** [^] PROTOTYPES [^] *************************** */

bool
	check_equal_valid_true(t_shell shell, char *command)
{
	bool	operator_found;
	char	*this;

	operator_found = false || ft_strboolcmp(command, "export");
	this = shell->arg[shell->index].this;
	if (!this)
		return (false);
	while (++this, *(this - 1) && !operator_found && !char_whitespace(*this) \
		&& *this != '\n')
		if (*(this - 1) == '=')
			operator_found = true;
	if (!operator_found || (!command && !!shell->arg[shell->index + 1].this \
		&& check_next_args(shell) && shell->index++))
		return (false);
	this = shell->arg[shell->index].this;
	if (*this != '_' && !(*this >= 'a' && *this <= 'z') && \
		!(*this >= 'A' && *this <= 'Z'))
		return (!not_a_valid_identifier(shell, command));
	while (++this, !!*this && *this != '=')
	{
		if (*this != '=' && *this != '_' && !(*this >= 'a' && *this <= 'z') && \
			!(*this >= 'A' && *this <= 'Z') && !(*this >= '0' && *this <= '9'))
			return (!not_a_valid_identifier(shell, command));
	}
	return (true);
}

static bool
	check_next_args(t_shell shell)
{
	register int	index;

	index = shell->index;
	while (!!shell->arg[index].this)
	{
		if (check_next_syntax(shell->arg[index].this))
			index += 2;
		else
			return (true);
	}
	return (false);
}
