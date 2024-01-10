/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_term_env_exist.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:02:36 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/07 18:02:36 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/****************************************************************************\
|*                                                                          *|
|* For checking if TERM variable is exist in (char **env) to get            *|
|* informations of terminal.                                                *|
|*                                                                          *|
\****************************************************************************/

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdbool.h> /*
#typedef bool;
# define true;
# define false;
*/
#include <term.h> /*
@ +----+ +-----------+
@ |FLAG| | -lncurses |
@ +----+ +-----------+
#    int tgetent(char *, char *);
#*/
#include <stdlib.h> /*
#   char *getenv(char *);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

bool
	check_term_env_exist(void)
{
	if (tgetent(NULL, getenv("TERM")) < 1)
		return (false);
	return (true);
}
