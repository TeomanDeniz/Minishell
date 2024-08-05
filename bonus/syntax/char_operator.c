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

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#   bool check_brackets(char);
#*/
#include <stdbool.h> /*
# define true;
# define false;
#typedef bool;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

bool
	char_operator(register char character)
{
	if (character == '<' || \
		character == '>' || \
		character == '|' || \
		character == '&' || \
		character == ';' || \
		check_brackets(character))
		return (true);
	return (false);
}
