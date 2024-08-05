/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 23:22:15 by hdeniz            #+#    #+#             */
/*   Updated: 2024/08/01 15:17:56 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "libft.h" /*
#   char *ft_strchr(char *, int);
#    int ft_strlen(char *);
#   char *ft_strdup(char *);
#   bool ft_free_matrix(char ***);
#        */
#include <stdlib.h> /*
#   void *malloc(size_t);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ int	get_word_count(char *string, int character);
extern __inline__ void	get_next_word(char **string, char character, int index);
/* *************************** [^] PROTOTYPES [^] *************************** */

char
	**ft_split(char const *string, char character)
{
	char			**result;
	int				word;
	register int	index;

	index = -1;
	word = get_word_count((char *) string, character);
	result = ft_calloc(word + 1, sizeof(*result));
	if (result == NULL)
		return (NULL);
	while (++index < word)
	{
		get_next_word(((char **) &string), character, index);
		if (ft_strchr(string, character) == NULL)
			result[index] = ft_strdup(string);
		else
			result[index] = ft_substr(string, 0, \
				ft_strchr(string, character) - string);
		if (result[index] == NULL)
		{
			ft_free_matrix(&result);
			return (NULL);
		}
	}
	return (result);
}

extern __inline__ int
	get_word_count(char *string, int character)
{
	register int	index;
	int				result;

	result = 0;
	index = -1;
	while (++index, string[index] && string[index] == character)
		(void)0;
	while (string[index])
	{
		++result;
		while (string[index] && string[index] != character)
			++index;
		while (string[index] && string[index] == character)
			++index;
	}
	return (result);
}

extern __inline__ void
	get_next_word(char **string, char character, int index)
{
	if (index != 0)
	{
		while (**string && **string != character)
			(*string)++;
	}
	while (**string && **string == character)
		(*string)++;
}
