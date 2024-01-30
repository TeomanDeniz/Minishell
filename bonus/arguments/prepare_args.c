/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:31:17 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/08 23:31:18 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
# define MALLOC_ERROR;
# struct s_arg;
# struct s_operator;
#typedef t_shell;
#    int arg_counter(t_shell);
#   void error_shell(t_shell, char *, int, char *);
#    int arg_strlen(t_shell, char *);
#   bool char_operator(char);
#   void fill_the_argument(t_shell, int);
#   void fill_the_operator(t_shell, int);
#*/
#include <stdlib.h> /*
#   void *malloc(size_t);
#*/
#include <stdbool.h> /*
# define false;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	prepare_args(t_shell shell)
{
	register int	index;
	register int	arg_len;

	arg_len = arg_counter(shell);
	shell->arg = (struct s_arg *) malloc(sizeof(struct s_arg) * (arg_len + 2));
	if (!shell->arg)
		error_shell(shell, MALLOC_ERROR, (__LINE__ - 2), "malloc()");
	shell->operator = (struct s_operator){false, false, false};
	index = 0;
	while (index < arg_len)
	{
		shell->arg[index].this = (char *) malloc(sizeof(char) * \
			(arg_strlen(shell, shell->input) + 2));
		if (!shell->arg[index].this)
			error_shell(shell, MALLOC_ERROR, (__LINE__ - 3), "malloc()");
		shell->arg[index].operator = false;
		if (!char_operator(*shell->input))
			fill_the_argument(shell, index);
		else
			fill_the_operator(shell, index);
		++index;
	}
	shell->arg[index] = (struct s_arg){NULL, 0};
	shell->arg[index + 1] = (struct s_arg){NULL, 0};
	shell->input = shell->org_input;
}
