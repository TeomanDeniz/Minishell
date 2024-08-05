/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_strlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 00:21:08 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 00:21:09 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
# struct s_operator;
#typedef t_shell;
#   void skip_whitespaces(char **, t_operator);
#   bool char_quote_o(char, struct s_operator);
#   void arg_set_quote(char, t_operator);
#   bool char_whitespace_o(char, t_operator);
#   bool char_operator_o(char, struct s_operator);
#   bool tilda_valid(t_shell, t_operator, int);
#   char *get_variable(char *, t_shell);
#   bool dollar_valid(t_shell, int);
#   char *get_varaible_by_name(char *, t_shell, int);
#*/
#include <stdbool.h> /*
# define false;
#*/
#include "../../libft/libft.h" /*
#    int ft_strlen(char *);
# Ushort ft_numlen(long long);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
static int	caluclate_variable_size(char *input, t_shell shell);
/* *************************** [^] PROTOTYPES [^] *************************** */

int
	arg_strlen(t_shell shell, char *org_input)
{
	int	result;

	result = 1 + caluclate_variable_size(shell->input, shell);
	if (!!shell->input)
		skip_whitespaces(&shell->input, &shell->operator);
	if (char_quote_o(*shell->input, shell->operator))
		arg_set_quote(*shell->input, &shell->operator);
	if (char_quote_o(*shell->input, shell->operator))
		shell->input += 1;
	while (!!shell->input && !!*shell->input && \
		!char_whitespace_o(*shell->input, &shell->operator))
	{
		if (char_quote_o(*shell->input, shell->operator))
		{
			arg_set_quote(*shell->input, &shell->operator);
			shell->input += 1;
			continue ;
		}
		if (char_operator_o(*shell->input, shell->operator))
			break ;
		shell->input += 1;
		++result;
	}
	shell->input = org_input;
	return (result);
}

static int
	caluclate_variable_size(char *input, t_shell shell)
{
	register int		index;
	int					result;
	struct s_operator	operator;

	operator = (struct s_operator){false, false, false};
	result = 1;
	index = 0;
	while (input[index])
	{
		if (input[index] == '~' && tilda_valid(shell, &operator, index))
			result += ft_strlen(get_variable("HOME", shell));
		if (input[index] == '$' && input[index + 1] == '?' && ++result)
			result += ft_numlen(shell->errorlevel);
		else if (input[index] == '$' && ++result && dollar_valid(shell, index))
			result += ft_strlen(get_varaible_by_name(input, shell, index));
		++index;
	}
	return (result);
}
