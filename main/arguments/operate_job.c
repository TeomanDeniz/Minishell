/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_job.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:54:54 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/08 23:54:54 by hdeniz           ###   ########.fr       */
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
#typedef t_operator;
#   bool tilda_valid(t_shell, t_operator, int);
#   char *get_variable(char *, t_shell);
#   bool dollar_valid(t_shell, int);
#   char *get_varaible_by_name(char *, t_shell, int);
#    int variable_name_len(char *, int);
#*/
#include "../../libft/libft.h" /*
# define END_OF_NUMBER_INDEX;
#   char ft_numindex(long long , Ushort);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
static int	overwrite_this(char *overwrite, char *copy, int *string_index);
static int	put_dollar(t_shell shell, char **this, int *string_index);
static int	put_exit_status(t_shell shell, char **this, int *string_index);
/* *************************** [^] PROTOTYPES [^] *************************** */

bool
	operate_job(t_shell shell, int arg_index, int *string_index, t_operator op)
{
	char	*this;

	if (op->single_quote)
		return (false);
	this = shell->arg[arg_index].this;
	if (*shell->input == '~' && tilda_valid(shell, op, 0))
	{
		shell->input += \
			overwrite_this(this, get_variable("HOME", shell), string_index);
		return (true);
	}
	if (*shell->input == '$' && *(shell->input + 1) == '?')
	{
		shell->input += put_exit_status(shell, &this, string_index);
		return (true);
	}
	else if (*shell->input == '$' && dollar_valid(shell, 0))
	{
		shell->input += put_dollar(shell, &this, string_index);
		return (true);
	}
	return (false);
}

static int
	overwrite_this(char *overwrite, char *copy, int *string_index)
{
	register int	index;

	if (!copy)
		return (1);
	index = -1;
	while (++index, !!copy[index])
	{
		overwrite[*string_index] = copy[index];
		++(*string_index);
	}
	return (1);
}

static int
	put_dollar(t_shell shell, char **this, int *string_index)
{
	char			*variable;
	register int	variable_index;

	variable_index = 0;
	variable = get_varaible_by_name(shell->input, shell, 0);
	while (variable[variable_index])
	{
		(*this)[*string_index] = variable[variable_index];
		++variable_index;
		*string_index += 1;
	}
	return (variable_name_len(shell->input + 1, 0));
}

static int
	put_exit_status(t_shell shell, char **this, int *string_index)
{
	register char	value;
	register int	variable_index;

	variable_index = 0;
	value = 0;
	while (1)
	{
		value = 48 + ft_numindex(shell->errorlevel, variable_index);
		if (value == END_OF_NUMBER_INDEX)
			return (2);
		(*this)[*string_index] = value;
		++variable_index;
		*string_index += 1;
	}
}
