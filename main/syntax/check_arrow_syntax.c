/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arrow_syntax.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:28:46 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 17:28:46 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#    int check_heredoc_syntax(char *);
#    int check_outpend_syntax(char *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

int
	check_arrow_syntax(const char *const input)
{
	if (check_outpend_syntax(input) || check_heredoc_syntax(input))
		return (1);
	return (0);
}
