/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasecmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 22:19:41 by hdeniz            #+#    #+#             */
/*   Updated: 2024/08/01 15:17:56 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ char	detect_case(register char compare, register \
char command);
/* *************************** [^] PROTOTYPES [^] *************************** */

int
	ft_strcasecmp(const char *const string, const char *const compare)
{
	register unsigned int	index;

	if (string == compare)
		return (1);
	if (!string || !compare)
		return (0);
	index = (unsigned int)0;
	while (!!string[index] && !!compare[index] && \
		(string[index] == (compare[index] + \
		detect_case(compare[index], 'l')) || \
		string[index] == (compare[index] + \
		detect_case(compare[index], 'U')) || \
		string[index] == (compare[index])))
		++index;
	if (!compare[index] && !string[index])
		return (1);
	return (0);
}

extern __inline__ char
	detect_case(register char compare, register char command)
{
	if ((command == 'l') && (compare >= 'A') && (compare <= 'Z'))
		return (32);
	if ((command == 'U') && (compare >= 'a') && (compare <= 'z'))
		return (-32);
	return (0);
}
