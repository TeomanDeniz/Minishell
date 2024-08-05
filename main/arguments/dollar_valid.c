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
#include "../main.h" /*
#typedef t_shell;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

int
	dollar_valid(t_shell shell, register int index)
{
	register char	character;

	character = shell->input[index + 1];
	if (!!character)
		if ((character >= 'a' && character <= 'z') || character == '?' || \
			((character >= 'A' && character <= 'Z')) || character == '_')
			return (1);
	return (0);
}
