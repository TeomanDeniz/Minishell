/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_varaible_by_name.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:51:42 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 12:51:43 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#typedef t_shell;
#   char *get_variable(char *, t_shell);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

char
	*get_varaible_by_name(char *input, t_shell shell, int index)
{
	char			*result;
	char			save_char;
	register int	last_char_index;

	last_char_index = 1;
	while (input[index + last_char_index])
	{
		save_char = input[index + last_char_index];
		if (!(save_char >= 'a' && save_char <= 'z') && \
			!(save_char >= 'A' && save_char <= 'Z') && \
			!(save_char >= '0' && save_char <= '9') && \
			save_char != '_')
			break ;
		last_char_index++;
		save_char = input[index + last_char_index];
	}
	input[index + last_char_index] = 0;
	result = get_variable(&input[index + 1], shell);
	input[index + last_char_index] = save_char;
	return (result);
}
