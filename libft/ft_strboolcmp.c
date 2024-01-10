/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strboolcmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 22:23:25 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/06 22:23:26 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdbool.h> /*
#typedef bool;
# define false;
# define true;
*/
/* **************************** [^] INCLUDES [^] **************************** */

bool
	ft_strboolcmp(const char *string, const char *compare)
{
	if (string == compare)
		return (true);
	if (!string || !compare)
		return (false);
	while (!!*string && !!*compare && *string == *compare)
		string += (++compare, 1);
	if (!*compare && !*string)
		return (true);
	return (false);
}
