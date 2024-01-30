/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:04:29 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/07 18:04:30 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#   bool check_term_env_exist(void);
#*/
#include <stdbool.h> /*
#typedef bool;
# define true;
# define false;
*/
#include <term.h> /*
@ +----+ +-----------+
@ |FLAG| | -lncurses |
@ +----+ +-----------+
#   char *tgetstr(char [2], char **);
#    int tputs(char *, int, int (*)(int));
#*/
#include <stdlib.h> /*
#   char *getenv(char *);
#*/
#include <unistd.h> /*
# define STDOUT_FILENO;
#ssize_t write(int, void *, size_t);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
static int	ft_putchar(int character);
/* *************************** [^] PROTOTYPES [^] *************************** */

bool
	move_cursor_up(void)
{
	char	*up;

	if (!check_term_env_exist())
		return (false);
	up = tgetstr("up", NULL);
	if (!!up)
		tputs(up, 1, ft_putchar);
	return (true);
}

static int
	ft_putchar(int character)
{
	write(STDOUT_FILENO, &character, 1);
	return (character);
}
