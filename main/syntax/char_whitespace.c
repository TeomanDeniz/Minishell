/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_whitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:25:36 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 17:25:37 by hdeniz           ###   ########.fr       */
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
	char_whitespace(register char character)
{
	if (character == ' ' || \
		character == '\t' || \
		character == '\v' || \
		character == '\f' || \
		character == '\r')
		return (true);
	return (false);
}
