/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 21:37:22 by hdeniz            #+#    #+#             */
/*   Updated: 2024/08/01 15:17:56 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "libft.h" /*
#    int ft_safe_free(char **);
#        */
#include <stdlib.h> /*
#   void free(void *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

int
	ft_free_matrix(char ***matrix)
{
	register int	y;

	if (!matrix || !*matrix)
		return (1);
	y = -1;
	while (++y, !!(*matrix)[y])
		ft_safe_free(&(*matrix)[y]);
	free(*matrix);
	*matrix = (char **)0;
	return (1);
}
