/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 21:37:22 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/06 21:37:23 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "libft.h" /*
#   bool ft_safe_free(char **);
#*/
#include <stdlib.h> /*
#   void free(void *);
#*/
#include <stdbool.h> /*
#typedef bool;
# define true;
*/
/* **************************** [^] INCLUDES [^] **************************** */

bool
	ft_free_matrix(char ***matrix)
{
	register int	y;

	if (!matrix || !*matrix)
		return (true);
	y = -1;
	while (++y, !!(*matrix)[y])
		ft_safe_free(&(*matrix)[y]);
	free(*matrix);
	*matrix = NULL;
	return (true);
}
