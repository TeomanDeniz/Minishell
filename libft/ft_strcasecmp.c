/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasecmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 22:19:41 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/06 22:19:43 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdbool.h> /*
#typedef bool;
# define false;
# define true;
*/
/* **************************** [^] INCLUDES [^] **************************** */

static char
	detect_case(register char compare, register char command)
{
	if (command == 'l' && compare >= 'A' && compare <= 'Z')
		return (32);
	if (command == 'U' && compare >= 'a' && compare <= 'z')
		return (-32);
	return (0);
}

bool
	ft_strcasecmp(const char *const string, const char *const compare)
{
	register unsigned int	index;

	if (string == compare)
		return (true);
	if (!string || !compare)
		return (false);
	index = 0U;
	while (!!string[index] && !!compare[index] && \
		(string[index] == (compare[index] + \
		detect_case(compare[index], 'l')) || \
		string[index] == (compare[index] + \
		detect_case(compare[index], 'U')) || \
		string[index] == (compare[index])))
		++index;
	if (!compare[index] && !string[index])
		return (true);
	return (false);
}
