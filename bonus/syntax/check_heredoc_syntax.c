/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_heredoc_syntax.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:31:31 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 17:31:31 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdbool.h> /*
# define true;
# define false;
#typedef bool;
#*/
#include "../../libft/libft.h" /*
#   bool ft_strboolcmp(char *, char *);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

bool
	check_heredoc_syntax(const char *const input)
{
	if (ft_strboolcmp(input, "<<") || ft_strboolcmp(input, "<"))
		return (true);
	return (false);
}
