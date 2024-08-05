/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 22:26:26 by hdeniz            #+#    #+#             */
/*   Updated: 2024/08/01 15:17:56 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/****************************************************************************\
|*                                                                          *|
|* Returns a number that you want from a number by index.                   *|
|*                                                                          *|
|* ft_numindex(29381, 0) = 2                                                *|
|*             ^------^                                                     *|
|* ft_numindex(29381, 1) = 9                                                *|
|*              ^-----^                                                     *|
|* ft_numindex(29381, 2) = 3                                                *|
|*               ^----^                                                     *|
|* ft_numindex(29381, 3) = 8                                                *|
|*                ^---^                                                     *|
|* ft_numindex(29381, 4) = 1                                                *|
|*                 ^--^                                                     *|
|* ft_numindex(29381, 5) = -1                                               *|
|*                    x                                                     *|
|*                                                                          *|
\****************************************************************************/

/* **************************** [v] INCLUDES [v] **************************** */
#include "libft.h" /*
#  short ft_numlen(long);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

char
	ft_numindex(long number, register unsigned short index)
{
	register unsigned short	position;
	register unsigned short	number_width;

	if (number < (long)0)
		number = ((~number) + (long)1);
	if (!number)
		return (0 - !!index);
	number_width = ft_numlen(number);
	if (index >= number_width)
		return (-1);
	position = number_width - index;
	while (--position, position > 0)
		number /= (long)10;
	return ((char)(number % (long)10));
}
