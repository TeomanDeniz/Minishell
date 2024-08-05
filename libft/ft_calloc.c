/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:36:15 by hdeniz            #+#    #+#             */
/*   Updated: 2024/08/01 15:17:56 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdlib.h> /*
#   void *malloc(size_t);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	*ft_calloc(unsigned int type_size, unsigned int size)
{
	register unsigned int	total_memory_size;
	void					*result;

	total_memory_size = type_size * size;
	result = malloc(total_memory_size);
	if (!result)
		return ((void *)0);
	while (--total_memory_size)
		((char *)result)[total_memory_size] = 0;
	return (result);
}
