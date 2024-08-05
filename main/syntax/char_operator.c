/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_operator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:21:46 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 17:21:47 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int
	char_operator(register char character)
{
	if (character == '<' || \
		character == '>' || \
		character == '|' || \
		character == ';')
		return (1);
	return (0);
}
