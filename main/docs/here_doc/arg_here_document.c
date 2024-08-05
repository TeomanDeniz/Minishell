/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_here_document.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:22:58 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 18:22:59 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../../main.h" /*
# define MALLOC_ERROR
G >>>>>> (sig_atomic_t)
G ^^^^^^ g_signal;
# struct s_operator;
#typedef t_shell;
#   void error_shell(t_shell, char *, int, char *);
#   void prompt_preparer(t_shell, char *);
#   char *prepare_here_doc(t_shell, t_operator);
#    int dollar_is_valid(char *);
#   void replace_dollar_with_value(char **, t_shell);
#        */
#include "../../../libft/libft.h" /*
#   char *ft_strdup(char *);
#    int ft_safe_free(char **);
#   void *ft_calloc(Uint, Uint);
#    int ft_strlen(char *);
#    int ft_strboolcmp(char *, char *);
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
#   char *readline(char *);
#        */
#include <signal.h> /*
# define SIGINT
#   void (*signal(int, void (*)(int)))(int);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ int	join_heredoc(char **this, char *input);
extern __inline__ int	arg_here_document_loop(t_shell shell, char **heredoc, \
register int index);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	arg_here_document(t_shell shell, int index)
{
	char	*heredoc;

	heredoc = ft_strdup(shell->arg[index].this);
	if (!heredoc)
		error_shell(shell, MALLOC_ERROR, (__LINE__ - 2), "ft_strdup()");
	ft_safe_free(&shell->arg[index].this);
	shell->arg[index].this = (char *) ft_calloc(sizeof(char), 2);
	if (!shell->arg[index].this && ft_safe_free(&heredoc))
		error_shell(shell, MALLOC_ERROR, (__LINE__ - 2), "ft_calloc()");
	shell->arg[index].this[0] = 0;
	while (1)
		if (!arg_here_document_loop(shell, &heredoc, index))
			break ;
	ft_safe_free(&heredoc);
	rl_getc_function = shell->original_rl_getc_function;
	signal(SIGINT, handle_sigint);
}

extern __inline__ int
	join_heredoc(char **this, char *input)
{
	char			*temp;
	register int	index;
	register int	input_index;

	temp = ft_strdup(*this);
	if (!temp)
		return (0);
	ft_safe_free(this);
	(*this) = (char *) ft_calloc(sizeof(char), ft_strlen(temp) + \
		ft_strlen(input) + 1);
	if (!(*this))
	{
		(*this) = temp;
		return (0);
	}
	index = -1;
	input_index = -1;
	while (++index, ++input_index, !!temp[index])
		(*this)[input_index] = temp[index];
	index = (ft_safe_free(&temp), --input_index, -1);
	while (++input_index, ++index, !!input[index])
		(*this)[input_index] = input[index];
	(*this)[input_index] = 0;
	return (1);
}

extern __inline__ int
	arg_here_document_loop(t_shell shell, char **heredoc, register int index)
{
	char	*input;

	prompt_preparer(shell, prepare_here_doc(shell, \
		&(struct s_operator){0, 0, 0}));
	input = readline(shell->prompt);
	if (!input || g_signal == SIGINT)
	{
		cancel_here_doc(shell, (struct s_operator){0, 0, 0});
		return (!ft_safe_free(&input));
	}
	if (ft_strboolcmp(input, *heredoc))
	{
		ft_safe_free(&input);
		return (0);
	}
	if (dollar_is_valid(input))
		replace_dollar_with_value(&input, shell);
	if (*input != 0 && !join_heredoc(&shell->arg[index].this, input) && \
		ft_safe_free(heredoc) && ft_safe_free(&input))
		error_shell(shell, MALLOC_ERROR, (__LINE__ - 2), "join_heredoc()");
	if (!join_heredoc(&shell->arg[index].this, "\n") && \
		ft_safe_free(heredoc) && ft_safe_free(&input))
		error_shell(shell, MALLOC_ERROR, (__LINE__ - 2), "join_heredoc()");
	ft_safe_free(&input);
	return (1);
}
