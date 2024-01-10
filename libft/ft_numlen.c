/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 21:41:23 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/06 21:41:26 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned short
	ft_numlen(register long long number)
{
	unsigned short	result;

	if (number < 0LL)
		number = ((~number) + 1LL);
	if (number == 0LL)
		return ((short)1);
	result = -1;
	while (++result, !!number)
		number = number / 10LL;
	return (result);
}
