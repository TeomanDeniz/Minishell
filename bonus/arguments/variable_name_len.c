/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_name_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:53:27 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 12:53:30 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int
	variable_name_len(char *input, int index)
{
	register char	save_char;
	int				result;

	result = 0;
	while (input[index + result])
	{
		save_char = input[index + result];
		if (!(save_char >= 'a' && save_char <= 'z') && \
			!(save_char >= 'A' && save_char <= 'Z') && \
			!(save_char >= '0' && save_char <= '9') && \
			save_char != '_')
			break ;
		result++;
	}
	return (result + 1);
}
