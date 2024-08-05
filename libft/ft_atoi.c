/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:37:50 by hdeniz            #+#    #+#             */
/*   Updated: 2024/08/01 15:17:56 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int
	ft_atoi(const char *const string)
{
	register int	counter;
	register int	sign;
	int				result;

	counter = 0;
	sign = 0;
	result = 0;
	while (string[counter] == ' ' || \
		string[counter] == '\t' || string[counter] == '\v' || \
		string[counter] == '\f' || string[counter] == '\r')
		++counter;
	if (string[counter] == '-' || string[counter] == '+')
		if (++counter, string[counter - 1] == '-')
			sign = 1;
	--counter;
	while (++counter, string[counter] >= '0' && string[counter] <= '9')
		result = (result * 10) + (string[counter] & 15);
	if (sign)
		result = (~(result) + 1);
	return (result);
}
