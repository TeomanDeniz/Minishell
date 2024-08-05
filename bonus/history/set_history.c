/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_history.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:07:49 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/07 16:07:50 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#typedef t_shell;
#*/
#include "../../libft/libft.h" /*
#    int ft_strlen(char *);
#*/
#include <unistd.h> /*
#ssize_t write(int, void *, size_t);
#*/
#include <stdio.h> /*
#typedef FILE;
^------> <readline/history.h>
#*/
#include <readline/history.h> /*
@ <----- <stdio.h> REQUIRED
@ +----+ +------------+
@ |FLAG| | -lreadline |
@ +----+ +------------+
#   void add_history(char *);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	set_history(t_shell shell)
{
	if (!shell->input)
		return ;
	add_history(shell->input);
	if (shell->histfile_fd < 0)
		return ;
	write(shell->histfile_fd, shell->input, ft_strlen(shell->input));
	write(shell->histfile_fd, "\n", 1);
	shell->history_number_of_commands++;
}
