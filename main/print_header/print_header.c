/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:52:50 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/06 13:52:53 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/****************************************************************************\
|*                                                                          *|
|* Used Font: Slant Relief                                                  *|
|*        At: https://patorjk.com/software/taag/                            *|
|*                                                                          *|
\****************************************************************************/

#include "../main.h" /*
#typedef t_shell;
#*/
#include "print_header.h" /*
#   void a(t_shell, int);
#   void b(t_shell, int);
#   void c(t_shell, int);
#   void d(t_shell, int);
#   void e(t_shell, int);
#   void f(t_shell, int);
#*/
#include <unistd.h> /*
#ssize_t write(int, void *, size_t);
#*/

static void
	send_to_terminal_screen(t_shell shell, void (**x)(t_shell, int), int *len)
{
	register int	index;

	index = 0;
	while (index < 276)
	{
		x[index](shell, len[index]);
		++index;
	}
}

static void
	prepare_sizes(t_shell s, void (**x)(t_shell, int))
{
	int	*len;

	len = (int [276]){\
		8, 1, 9, 2, 1, 4, 12, 1, 4, 2, 1, 12, (s->ws_col - 107) + 15, 1, 3, \
		7, 1, 9, 5, 0, 1, 5, 1, 3, 8, 2, 0, 1, 6, 8, 1, 6, 1, 0, 1, 3, 8, \
		3, (s->ws_col - 107) + 11, 1, 5, 5, 1, 3, 7, 3, 3, 0, 2, 3, 1, 3, 1, \
		11, 0, 1, 3, 2, 3, 4, 1, 3, 2, 3, 1, 0, 1, 3, 6, 0, 2, 3, \
		(s->ws_col - 107) + 8, 1, 3, 1, 3, 4, 0, 3, 6, 0, 2, 3, 2, 0, 3, 2, 1, \
		3, 13, 0, 1, 4, 3, 3, 1, 3, 1, 1, 0, 1, 3, 1, 0, 1, 3, 7, 0, 1, 3, \
		(s->ws_col - 107) + 6, 1, 3, 1, 0, 1, 3, 14, 1, 3, 1, 3, 0, 4, 1, 0, \
		1, 3, 13, 0, 1, 3, 2, 0, 3, 3, 1, 3, 0, 1, 3, 1, 0, 1, 3, 7, 0, 1, 3, \
		(s->ws_col - 107) + 4, 1, 3, 1, 2, 0, 1, 3, 11, 1, 3, 2, 5, 0, 5, 1, \
		0, 2, 3, 12, 0, 1, 3, 4, 0, 3, 5, 0, 1, 3, 1, 0, 1, 3, 7, 0, 1, 3, \
		(s->ws_col - 107) + 2, 1, 16, 5, 1, 3, 2, 8, 0, 6, 2, 0, 3, 3, 10, 0, \
		1, 3, 13, 0, 1, 3, 1, 0, 1, 3, 7, 1, 3, (s->ws_col - 107) + 2, 0, 11, \
		3, 2, 4, 1, 3, 1, 11, 0, 7, 4, 0, 4, 9, 1, 0, 1, 3, 13, 0, 1, 3, 1, \
		0, 1, 12, 1, (s->ws_col - 107) + 13, 0, 1, 3, 5, 1, 15, 1, 0, 8, 7, \
		0, 9, 2, 0, 3, 14, 0, 3, 2, 0, 12, (s->ws_col - 107) + 15, 0, 3, 5, 0, \
		15, 2, 0};
	send_to_terminal_screen(s, x, len);
}

static void
	print_small_header(t_shell shell)
{
	register int	fd;

	fd = shell->std_out_fd;
	write(fd, "\n", 1);
	write(fd, "  ██████╗███╗   ███╗██████╗     ██╗  ██╗██████╗\n", 118);
	write(fd, " ██╔════╝████╗ ████║██╔══██╗    ██║  ██║╚════██╗\n", 129);
	write(fd, " ██║     ██╔████╔██║██║  ██║    ███████║ █████╔╝\n", 119);
	write(fd, " ██║     ██║╚██╔╝██║██║  ██║    ╚════██║██╔═══╝\n", 118);
	write(fd, " ╚██████╗██║ ╚═╝ ██║██████╔╝         ██║███████╗\n", 121);
	write(fd, "  ╚═════╝╚═╝     ╚═╝╚═════╝          ╚═╝╚══════╝\n\n", 112);
}

void
	print_header(t_shell shell)
{
	void	(**x)(t_shell, int);

	if (shell->ws_col < 106)
	{
		print_small_header(shell);
		return ;
	}
	x = (void (*[276])(t_shell, int)){\
		a, b, c, a, b, c, a, b, c, a, b, c, a, b, c, a, b, c, a, f, e, a, b, \
		c, b, a, d, b, c, a, b, c, a, d, b, c, b, c, a, b, c, a, b, c, b, c, \
		a, f, e, a, b, c, b, a, d, b, c, b, c, a, b, c, b, c, a, d, b, c, a, \
		d, b, c, a, b, c, b, c, a, d, b, a, d, b, c, a, f, e, a, b, c, a, d, \
		b, c, b, c, b, c, b, a, d, b, c, a, d, b, c, a, d, b, c, a, b, c, b, \
		d, b, c, a, b, c, b, a, f, e, a, d, b, c, a, d, b, c, a, d, b, c, b, \
		a, d, b, c, a, d, b, c, a, d, b, c, a, b, c, b, a, d, b, c, a, b, c, \
		b, a, f, e, a, d, b, c, a, d, b, c, a, d, b, a, d, b, c, a, d, b, c, \
		a, d, b, c, a, b, c, a, b, c, b, a, f, e, a, d, b, c, a, d, b, c, a, \
		d, b, c, a, d, b, c, a, b, c, a, d, b, c, b, a, b, c, b, a, f, e, a, \
		d, b, c, a, d, b, c, a, d, b, c, a, d, b, c, b, a, d, b, c, a, b, c, \
		a, f, e, a, d, b, a, d, b, a, d, b, a, d, b, a, d, b, a, d, b, a, f};
	prepare_sizes(shell, x);
	write(shell->std_out_fd, "\n", 1);
}
