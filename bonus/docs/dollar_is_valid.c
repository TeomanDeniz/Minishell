/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_is_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:06:55 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 18:06:55 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdbool.h> /*
# define true;
# define false;
#typedef bool;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

bool
	dollar_is_valid(char *input)
{
	register int	index;

	index = 0;
	if (!input)
		return (false);
	while (!!input[index] && input[index] != '$')
		++index;
	while (!!input[index])
	{
		++index;
		if (!!input[index] && ((input[index] >= 'a' && input[index] <= 'z') || \
			((input[index] >= 'A' && input[index] <= 'Z')) || \
			input[index] == '_' || input[index] == '?'))
			return (true);
	}
	return (false);
}
