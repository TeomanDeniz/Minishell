/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   werror_shell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:00:52 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/07 15:00:53 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../../libft/libft.h" /*
#   void ft_putnbr_fd(int, int);
#    int ft_strlen(char *);
#*/
#include "../main.h" /*
#typedef t_shell;
#   char *get_variable(char *, t_shell);
#*/
#include <unistd.h> /*
#ssize_t write(int, void *, size_t);
*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	werror_shell(t_shell shell, char *note, int line, char *from)
{
	char	*cmd42_name;

	cmd42_name = get_variable("CMD42_NAME", shell);
	if (!!line)
	{
		write(shell->std_out_fd, " at [", 4);
		ft_putnbr_fd(line, shell->std_out_fd);
		write(shell->std_out_fd, "] ", 2);
	}
	write(shell->std_out_fd, "-", 1);
	write(shell->std_out_fd, cmd42_name, ft_strlen(cmd42_name));
	write(shell->std_out_fd, ": `", 3);
	write(shell->std_out_fd, from, ft_strlen(from));
	write(shell->std_out_fd, "': ", 3);
	if (!!note)
	{
		write(shell->std_out_fd, note, ft_strlen(note));
		write(shell->std_out_fd, "\n", 1);
	}
}
