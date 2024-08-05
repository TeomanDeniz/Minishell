/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 22:39:43 by hdeniz            #+#    #+#             */
/*   Updated: 2024/08/01 15:17:56 by hdeniz           ###   ########.fr       */
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
#        */
#include <stdlib.h> /*
#   void *malloc(size_t);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

char
	*ft_substr(char const *string, unsigned int start, unsigned int len)
{
	register unsigned int	string_size;
	register unsigned int	ecx;
	char					*result;

	string_size = ft_strlen(string);
	if (!string || start > len || start > string_size)
		return (NULL);
	if (len > string_size)
		len = string_size;
	result = (char *) malloc(sizeof(char) * (len - start + 1));
	if (!result)
		return (NULL);
	ecx = 0;
	while (string[start])
	{
		if (ecx >= len)
			break ;
		result[ecx] = string[start];
		++ecx;
		++start;
	}
	result[ecx] = 0;
	return (result);
}
