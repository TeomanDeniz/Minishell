/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:46:14 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/08 16:46:14 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
# define EXPORT_OUT
#typedef t_shell;
#typedef t_variable;
#    int skip_docs(t_shell);
#    int check_next_syntax(char *);
#    int check_equal_valid(t_shell, char *);
#   char *get_variable_direct_value(char *, t_shell);
#   void command_set_varible(t_shell);
#        */
#include <unistd.h> /*
# define STDOUT_FILENO
#ssize_t write(int, void *, size_t);
#        */
#include "../../libft/libft.h" /*
#    int ft_strlen(char *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ void	export_with_parameter(t_shell shell);
extern __inline__ void	print_variable(t_variable event_varaible);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	command_export(t_shell shell)
{
	t_variable	event_varaible;

	shell->index++;
	event_varaible = shell->variable;
	if (skip_docs(shell), !!shell->arg[shell->index].this && \
		!(shell->arg[shell->index].operator && \
		check_next_syntax(shell->arg[shell->index].this)))
	{
		while (skip_docs(shell), !!shell->arg[shell->index].this && \
			!(shell->arg[shell->index].operator && \
			check_next_syntax(shell->arg[shell->index].this)))
			export_with_parameter(shell);
	}
	else
		print_variable(event_varaible);
}

extern __inline__ void
	export_with_parameter(t_shell shell)
{
	if (check_equal_valid(shell, "export"))
		if (!get_variable_direct_value(shell->arg[shell->index].this, shell))
			command_set_varible(shell);
	shell->index++;
}

extern __inline__ void
	print_variable(t_variable event_varaible)
{
	while (!!event_varaible)
	{
		write(STDOUT_FILENO, EXPORT_OUT, ft_strlen(EXPORT_OUT));
		write(STDOUT_FILENO, event_varaible->name, \
			ft_strlen(event_varaible->name));
		if (!!event_varaible->value)
		{
			write(STDOUT_FILENO, "=\"", 2);
			write(STDOUT_FILENO, event_varaible->value, \
				ft_strlen(event_varaible->value));
			write(STDOUT_FILENO, "\"", 1);
		}
		write(STDOUT_FILENO, "\n", 1);
		event_varaible = event_varaible->next;
	}
}
