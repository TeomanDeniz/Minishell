/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_input_ctrl_c_bypass.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:14:11 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/07 18:14:11 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdio.h> /*
# define EOF;
# struct FILE;
#*/
#include <unistd.h> /*
# define STDIN_FILENO;
#ssize_t read(int, void *, size_t);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

int
	rd_input_ctrl_c_bypass(FILE *stream)
{
	static char	buffer[1];
	static char	*buffer_ptr = buffer;
	static int	buffer_size = 0;

	(void)stream;
	if (buffer_size <= 0)
	{
		buffer_size = read(STDIN_FILENO, buffer, 1);
		buffer_ptr = buffer;
		if (buffer_size <= 0)
			return (EOF);
	}
	buffer_size--;
	return (*buffer_ptr++);
}
