/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_var_by_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:02:18 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/07 17:02:18 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#typedef t_shell;
#   void set_variable(char *, char *, t_shell);
#*/
#include "../../libft/libft.h" /*
# define END_OF_NUMBER_INDEX;
#   char ft_numindex(long long, short);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	set_var_by_int(char *name, int x, t_shell shell)
{
	register int	number;
	register short	index;
	char			result[16];

	index = -1;
	while (++index, index < 16)
	{
		number = 48 + ft_numindex(x, index);
		if (number == END_OF_NUMBER_INDEX)
			break ;
		result[index] = number;
	}
	result[index] = 0;
	set_variable(name, result, shell);
}
