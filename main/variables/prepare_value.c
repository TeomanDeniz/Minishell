/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:25:09 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/07 16:25:10 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../../libft/libft.h" /*
#   void *ft_calloc(uint, uint);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	prepare_value(char **value, char *env)
{
	register int	index;

	while (!!env && !!*env && *env != '=')
		env += 1;
	if (!*env)
	{
		*value = ((void *)0);
		return ;
	}
	if (*env == '=')
		env += 1;
	index = 0;
	while (!!env && !!env[index] && env[index])
		++index;
	*value = (char *) ft_calloc(sizeof(char), index + 1);
	if (!(*value))
		return ;
	index = -1;
	while (++index, !!env && !!env[index] && env[index])
		(*value)[index] = env[index];
	(*value)[index] = 0;
}
