/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:15:48 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/08 16:15:49 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
# define PATH_MAX;
#typedef t_shell;
#*/
#include <unistd.h> /*
# define STDOUT_FILENO;
#   char *getcwd(char *, size_t);
#ssize_t write(int, void *, size_t);
#*/
#include "../../libft/libft.h" /*
#    int ft_strlen(char *);
#*/
#include <stdbool.h> /*
# define true;
#typedef bool;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

bool
	command_pwd(t_shell shell)
{
	char	dir[PATH_MAX];

	getcwd(dir, PATH_MAX);
	write(STDOUT_FILENO, dir, ft_strlen(dir));
	write(STDOUT_FILENO, "\n", 1);
	shell->errorlevel = 0U;
	return (true);
}
