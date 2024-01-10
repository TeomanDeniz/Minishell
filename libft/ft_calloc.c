/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:36:15 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/06 18:36:17 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "libft.h" /*
#   void ft_bzero(char *, int);
#*/
#include <stdlib.h> /*
#   void *malloc(size_t);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	*ft_calloc(unsigned int type_size, unsigned int size)
{
	register unsigned int	total_memory_size;
	void					*result;

	total_memory_size = type_size * size;
	result = malloc(total_memory_size);
	if (!result)
		return (NULL);
	ft_bzero(result, total_memory_size);
	return (result);
}
