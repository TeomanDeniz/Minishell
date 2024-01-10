/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 22:25:26 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/06 22:25:27 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char
	ft_strcmp(const char *string, const char *compare)
{
	if (string == compare)
		return (0);
	if (!string || !compare)
		return (1);
	while (*string == *compare && *string != '\0' && *compare != '\0')
		string += (++compare, 1);
	return (*string - *compare);
}
