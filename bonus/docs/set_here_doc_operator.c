/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_here_doc_operator.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:52:50 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 17:52:51 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#typedef t_operator;
#   void set_double_quote(t_operator);
#   void set_single_quote(t_operator);
#   bool char_whitespace(char);
#*/
#include <stdbool.h> /*
# define true;
# define false;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
static void	pipe_doc(char *input, t_operator operator);
/* *************************** [^] PROTOTYPES [^] *************************** */

int
	set_here_doc_operator(char *input, t_operator operator)
{
	int		result;

	result = 0;
	if (!!input && !!*input && operator->pipe)
		operator->pipe = false;
	while (!!*input)
	{
		if (*input == '\'' && !operator->double_quote)
			set_single_quote(operator);
		else if (*input == '\"' && !operator->single_quote)
			set_double_quote(operator);
		else if (!operator->double_quote && \
			!operator->single_quote && *input == '|')
			pipe_doc(input, operator);
		else if (!operator->double_quote && \
			!operator->single_quote && *input == '(')
			++result;
		else if (!operator->double_quote && \
			!operator->single_quote && *input == ')')
			--result;
		input += 1;
	}
	return (result);
}

static void
	pipe_doc(char *input, t_operator operator)
{
	char	*check_input;

	check_input = input;
	while (++check_input, !!*check_input)
	{
		if (char_whitespace(*check_input))
			continue ;
		return ;
	}
	operator->pipe = true;
	operator->double_quote = false;
	operator->single_quote = false;
}
