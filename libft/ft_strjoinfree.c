/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 21:47:59 by hdeniz            #+#    #+#             */
/*   Updated: 2024/08/01 15:17:56 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "libft.h" /*
#   char *ft_strjoin(char *, char *);
#    int ft_safe_free(char **);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

char
	*ft_strjoinfree(char *s1, const char *s2)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	ft_safe_free(&s1);
	return (result);
}
