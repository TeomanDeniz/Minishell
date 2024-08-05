/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:54:38 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 12:54:39 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdbool.h> /*
# define true;
# define false;
#typedef bool;
#*/
#include "../main.h" /*
#typedef t_shell;

#*/
/* **************************** [^] INCLUDES [^] **************************** */

bool
	dollar_valid(t_shell shell, int index)
{
	register char	character;

	character = shell->input[index + 1];
	if (!!character)
		if ((character >= 'a' && character <= 'z') || character == '?' || \
			((character >= 'A' && character <= 'Z')) || character == '_')
			return (true);
	return (false);
}
