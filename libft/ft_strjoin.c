/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 21:44:58 by hdeniz            #+#    #+#             */
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
#   char *ft_strdup(char *);
#        */
#include <stdlib.h> /*
#   void *malloc(size_t);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

char
	*ft_strjoin(char const *s1, char const *s2)
{
	char			*result;
	register int	index;
	register int	s1_len;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	s1_len = ft_strlen(s1);
	result = (char *) malloc(sizeof(char) * (s1_len + ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	index = -1;
	while (++index, s1[index])
		result[index] = s1[index];
	index = -1;
	while (++index, s2[index])
		result[s1_len + index] = s2[index];
	result[s1_len + index] = 0;
	return (result);
}
