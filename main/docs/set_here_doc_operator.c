/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_here_doc_operator.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
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
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	set_here_doc_operator(char *input, t_operator operator)
{
	char	*org_input;

	org_input = input;
	while (!!*input)
	{
		if (*input == '\'' && !operator->double_quote)
			set_single_quote(operator);
		else if (*input == '\"' && !operator->single_quote)
			set_double_quote(operator);
		input += 1;
	}
	input = org_input;
}
