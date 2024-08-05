/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:04:29 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/07 18:04:30 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#    int check_term_env_exist(void);
#        */
#include <term.h> /*
@ +----+ +-----------+
@ |FLAG| | -lncurses |
@ +----+ +-----------+
#   char *tgetstr(char [2], char **);
#    int tputs(char *, int, int (*)(int));
#        */
#include <stdlib.h> /*
#   char *getenv(char *);
#        */
#include <unistd.h> /*
# define STDOUT_FILENO
#ssize_t write(int, void *, size_t);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ int	ft_putchar(int character);
/* *************************** [^] PROTOTYPES [^] *************************** */

int
	move_cursor_up(void)
{
	char	*up;

	if (!check_term_env_exist())
		return (0);
	up = tgetstr("up", ((void *)0));
	if (!!up)
		tputs(up, 1, ft_putchar);
	return (1);
}

extern __inline__ int
	ft_putchar(int character)
{
	write(STDOUT_FILENO, &character, 1);
	return (character);
}
