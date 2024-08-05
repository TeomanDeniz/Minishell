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
#    int char_whitespace(char);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ void	pipe_doc(char *input, t_operator operator);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	set_here_doc_operator(char *input, t_operator operator)
{
	char	*org_input;

	if (!!input && !!*input && operator->pipe)
		operator->pipe = 0;
	org_input = input;
	while (!!*input)
	{
		if (*input == '\'' && !operator->double_quote)
			set_single_quote(operator);
		else if (*input == '\"' && !operator->single_quote)
			set_double_quote(operator);
		else if (!operator->double_quote && \
			!operator->single_quote && *input == '|')
			pipe_doc(input, operator);
		input += 1;
	}
	input = org_input;
}

extern __inline__ void
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
	operator->pipe = 1;
	operator->double_quote = 0;
	operator->single_quote = 0;
}
