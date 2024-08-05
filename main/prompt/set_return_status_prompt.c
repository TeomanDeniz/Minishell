/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_return_status_prompt.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:33:51 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 14:33:52 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#typedef t_shell;
#        */
#include "../../libft/libft.h" /*
#   char ft_numindex(long , ushort);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	set_return_status_prompt(t_shell shell, int *prompt_index, char **ps)
{
	register int	index;
	char			number;

	index = 0;
	number = 1;
	while (!!number)
	{
		number = '0' + ft_numindex(shell->errorlevel, index);
		if (number == END_OF_NUMBER_INDEX)
			break ;
		shell->prompt[*prompt_index] = number;
		*prompt_index += 1;
		++index;
	}
	*ps += 2;
}
