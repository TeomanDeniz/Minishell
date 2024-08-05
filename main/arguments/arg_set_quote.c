/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_set_quote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:57:37 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 12:57:39 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#typedef t_operator;
#   void set_double_quote(t_operator);
#   void set_single_quote(t_operator);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	arg_set_quote(register char input, t_operator operator)
{
	if (input == '\"' && !operator->single_quote)
		set_double_quote(operator);
	if (input == '\'' && !operator->double_quote)
		set_single_quote(operator);
}
