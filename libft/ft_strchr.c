/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 22:38:49 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/06 22:38:50 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char const
	*ft_strchr(char const *string, register int character)
{
	if (!string)
		return ((void *)0);
	while ((*string != '\0') && (*string != character))
		string++;
	if (*string == character)
		return (string);
	return ((void *)0);
}
