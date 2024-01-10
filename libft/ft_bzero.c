/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:51:31 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/06 18:51:32 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void
	ft_bzero(char *const buffer, register int size)
{
	register int	index;

	index = -1;
	while (++index, index < size)
		buffer[index] = 0;
}
