/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_whitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:25:36 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 17:25:37 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int
	char_whitespace(register char character)
{
	if (character == ' ' || \
		character == '\t' || \
		character == '\v' || \
		character == '\f' || \
		character == '\r')
		return (1);
	return (0);
}
