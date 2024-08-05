/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:59:05 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 12:59:06 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
# struct s_operator;
#typedef t_shell;
#    int char_whitespace_o(char, t_operator);
#    int char_quote_o(char, struct s_operator);
#    int char_whitespace(char);
#   void set_double_quote(t_operator);
#   void set_single_quote(t_operator);
#    int char_operator_o(char, struct s_operator);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ int	skip_whitespaces_index(const char *const input, \
int index);
extern __inline__ int	arg_counter_quote(int index, char *input, \
t_operator operator);
extern __inline__ void	arg_counter_event(t_shell shell, int *index, \
t_operator operator);
extern __inline__ int	arg_operator_event(t_shell shell, int *index, \
t_operator operator);
/* *************************** [^] PROTOTYPES [^] *************************** */

int
	arg_counter(t_shell shell)
{
	int					result;
	int					index;
	struct s_operator	operator;

	index = 0;
	result = 0;
	operator = (struct s_operator){0, 0, 0};
	while (!!shell->input[index])
	{
		if (char_whitespace_o(shell->input[index], &operator))
			index = skip_whitespaces_index(shell->input, index);
		if (!shell->input[index])
			return (result);
		result++;
		while (char_quote_o(shell->input[index], operator))
			index = arg_counter_quote(index, shell->input, &operator);
		if (arg_operator_event(shell, &index, &operator))
			continue ;
		arg_counter_event(shell, &index, &operator);
	}
	return (result);
}

extern __inline__ int
	skip_whitespaces_index(const char *const input, int index)
{
	while (!!input[index] && char_whitespace(input[index]))
		++index;
	return (index);
}

extern __inline__ int
	arg_counter_quote(int index, char *input, t_operator operator)
{
	if (input[index] == '\"' && !operator->single_quote)
	{
		set_double_quote(operator);
		return (index + 1);
	}
	if (input[index] == '\'' && !operator->double_quote)
	{
		set_single_quote(operator);
		return (index + 1);
	}
	return (index);
}

extern __inline__ void
	arg_counter_event(t_shell shell, int *index, t_operator operator)
{
	while (!!shell->input[*index] && \
		!char_whitespace_o(shell->input[*index], operator) && \
		!char_operator_o(shell->input[*index], *operator))
	{
		*index += 1;
		while (char_quote_o(shell->input[*index], *operator))
			*index = arg_counter_quote(*index, shell->input, operator);
	}
}

extern __inline__ int
	arg_operator_event(t_shell shell, int *index, t_operator operator)
{
	register char	operator_character;

	operator_character = 0;
	if (!!shell->input[*index] && \
		char_operator_o(shell->input[*index], *operator))
	{
		operator_character = shell->input[*index];
		while (char_operator_o(shell->input[*index], *operator) && \
			shell->input[*index] == operator_character)
			++(*index);
		return (1);
	}
	return (0);
}
