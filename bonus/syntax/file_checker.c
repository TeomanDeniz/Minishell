/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:33:00 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 17:33:01 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdbool.h> /*
# define true;
# define false;
#typedef bool;
#*/
#include "../main.h" /*
# define IS_A_DIRECTORY;
#typedef t_shell;
#   void perror_shell(t_shell, char *, int, char *);
#*/
#include <unistd.h> /*
# define F_OK;
# define X_OK;
#    int access(char *, int);
#*/
#include <sys/stat.h> /*
# define S_ISDIR(st_mode);
# struct stat;
#    int lstat(char *, struct stat *);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
static void	file_doesnt_exist(char *command, bool debug, t_shell shell);
/* *************************** [^] PROTOTYPES [^] *************************** */

bool
	file_checker(char *command, bool debug, t_shell shell)
{
	struct stat	file_stats;

	lstat(command, &file_stats);
	if (!!command && access(command, F_OK) == 0)
	{
		if (access(command, X_OK) != 0)
		{
			shell->errorlevel = 126;
			if (debug)
				perror_shell(shell, NULL, 0, command);
			return (false);
		}
		if (S_ISDIR(file_stats.st_mode))
		{
			shell->errorlevel = 126;
			if (debug)
				werror_shell(shell, IS_A_DIRECTORY, 0, command);
			return (false);
		}
		return (true);
	}
	else
		file_doesnt_exist(command, debug, shell);
	return (false);
}

static void
	file_doesnt_exist(char *command, bool debug, t_shell shell)
{
	shell->errorlevel = 127;
	if (debug)
		perror_shell(shell, NULL, 0, command);
}
