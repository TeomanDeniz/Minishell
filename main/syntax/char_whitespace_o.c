/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_whitespace_o.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:24:36 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 17:24:37 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#typedef t_operator;
#    int char_whitespace_o(char, t_operator);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

int
	char_whitespace_o(register char character, t_operator operator)
{
	if (!(operator->double_quote || operator->single_quote) && \
		char_whitespace(character))
		return (1);
	return (0);
}
