/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_here_doc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:56:14 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 17:56:15 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
# struct s_operator;
#typedef t_shell;
#typedef t_operator;
#   void just_handle_signal(int);
#    int rd_input_ctrl_c_bypass(FILE *);
#   void reset_here_doc_operator(char *, t_operator);
#   char *get_variable(char *, t_shell);
#        */
#include <signal.h> /*
# define SIGINT
#   void (*signal(int, void (*)(int)))(int);
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
#typedef rl_getc_function();
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ char	*return_prompt(t_shell shell, \
struct s_operator operator);
/* *************************** [^] PROTOTYPES [^] *************************** */

char
	*prepare_here_doc(t_shell shell, t_operator operator)
{
	signal(SIGINT, just_handle_signal);
	rl_getc_function = rd_input_ctrl_c_bypass;
	reset_here_doc_operator(shell->input, operator);
	return (return_prompt(shell, *operator));
}

extern __inline__ char
	*return_prompt(t_shell shell, struct s_operator operator)
{
	if (operator.pipe)
		return (get_variable("PS5", shell));
	if (operator.double_quote)
		return (get_variable("PS2", shell));
	if (operator.single_quote)
		return (get_variable("PS3", shell));
	return (get_variable("PS4", shell));
}