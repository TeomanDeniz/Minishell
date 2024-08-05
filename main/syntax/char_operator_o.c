/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_operator_o.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:20:15 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 17:20:16 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
# struct s_operator;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

int
	char_operator_o(register char character, struct s_operator operator)
{
	if (!(operator.double_quote || operator.single_quote) && \
		char_operator(character))
		return (1);
	return (0);
}
