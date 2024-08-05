/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_a_valid_identifier.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:32:11 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 19:32:13 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
# define NOT_VALID_IDENTIFIER;
#typedef t_shell;
#   void werror_shell(t_shell, char *, int, char *);
#*/
#include <stdbool.h> /*
# define false;
#typedef bool;
#*/
#include "../../libft/libft.h" /*
#    int ft_strlen(char *);
#*/
#include <unistd.h> /*
#ssize_t write(int, void *, size_t);
*/
/* **************************** [^] INCLUDES [^] **************************** */

bool
	not_a_valid_identifier(t_shell shell, char *command)
{
	char	*cmd42_name;

	shell->errorlevel = 1U;
	cmd42_name = get_variable("CMD42_NAME", shell);
	write(shell->std_out_fd, "-", 1);
	write(shell->std_out_fd, cmd42_name, ft_strlen(cmd42_name));
	write(shell->std_out_fd, ": ", 2);
	if (!!command)
	{
		write(shell->std_out_fd, command, ft_strlen(command));
		write(shell->std_out_fd, ": ", 2);
	}
	write(shell->std_out_fd, "`", 1);
	write(shell->std_out_fd, shell->arg[shell->index].this, \
		ft_strlen(shell->arg[shell->index].this));
	write(shell->std_out_fd, "': ", 3);
	write(shell->std_out_fd, NOT_VALID_IDENTIFIER, \
		ft_strlen(NOT_VALID_IDENTIFIER));
	write(shell->std_out_fd, "\n", 1);
	return (false);
}
