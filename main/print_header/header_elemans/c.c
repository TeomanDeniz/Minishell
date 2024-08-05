/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:00:34 by hdeniz            #+#    #+#             */
/*   Updated: 2023/11/12 18:00:35 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../print_header.h" /*
# define COLOR_C
#   void write_color_f(int, char *, char *);
#        */
#include "../../main.h" /*
#typedef t_shell;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	c(t_shell shell, int len)
{
	while (!!len)
	{
		write_color_f(shell->std_out_fd, "\\", COLOR_C);
		--len;
	}
}
