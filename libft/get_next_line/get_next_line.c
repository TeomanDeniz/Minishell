/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:49:56 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/23 15:17:56 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../libft.h" /*
# define BUFFER_SIZE;
#   char *ft_strdup(char *);
#   char *ft_strchr(char *, int);
#   char *ft_strjoin(char *, char *);
#*/
#include <unistd.h> /*
#    int read(int, void *, size_t);
#*/
#include <stdlib.h> /*
#   void *malloc(size_t);
#   void free(void *);
#*/
#include <stdio.h> /*
# define NULL;
#*/
#ifdef __APPLE__ /* MACOS */
# include <sys/syslimits.h> /*
#  define OPEN_MAX
#*/
#else
# ifndef OPEN_MAX
#  define OPEN_MAX 0X1000
# endif /* OPEN_MAX */
#endif /* __APPLE__ */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
static void	*ft_free_stash(char **stash, int create_line);
static char	*ft_extract_line(char *stash);
static char	*ft_recreate_stash(char *stash);
/* *************************** [^] PROTOTYPES [^] *************************** */

char
	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	int			size;
	static char	*stash[OPEN_MAX];
	char		*line;
	char		*joinned_string;

	size = BUFFER_SIZE;
	while (size > 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if ((size == 0 && !stash[fd]) || size == -1)
			return (ft_free_stash(&stash[fd], 0));
		buffer[size] = 0;
		joinned_string = ft_strjoin(stash[fd], buffer);
		stash[fd] = (ft_free_stash(&stash[fd], 0), joinned_string);
		if (ft_strchr(stash[fd], '\n'))
		{
			line = ft_extract_line(stash[fd]);
			if (!line)
				return (ft_free_stash(&stash[fd], 0));
			stash[fd] = ft_recreate_stash(stash[fd]);
			return (line);
		}
	}
	return (ft_free_stash(&stash[fd], 1));
}

static void
	*ft_free_stash(char **stash, int create_line)
{
	char	*line;

	if (*stash && !create_line)
	{
		free(*stash);
		*stash = NULL;
		return (NULL);
	}
	else if (*stash && create_line)
	{
		line = ft_strdup(*stash);
		free(*stash);
		*stash = NULL;
		return (line);
	}
	return (NULL);
}

static char
	*ft_extract_line(char *stash)
{
	char			*line;
	register int	index_1;
	register int	index_2;

	if (!stash)
		return (NULL);
	index_1 = ft_strchr(stash, '\n') - stash;
	line = (char *) malloc(sizeof(char) * (index_1 + 2));
	if (!line)
		return (NULL);
	index_2 = -1;
	while (++index_2 < index_1 + 1)
		line[index_2] = stash[index_2];
	line[index_2] = 0;
	return (line);
}

static char
	*ft_recreate_stash(char *stash)
{
	char	*res;

	if (!stash)
		return (NULL);
	if (!*(ft_strchr(stash, '\n') + 1))
		return (ft_free_stash(&stash, 0));
	res = ft_strdup(ft_strchr(stash, '\n') + 1);
	ft_free_stash(&stash, 0);
	return (res);
}
