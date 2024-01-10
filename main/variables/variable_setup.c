/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:16:35 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/07 16:16:35 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
# define MALLOC_ERROR;
# struct s_variable;
#typedef t_shell;
#typedef t_variable;
#   void error_shell(t_shell, char *, int, char *);
#*/
#include <stdlib.h> /*
#   void *malloc(size_t);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	variable_setup(t_shell shell)
{
	shell->variable = (t_variable) malloc(sizeof(struct s_variable));
	if (!shell->variable)
		error_shell(shell, MALLOC_ERROR, (__LINE__ - 2), "malloc()");
	shell->variable->name = NULL;
	shell->variable->value = NULL;
	shell->variable->next = NULL;
}
