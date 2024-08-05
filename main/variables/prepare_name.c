/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_name.c                                     :+:      :+:    :+:   */
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
	prepare_name(char **name, const char *const env)
{
	register int	index;

	index = 0;
	while (!!env && !!env[index] && env[index] != '=')
		++index;
	*name = (char *) ft_calloc(sizeof(char), index + 1);
	if (!(*name))
		return ;
	index = -1;
	while (++index, !!env && !!env[index] && env[index] != '=')
		(*name)[index] = env[index];
	(*name)[index] = 0;
}
