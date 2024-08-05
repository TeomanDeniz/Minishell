/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:00:34 by hdeniz            #+#    #+#             */
/*   Updated: 2023/11/12 18:00:35 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../print_header.h" /*
# define COLOR_A
#   void write_color_f(int, char *, char *);
#        */
#include "../../main.h" /*
#typedef t_shell;
#        */
#include <unistd.h> /*
#ssize_t write(int, void *, size_t);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	a(t_shell shell, int len)
{
	while (!!len)
	{
		write(shell->std_out_fd, "\e[5m", 5);
		write_color_f(shell->std_out_fd, "_", COLOR_A);
		--len;
	}
}
