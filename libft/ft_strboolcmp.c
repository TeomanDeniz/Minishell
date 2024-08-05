/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strboolcmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 22:23:25 by hdeniz            #+#    #+#             */
/*   Updated: 2024/08/01 15:17:56 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int
	ft_strboolcmp(const char *string, const char *compare)
{
	if (string == compare)
		return (1);
	if (!string || !compare)
		return (0);
	while (!!*string && !!*compare && *string == *compare)
		string += (++compare, 1);
	if (!*compare && !*string)
		return (1);
	return (0);
}
