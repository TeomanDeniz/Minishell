/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_row_and_col_variables.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:00:37 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/07 16:00:38 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
# define TERM_ROW;
# define TERM_COL;
#typedef t_shell;
#typedef t_converter;
#   void set_variable(char *, char *, t_shell);
#   void set_var_by_int(char *, int, t_shell);
#*/
#include <sys/ioctl.h> /*
# define TIOCGWINSZ;
#    int ioctl(int, Ulong, ...);
#*/
#include <unistd.h> /*
# define STDOUT_FILENO;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
static t_shell	save_shell_struct(int counter, int signal);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	update_row_and_col_variables(int signal)
{
	struct winsize	window_size;
	static t_shell	shell = NULL;
	static char		counter = 0;

	if (counter < 2)
	{
		shell = save_shell_struct(counter, signal);
		++counter;
		return ;
	}
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &window_size);
	shell->ws_row = window_size.ws_row;
	shell->ws_col = window_size.ws_col;
	set_var_by_int(TERM_ROW, shell->ws_row, shell);
	set_var_by_int(TERM_COL, shell->ws_col, shell);
}

static t_shell
	save_shell_struct(int counter, int signal)
{
	t_converter				converter;
	static unsigned long	struct_address = 0U;

	if (counter == 0)
	{
		struct_address = signal;
		struct_address = struct_address << 32;
		return (NULL);
	}
	else
	{
		struct_address = struct_address + (unsigned)signal;
		converter.ul_var = struct_address;
		return ((t_shell)converter.p_var);
	}
}
