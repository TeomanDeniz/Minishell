/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   there_is_slash_on_command.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:32:15 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 17:32:16 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdbool.h> /*
# define true;
# define false;
#typedef bool;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

bool
	there_is_slash_on_command(const char *const command)
{
	register int	index;

	index = -1;
	while (++index, !!command && !!command[index])
		if (command[index] == '/')
			return (true);
	return (false);
}
