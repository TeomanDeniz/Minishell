/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_the_argument.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
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
#   bool char_whitespace_o(char, t_operator);
#   bool dollar_job(t_shell, int, int *, t_operator);
#   bool char_quote_o(char, struct s_operator);
#   void arg_set_quote(char, t_operator);
#   bool char_operator_o(char, struct s_operator);
#*/
#include <stdbool.h> /*
# define false;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	fill_the_argument(t_shell shell, int arg_index)
{
	int					string_index;
	struct s_operator	operator;

	string_index = 0;
	operator = (struct s_operator){false, false};
	skip_whitespaces(&shell->input, &operator);
	while (!!*shell->input && !char_whitespace_o(*shell->input, &operator))
	{
		if (*shell->input == '~' || *shell->input == '$')
			if (dollar_job(shell, arg_index, &string_index, &operator))
				continue ;
		if (char_quote_o(*shell->input, operator))
		{
			shell->input += (arg_set_quote(*shell->input, &operator), 1);
			continue ;
		}
		if (char_operator_o(*shell->input, operator))
			break ;
		shell->arg[arg_index].this[string_index] = *shell->input;
		++string_index;
		shell->input++;
	}
	shell->arg[arg_index].this[string_index] = 0;
	skip_whitespaces(&shell->input, &operator);
}
