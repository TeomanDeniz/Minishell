/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_single_quote.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:27:11 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 17:27:11 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdbool.h> /*
# define true;
# define false;
#*/
#include "../main.h" /*
#typedef t_operator;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	set_single_quote(t_operator operator)
{
	if (operator->single_quote)
		operator->single_quote = false;
	else
		operator->single_quote = true;
}
