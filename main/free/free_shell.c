/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:04:10 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/07 15:04:11 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#typedef t_shell;
#        */
#include "../../libft/libft.h" /*
#    int ft_safe_free(char **);
#    int ft_free_matrix(char ***);
#   void free_arg(t_shell);
#   void free_all_variables(t_shell);
#        */
#include <unistd.h> /*
#    int close(int);
#        */
#include <stdio.h> /*
#typedef FILE;
^------> <readline/readline.h>
#        */
#include <readline/readline.h> /*
@ <----- <stdio.h> REQUIRED
@ +----+ +------------+
@ |FLAG| | -lreadline |
@ +----+ +------------+
#   void rl_clear_history(void);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	free_shell(t_shell shell)
{
	if (!(shell->std_out_fd < 0))
		close(shell->std_out_fd);
	if (!(shell->histfile_fd < 0))
		close(shell->histfile_fd);
	rl_clear_history();
	shell->input = shell->org_input;
	ft_free_matrix(&shell->env);
	ft_safe_free(&shell->histfile);
	ft_safe_free(&shell->home);
	ft_safe_free(&shell->prompt);
	ft_safe_free(&shell->execute_program);
	free_arg(shell);
	free_all_variables(shell);
}
