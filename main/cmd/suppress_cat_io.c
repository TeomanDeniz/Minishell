/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suppress_cat_io.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:20:20 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/07 18:20:21 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/****************************************************************************\
|*                                                                          *|
|* This function is for restrict the inputs in terminal such as arrow keys, *|
|* enter, esc and many other special characters to be work in the terminal. *|
|*                                                                          *|
|*..........................................................................*|
|*: TCSANOW : The changes are occurs immediately on tcsetattr() function.  :*|
|*:.........:..............................................................:*|
|*: ECHOCTL : Disable terminal special inputs.                             :*|
|*:.........:..............................................................:*|
\****************************************************************************/

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdbool.h> /*
#typedef bool;
*/
#include <termios.h> /*
# define ECHOCTL;
# define TCSANOW;
# struct termios;
#    int tcsetattr(int, int, struct termios *);
#    int tcgetattr(int, struct termios *);
*/
#include <unistd.h> /*
# define STDOUT_FILENO;
#ssize_t write(int, void *, size_t);
#    int dup(int);
#*/
#include "../main.h" /*
# define CMD42_NAME;
#*/
#include <stdio.h> /*
#   void perror(char *);
#*/
#include "../../libft/libft.h" /*
#    int ft_strlen(char *);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	suppress_cat_io(bool echo_ctrl_character)
{
	static int		fd = 0;
	struct termios	termios_p;

	if (fd == 0)
		fd = dup(STDOUT_FILENO);
	if (tcgetattr(fd, &termios_p) != 0)
	{
		write(1, CMD42_NAME, ft_strlen(CMD42_NAME));
		write(1, ": ", 2);
		perror("tcgetattr");
		return ;
	}
	termios_p.c_lflag &= ~ECHOCTL;
	if (echo_ctrl_character)
		termios_p.c_lflag |= ECHOCTL;
	if (tcsetattr(fd, TCSANOW, &termios_p) != 0)
	{
		write(1, CMD42_NAME, ft_strlen(CMD42_NAME));
		write(1, ": ", 2);
		perror("tcsetattr");
	}
}
