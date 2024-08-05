/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_the_argument.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:45:01 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/08 23:45:02 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
# struct s_operator;
#typedef t_shell;
#   void skip_whitespaces(char **, t_operator);
#    int char_whitespace_o(char, t_operator);
#    int operate_job(t_shell, int, int *, t_operator);
#    int char_quote_o(char, struct s_operator);
#   void arg_set_quote(char, t_operator);
#    int char_operator_o(char, struct s_operator);
#        */
#include "../../libft/libft.h" /*
#    int ft_strboolcmp(char *, char *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ int	check_prev_arg_is_hereodc(t_shell shell, \
register int arg_index);
extern __inline__ int	check_sub_operator(const char *const input);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	fill_the_argument(t_shell shell, int arg_index)
{
	int					string_index;
	struct s_operator	operator;

	operator = (struct s_operator){0, 0, 0};
	string_index = (skip_whitespaces(&shell->input, &operator), 0);
	while (!!*shell->input && !char_whitespace_o(*shell->input, &operator))
	{
		if (check_sub_operator(shell->input) && \
			!check_prev_arg_is_hereodc(shell, arg_index))
			if (operate_job(shell, arg_index, &string_index, &operator))
				continue ;
		if (char_quote_o(*shell->input, operator))
		{
			shell->input += (arg_set_quote(*shell->input, &operator), 1);
			continue ;
		}
		if (char_operator_o(*shell->input, operator))
			break ;
		shell->arg[arg_index].this[string_index] = *shell->input;
		shell->input += (++string_index, 1);
	}
	shell->arg[arg_index].this[string_index] = 0;
	skip_whitespaces(&shell->input, &operator);
}

extern __inline__ int
	check_prev_arg_is_hereodc(t_shell shell, register int arg_index)
{
	if (!!shell->arg && !!arg_index)
	{
		if (ft_strboolcmp(shell->arg[arg_index - 1].this, "<<") && \
			shell->arg[arg_index - 1].operator)
			return (1);
	}
	return (0);
}

extern __inline__ int
	check_sub_operator(const char *const input)
{
	if (*input == '~' || *input == '$')
		return (1);
	return (0);
}
