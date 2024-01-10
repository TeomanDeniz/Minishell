/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:40:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/06 18:40:04 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int
	ft_strlen(const char *const string)
{
	int	ecx;

	ecx = 0;
	if (!string)
		return (0);
	while (!!string[ecx])
		++ecx;
	return (ecx);
}