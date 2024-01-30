/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_certain_home.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 00:51:51 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/19 00:51:52 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
# define PATH_MAX;
# define MALLOC_ERROR;
#typedef t_shell;
#   void error_shell(t_shell, char *, int, char *);
#*/
#include "../../libft/libft.h" /*
#   void ft_bzero(char *, int);
#   bool ft_strboolcmp(char *, char *);
#   char *ft_strdup(char *);
#*/
#include <stdbool.h> /*
#typedef bool;
# define false;
# define true;
#*/
#include <dirent.h> /*
# define DT_DIR; [DIRECTORY]
# struct dirent;
#typedef DIR;
#Sdirent *readdir(DIR *);
#    DIR *opendir(char *);
#    int closedir(DIR *);
#*/
#include <unistd.h> /*
# define F_OK;
# define R_OK;
# define X_OK;
#    int access(char *, int);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
static char	*remove_desktop(char *home_directory, t_shell shell);
static void	ft_stradd(char string[PATH_MAX], const char *add);
/* *************************** [^] PROTOTYPES [^] *************************** */

char
	*get_certain_home(t_shell shell)
{
	char			home_directory[PATH_MAX];
	struct dirent	*entry;
	DIR				*dir;

	dir = opendir("/Users/");
	if (dir == NULL)
		return (NULL);
	entry = readdir(dir);
	while (ft_bzero(home_directory, PATH_MAX), entry != NULL)
	{
		if (entry->d_type == DT_DIR && !ft_strboolcmp(entry->d_name, ".") && \
			!ft_strboolcmp(entry->d_name, "..") && \
			!ft_strboolcmp(entry->d_name, "Shared"))
		{
			ft_stradd(home_directory, "/Users/");
			ft_stradd(home_directory, entry->d_name);
			ft_stradd(home_directory, "/Desktop");
			if (access(home_directory, F_OK | R_OK | X_OK) == 0)
				return (closedir(dir), remove_desktop(home_directory, shell));
		}
		entry = readdir(dir);
	}
	closedir(dir);
	return (NULL);
}

static char
	*remove_desktop(char *home_directory, t_shell shell)
{
	register int	index;
	char			*result;

	index = -1;
	while (++index, !!home_directory[index])
		if (home_directory[index] == '/' && \
			home_directory[index + 1] == 'D' && \
			home_directory[index + 2] == 'e' && \
			home_directory[index + 3] == 's' && \
			home_directory[index + 4] == 'k' && \
			home_directory[index + 5] == 't' && \
			home_directory[index + 6] == 'o' && \
			home_directory[index + 7] == 'p' && \
			home_directory[index + 8] == 0)
			break ;
	home_directory[index] = 0;
	result = ft_strdup(home_directory);
	if (!result)
		error_shell(shell, MALLOC_ERROR, (__LINE__ - 2), "ft_strdup()");
	return (result);
}

static void
	ft_stradd(char string[PATH_MAX], const char *add)
{
	register int	index;

	index = 0;
	if (!string || !add)
		return ;
	while (string[index])
		++index;
	while (*add && index < PATH_MAX)
	{
		string[index] = *add;
		++add;
		++index;
	}
	string[index] = 0;
}
