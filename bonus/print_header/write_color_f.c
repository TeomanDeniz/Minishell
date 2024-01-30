/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_color_f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:53:12 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/06 13:53:14 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../../libft/libft.h" /*
#    int ft_strlen(char *);
#*/
#include <unistd.h> /*
#ssize_t write(int, void *, size_t);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	write_color_f(int fd, char *text, char *color)
{
	write(fd, "\033[38;5;", 7);
	write(fd, color, ft_strlen(color));
	write(fd, "m", 1);
	write(fd, text, ft_strlen(text));
	write(fd, "\033[0m", 4);
}
