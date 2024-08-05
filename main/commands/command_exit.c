/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:04:14 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/08 16:04:15 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
# define EXIT_TOO_MANY
# define EXIT_ARGUMENT
#typedef t_shell;
#    int skip_docs(t_shell);
#   void werror_shell(t_shell, char *, int, char *);
#   void free_shell(t_shell);
#        */
#include "../../libft/libft.h" /*
#    int ft_atoi(char *);
#    int ft_strlen(char *);
#        */
#include <unistd.h> /*
#ssize_t write(int, void *, size_t);
#        */
#include <stdlib.h> /*
#   void exit(int);
#        */
#include <limits.h> /*
# define INT_MAX
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ void	its_over(t_shell shell);
extern __inline__ int	check_if_number(const char *const number);
extern __inline__ int	check_int_max(const char *const number);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	command_exit(t_shell shell)
{
	if (shell->index++, !shell->arg || (skip_docs(shell) && \
		!shell->arg[shell->index].this) || shell->arg[shell->index].operator)
		(void)0;
	else if (check_if_number(shell->arg[shell->index].this) && \
		check_int_max(shell->arg[shell->index].this))
	{
		if (!!shell->arg[shell->index].this && \
			!!shell->arg[shell->index + 1].this)
		{
			werror_shell(shell, EXIT_TOO_MANY, 0, "exit");
			shell->errorlevel = (unsigned int)1;
			while (shell->arg[shell->index].this)
				shell->index++;
			return ;
		}
		shell->errorlevel = \
			(unsigned)ft_atoi(shell->arg[shell->index].this);
	}
	else
	{
		werror_shell(shell, EXIT_ARGUMENT, 0, shell->arg[shell->index].this);
		shell->errorlevel = (unsigned int)255;
	}
	its_over(shell);
}

extern __inline__ void
	its_over(t_shell shell)
{
	if (!shell->i_am_a_fork)
		write(shell->std_out_fd, "exit\n", 5);
	free_shell(shell);
	exit(shell->errorlevel);
}

extern __inline__ int
	check_int_max(const char *const number)
{
	if (ft_atoi(number) == INT_MAX || ft_strlen(number) > 10)
		return (0);
	return (1);
}

extern __inline__ int
	check_if_number(const char *const number)
{
	register int	index;

	index = 0;
	if (!number)
		return (1);
	while (number[index] == ' ' || \
		number[index] == '\t' || \
		number[index] == '\v' || \
		number[index] == '\f' || \
		number[index] == '\r')
		++index;
	if (number[index] == '+' || number[index] == '-')
		++index;
	while (number[index] <= '9' && '0' <= number[index])
		++index;
	while (number[index] == ' ' || \
		number[index] == '\t' || \
		number[index] == '\v' || \
		number[index] == '\f' || \
		number[index] == '\r')
		++index;
	if (!!number[index])
		return (0);
	return (1);
}
