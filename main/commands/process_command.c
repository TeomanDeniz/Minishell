/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:54:47 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/08 15:54:47 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#typedef t_shell;
#   void command_echo(t_shell);
#   void command_exit(t_shell);
#   void command_cd(t_shell);
#   void command_pwd(t_shell);
#   void command_env(t_shell);
#   void command_export(t_shell);
#   void command_unset(t_shell);
#   bool check_direct_variable_creation(t_shell);
#   void direct_variable_creation(t_shell);
#   void command_not_found(t_shell);
#   void free_shell(t_shell);
#*/
#include "../../libft/libft.h" /*
#   bool ft_strcasecmp(char *, char *);
#*/
#include <stdlib.h> /*
#   void exit(int);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	process_command(t_shell shell)
{
	if (ft_strcasecmp(shell->arg[shell->index].this, "echo"))
		command_echo(shell);
	else if (ft_strcasecmp(shell->arg[shell->index].this, "exit"))
		command_exit(shell);
	else if (ft_strcasecmp(shell->arg[shell->index].this, "cd"))
		command_cd(shell);
	else if (ft_strcasecmp(shell->arg[shell->index].this, "pwd"))
		command_pwd(shell);
	else if (ft_strcasecmp(shell->arg[shell->index].this, "env"))
		command_env(shell);
	else if (ft_strcasecmp(shell->arg[shell->index].this, "export"))
		command_export(shell);
	else if (ft_strcasecmp(shell->arg[shell->index].this, "unset"))
		command_unset(shell);
	else if (check_direct_variable_creation(shell))
		direct_variable_creation(shell);
	else if (shell->arg[shell->index].operator)
		shell->index++;
	else
		command_not_found(shell);
	if (shell->i_am_a_fork)
	{
		free_shell(shell);
		exit(shell->errorlevel);
	}
}
