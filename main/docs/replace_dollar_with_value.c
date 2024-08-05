/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_dollar_with_value.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:09:06 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 18:09:07 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
# define MALLOC_ERROR
#typedef t_shell;
#   char *get_varaible_by_name(char *, t_shell, int);
#   void error_shell(t_shell, char *, int, char *);
#    int dollar_is_valid(char *);
#        */
#include "../../libft/libft.h" /*
# define END_OF_NUMBER_INDEX
#   void *ft_calloc(Uint, Uint);
#    int ft_strlen(char *);
#    int ft_safe_free(char **);
#   char ft_numindex(long long , Ushort);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ int	skip_variable_name(char **input, register int ecx1);
extern __inline__ int	replace_variable(char **input, t_shell shell, \
char *value);
extern __inline__ char	*get_return_value(unsigned int errorlevel, \
char result[4]);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	replace_dollar_with_value(char **input, t_shell shell)
{
	char			error_level[4];
	char			*value;
	register int	index;

	index = -1;
	while (++index, !!input && !!*input && !!(*input)[index])
	{
		value = ((void *)0);
		error_level[0] = 0;
		if ((*input)[index] == '$' && (*input)[index + 1] == '?')
			value = get_return_value(shell->errorlevel, error_level);
		else if ((*input)[index] == '$')
			value = get_varaible_by_name(*input, shell, index);
		if (!!value)
			index = replace_variable(input, shell, value);
	}
}

extern __inline__ int
	skip_variable_name(char **input, register int ecx1)
{
	register char	save_char;

	while ((*input)[ecx1])
	{
		save_char = (*input)[ecx1];
		if (!(save_char >= 'a' && save_char <= 'z') && \
			!(save_char >= 'A' && save_char <= 'Z') && \
			!(save_char >= '0' && save_char <= '9') && \
			save_char != '_')
			break ;
		ecx1++;
		save_char = (*input)[ecx1];
	}
	return (ecx1);
}

extern __inline__ int
	replace_variable(char **input, t_shell shell, char *value)
{
	char			*result;
	register int	ecx1;
	register int	ecx2;
	register int	value_index;

	if (!*input)
		return (0);
	result = (char *) ft_calloc(sizeof(char), (ft_strlen(*input) + \
		ft_strlen(value) + 2));
	if (!result)
		error_shell(shell, MALLOC_ERROR, (__LINE__ - 3), "ft_calloc()");
	ecx1 = -1;
	while (++ecx1, !!(*input)[ecx1] && !dollar_is_valid(&(*input)[ecx1]))
		result[ecx1] = (*input)[ecx1];
	ecx2 = ecx1 - 1;
	value_index = -1;
	while (++value_index, ++ecx2, !!value && !!value[value_index])
		result[ecx2] = value[value_index];
	ecx1 = skip_variable_name(input, ecx1);
	while (++ecx1, ++ecx2, !!(*input)[ecx1])
		result[ecx2] = (*input)[ecx1];
	ft_safe_free(input);
	*input = result;
	return (ecx2);
}

extern __inline__ char
	*get_return_value(unsigned int errorlevel, char result[4])
{
	register char	number;
	register int	index;

	index = 0;
	while (1)
	{
		number = 48 + ft_numindex(errorlevel, index);
		if (number == END_OF_NUMBER_INDEX)
			break ;
		result[index] = number;
		++index;
	}
	result[index] = 0;
	return (result);
}
