/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_equal_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:10:14 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/08 17:10:15 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#typedef t_shell;
#    int char_whitespace(char);
#    int not_a_valid_identifier(t_shell, char *);
#        */
#include "../../libft/libft.h" /*
#    int ft_strboolcmp(char *, char *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

int
	check_equal_valid(t_shell shell, char *command)
{
	register int	operator_found;
	char			*this;

	operator_found = ft_strboolcmp(command, "export");
	this = shell->arg[shell->index].this;
	if (!this)
		return (0);
	while (++this, !operator_found && !char_whitespace(*this) && *this != '\n')
		if (*(this - 1) == '=')
			operator_found = 1;
	if (!operator_found)
		return (0);
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
	return (1);
}
