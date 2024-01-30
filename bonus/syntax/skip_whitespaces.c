/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_whitespaces.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:22:42 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 17:22:42 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#typedef t_operator;
#   bool char_whitespace_o(char, t_operator);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	skip_whitespaces(char **input, t_operator operator)
{
	while (!!**input && (char_whitespace_o(**input, operator)))
		*input += 1;
}
