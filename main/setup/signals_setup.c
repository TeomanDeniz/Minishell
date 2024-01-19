/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:43:37 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/07 15:43:38 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/****************************************************************************\
|*                        WHAT ARE THESE SIGNALS DO?                        *|
|****************************************************************************|
|*..........................................................................*|
|*: SIGWINCH : Get activates when terminal's screen size changes.          :*|
|*:..........:.............................................................:*|
|*:   SIGINT : Get activates when pressed CTRL + C key. (SIGNAL INTERRUPT) :*|
|*:..........:.............................................................:*|
|*:  SIGQUIT : Get activates when pressed CTRL + / key. (Do nothing)       :*|
|*:..........:.............................................................:*|
\****************************************************************************/

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdbool.h> /*
# define false;
#*/
#include "../main.h" /*
#   void suppress_cat_io(bool);
#   void update_row_and_col_variables(int);
#   void handle_sigint(int);
#*/
#include <signal.h> /*
# define SIGWINCH;
# define SIGINT;
# define SIGQUIT;
# define SIG_IGN;
#sigh... signal(int, sighandler_t); ((sighandler_t))
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	signals_setup(void)
{
	suppress_cat_io(false);
	signal(SIGWINCH, update_row_and_col_variables);
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
}
