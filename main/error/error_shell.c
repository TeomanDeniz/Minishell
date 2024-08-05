/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:42:32 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/07 14:42:33 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#typedef t_shell;
#   void free_shell(t_shell);
#   void perror_shell(t_shell, char *, int, char *);
#        */
#include <stdlib.h> /*
#   void exit(int);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	error_shell(t_shell shell, char *note, int line, char *from)
{
	perror_shell(shell, note, line, from);
	free_shell(shell);
	exit(1);
}
