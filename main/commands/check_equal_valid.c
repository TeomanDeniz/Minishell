/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_equal_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:10:14 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/08 17:10:15 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#typedef t_shell;
#   bool char_whitespace(char);
#   bool not_a_valid_identifier(t_shell, char *);
#*/
#include <stdbool.h> /*
# define true;
# define false;
#typedef bool;
#*/
#include "../../libft/libft.h" /*
#   bool ft_strboolcmp(char *, char *);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

bool
	check_equal_valid(t_shell shell, char *command)
{
	bool	operator_found;
	char	*this;

	operator_found = false || ft_strboolcmp(command, "export");
	this = shell->arg[shell->index].this;
	if (!this)
		return (false);
	while (++this, !operator_found && !char_whitespace(*this) && *this != '\n')
		if (*(this - 1) == '=')
			operator_found = true;
	if (!operator_found)
		return (false);
	this = shell->arg[shell->index].this;
	if (*this != '_' && !(*this >= 'a' && *this <= 'z') && \
		!(*this >= 'A' && *this <= 'Z'))
		return (not_a_valid_identifier(shell, command));
	while (++this, !!*this && *this != '=')
	{
		if (*this != '=' && *this != '_' && !(*this >= 'a' && *this <= 'z') && \
			!(*this >= 'A' && *this <= 'Z') && !(*this >= '0' && *this <= '9'))
			return (not_a_valid_identifier(shell, command));
	}
	return (true);
}
