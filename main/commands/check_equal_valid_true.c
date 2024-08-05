/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_equal_valid_true.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:21:25 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/08 23:21:26 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#typedef t_shell;
#    int char_whitespace(char);
#    int check_next_syntax(char *);
#    int not_a_valid_identifier(t_shell, char *);
#        */
#include "../../libft/libft.h" /*
#    int ft_strboolcmp(char *, char *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ int	check_next_args(t_shell shell);
/* *************************** [^] PROTOTYPES [^] *************************** */

int
	check_equal_valid_true(t_shell shell, char *command)
{
	register int	operator_found;
	char			*this;

	operator_found = ft_strboolcmp(command, "export");
	this = shell->arg[shell->index].this;
	if (!this)
		return (0);
	while (++this, *(this - 1) && !operator_found && !char_whitespace(*this) \
		&& *this != '\n')
		if (*(this - 1) == '=')
			operator_found = 1;
	if (!operator_found || (!command && !!shell->arg[shell->index + 1].this \
		&& check_next_args(shell) && shell->index++))
		return (0);
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
	return (1);
}

extern __inline__ int
	check_next_args(t_shell shell)
{
	register int	index;

	index = shell->index;
	while (!!shell->arg[index].this)
	{
		if (check_next_syntax(shell->arg[index].this))
			index += 2;
		else
			return (1);
	}
	return (0);
}
