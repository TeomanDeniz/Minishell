/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_double_quote.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:26:17 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 17:26:18 by hdeniz           ###   ########.fr       */
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
	set_double_quote(t_operator operator)
{
	if (operator->double_quote)
		operator->double_quote = false;
	else
		operator->double_quote = true;
}
