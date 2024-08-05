/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_heredoc_syntax.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:31:31 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 17:31:31 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../../libft/libft.h" /*
#    int ft_strboolcmp(char *, char *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

int
	check_heredoc_syntax(const char *const input)
{
	if (ft_strboolcmp(input, "<<") || ft_strboolcmp(input, "<"))
		return (1);
	return (0);
}
