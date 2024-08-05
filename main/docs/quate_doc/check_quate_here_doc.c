/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quate_here_doc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:32:10 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 18:32:11 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../../main.h" /*
# struct s_operator;
#typedef t_shell;
#   void reset_here_doc_operator(char *, t_operator);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

int
	check_quate_here_doc(t_shell shell)
{
	struct s_operator	operator;

	reset_here_doc_operator(shell->input, &operator);
	return (operator.double_quote || operator.single_quote || operator.pipe);
}
