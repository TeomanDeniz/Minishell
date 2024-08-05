/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:34:16 by hdeniz            #+#    #+#             */
/*   Updated: 2024/08/01 15:17:56 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "libft.h" /*
#   void ft_putchar_fd(char, int);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	ft_putnbr_fd(int number, int fd)
{
	long	write_number;

	write_number = (long)number;
	if (write_number < 0)
	{
		write_number = (~(write_number) + 1);
		ft_putchar_fd('-', fd);
	}
	if (write_number >= 10)
	{
		ft_putnbr_fd(write_number / 10, fd);
		ft_putnbr_fd(write_number % 10, fd);
	}
	else
		if (fd >= 0)
			ft_putchar_fd(write_number + 48, fd);
}
