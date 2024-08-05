/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_quote_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:32:59 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 13:33:01 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
# struct s_operator;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

int
	char_quote_o(register char character, struct s_operator operator)
{
	if (character == '\'' && !operator.double_quote)
		return (1);
	if (character == '\"' && !operator.single_quote)
		return (1);
	return (0);
}
