/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:37:50 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/06 18:37:52 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdbool.h> /*
#typedef bool;
# define true;
# define false;
*/
/* **************************** [^] INCLUDES [^] **************************** */

int
	ft_atoi(const char *const string)
{
	register int	counter;
	bool			sign;
	int				result;

	counter = 0;
	sign = false;
	result = 0;
	while (string[counter] == ' ' || \
		string[counter] == '\t' || \
		string[counter] == '\v' || \
		string[counter] == '\f' || \
		string[counter] == '\r')
		counter++;
	if (string[counter] == '-' || string[counter] == '+')
		if (++counter, string[counter - 1] == '-')
			sign = true;
	--counter;
	while (++counter, string[counter] >= '0' && string[counter] <= '9')
		result = (result * 10) + (string[counter] & 15);
	if (sign)
		result = (~(result) + 1);
	return (result);
}
