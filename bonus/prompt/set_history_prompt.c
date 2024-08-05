/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_history_prompt.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:52:59 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 16:53:00 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#typedef t_shell;
#*/
#include "../../libft/libft.h" /*
# define END_OF_NUMBER_INDEX;
#   char ft_numindex(long long , Ushort);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	set_history_prompt(t_shell shell, int *prompt_index, char **ps)
{
	register int	index;
	char			number;

	index = 0;
	number = 1;
	while (!!number)
	{
		number = '0' + ft_numindex(shell->history_number_of_commands, \
			index);
		if (number == END_OF_NUMBER_INDEX)
			break ;
		shell->prompt[*prompt_index] = number;
		*prompt_index += 1;
		++index;
	}
	*ps += 2;
}
