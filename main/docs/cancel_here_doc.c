/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cancel_here_doc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:02:01 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 18:02:02 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
# define UNEX_EOF_MATCH
# define UNEX_END_FILE
G >>>>>> (sig_atomic_t)
G ^^^^^^ g_signal;
# struct s_operator;
#typedef t_shell;
#   bool check_term_env_exist(void);
#   char *get_variable(char *, t_shell);
#        */
#include <stdio.h> /*
#typedef FILE;
^------> <readline/readline.h>
#    int printf(char *, ...);
#        */
#include <readline/readline.h> /*
@ <----- <stdio.h> REQUIRED
@ +----+ +------------+
@ |FLAG| | -lreadline |
@ +----+ +------------+
#typedef rl_getc_function();
#        */
#include <signal.h> /*
# define SIGINT
#   void (*signal(int, void (*)(int)))(int);
#        */
#include <unistd.h> /*
#ssize_t write(int, void *, size_t);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	cancel_here_doc(t_shell shell, struct s_operator operator)
{
	rl_getc_function = shell->original_rl_getc_function;
	shell->errorlevel = 1U;
	signal(SIGINT, handle_sigint);
	shell->fix_extra_fucking_newline = 1;
	if (!check_term_env_exist())
		write(shell->std_out_fd, "\n", 1);
	if (g_signal == SIGINT)
		return ;
	if (operator.double_quote || operator.single_quote)
	{
		if (operator.double_quote)
			printf(UNEX_EOF_MATCH, get_variable("CMD42_NAME", shell), '\"');
		if (operator.single_quote)
			printf(UNEX_EOF_MATCH, get_variable("CMD42_NAME", shell), '\'');
		printf(UNEX_END_FILE, get_variable("CMD42_NAME", shell));
		g_signal = SIGINT;
		shell->errorlevel = (unsigned int)258;
	}
}
