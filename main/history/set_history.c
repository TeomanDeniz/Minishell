/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_history.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:07:49 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/07 16:07:50 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
# define MALLOC_ERROR;
#typedef t_shell;
#   void error_shell(t_shell, char *, int, char *);
#   void werror_shell(t_shell, char *, int, char *);
#   void env_to_variable(t_shell, char **);
#   char *get_variable_direct_value(char *, t_shell);
#   char *get_variable(char *, t_shell);
#   void set_variable(char *, char *, t_shell);
#   void set_readline_history(t_shell);
#*/
#include <unistd.h> /*
# define F_OK;
# define R_OK;
# define X_OK;
#    int access(char *, int);
#*/
#include <stdbool.h> /*
#typedef bool;
# define false;
# define true;
#*/
#include "../../libft/libft.h" /*
#   char *get_next_line(int);
#   void *ft_calloc(uint, uint);
#    int ft_strlen(char *);
#*/
#include <fcntl.h> /*
# define O_RDONLY;
#    int open(char *, int, ...);
#*/
#include <stdio.h> /*
#typedef FILE;
^------> <readline/readline.h>
*/
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

}
