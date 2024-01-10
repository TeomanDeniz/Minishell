/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 21:52:28 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/06 21:52:30 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/****************************************************************************\
|*                                                                          *|
|* No need to use ft_calloc here because we're already filling the inside   *|
|* of the allocated string. Optimisation*                                   *|
|*                                                                          *|
\****************************************************************************/

/* **************************** [v] INCLUDES [v] **************************** */
#include "libft.h" /*
#    int ft_strlen(char *);
*/
#include <stdlib.h> /*
#   void *malloc(size_t);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

char
	*ft_strdup(const char *const string)
{
	char			*result;
	register int	index;

	if (!string)
		return (NULL);
	result = (char *) malloc(sizeof(char) * (ft_strlen(string) + 1));
	if (!result)
		return (NULL);
	index = -1;
	while (++index, string[index])
		result[index] = string[index];
	result[index] = 0;
	return (result);
}
