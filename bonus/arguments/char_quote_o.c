/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_quote_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:32:59 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 13:33:01 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdbool.h> /*
# define true;
# define false;
#typedef bool;
#*/
#include "../main.h" /*
# struct s_operator;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

bool
	char_quote_o(register char character, struct s_operator operator)
{
	if (character == '\'' && !operator.double_quote)
		return (true);
	if (character == '\"' && !operator.single_quote)
		return (true);
	return (false);
}
