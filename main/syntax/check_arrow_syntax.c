/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arrow_syntax.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:28:46 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 17:28:46 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdbool.h> /*
# define true;
# define false;
#typedef bool;
#*/
#include "../main.h" /*
#   bool check_heredoc_syntax(char *);
#   bool check_outpend_syntax(char *);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

bool
	check_arrow_syntax(const char *const input)
{
	if (check_outpend_syntax(input) || check_heredoc_syntax(input))
		return (true);
	return (false);
}
