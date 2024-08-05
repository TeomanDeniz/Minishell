/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:00:34 by hdeniz            #+#    #+#             */
/*   Updated: 2023/11/12 18:00:35 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../print_header.h" /*
# define COLOR_D;
#   void write_color_f(int, char *, char *);
#*/
#include "../../main.h" /*
#typedef t_shell;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	d(t_shell shell, int len)
{
	(void)len;
	write_color_f(shell->std_out_fd, "\\", COLOR_D);
}
