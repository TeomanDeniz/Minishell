/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_size_detector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:56:51 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 16:56:52 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#typedef t_shell;
#    int get_variable_len(char *, t_shell);
#*/
#include "../../libft/libft.h" /*
# Ushort ft_numlen(long long);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
static int	set_prompt_size(int *result, int result_add, int return_add);
static void	detect_slash_commands(t_shell shell, int *result, char **ps);
static void	detect_percent_commands(t_shell shell, int *result, char **ps);
/* *************************** [^] PROTOTYPES [^] *************************** */

int
	prompt_size_detector(t_shell shell, char *ps)
{
	int	result;

	result = 0;
	while (!!*ps)
	{
		if (*ps == '\\')
			detect_slash_commands(shell, &result, &ps);
		else if (*ps == '%')
			detect_percent_commands(shell, &result, &ps);
		else
			ps += (++result, 1);
	}
	return (result);
}

static int
	set_prompt_size(int *result, int result_add, int return_add)
{
	*result += result_add;
	return (return_add);
}

static void
	detect_slash_commands(t_shell shell, int *result, char **ps)
{
	if ((*ps)[1] == 'w' || (*ps)[1] == 'W')
		*ps += set_prompt_size(result, get_variable_len("PWD", shell), 2);
	else if ((*ps)[1] == 'v' || (*ps)[1] == 'V')
		*ps += \
		set_prompt_size(result, get_variable_len("CMD42_VERSION", shell), 2);
	else if ((*ps)[1] == 's')
		*ps += \
		set_prompt_size(result, (get_variable_len("CMD42_NAME", shell) + 1), 2);
	else if ((*ps)[1] == '!' || (*ps)[1] == '#')
		*ps += set_prompt_size(result, \
			ft_numlen(shell->history_number_of_commands), 2);
	else if ((*ps)[1] == '?')
		*ps += set_prompt_size(result, \
			ft_numlen(shell->errorlevel), 2);
	else if ((*ps)[1] == '\"' || (*ps)[1] == '\\')
		*ps += set_prompt_size(result, 1, 2);
	else
		*ps += ((*result)++, 1);
}

static void
	detect_percent_commands(t_shell shell, int *result, char **ps)
{
	if ((*ps)[1] == '/' || (*ps)[1] == 'd' || (*ps)[1] == '~')
		*ps += set_prompt_size(result, get_variable_len("PWD", shell), 2);
	else if ((*ps)[1] == 'V')
		*ps += \
		set_prompt_size(result, get_variable_len("CMD42_VERSION", shell), 2);
	else if ((*ps)[1] == 'N')
		*ps += \
		set_prompt_size(result, (get_variable_len("CMD42_NAME", shell) + 1), 2);
	else if ((*ps)[1] == '!' || (*ps)[1] == 'h')
		*ps += set_prompt_size(result, \
			ft_numlen(shell->history_number_of_commands), 2);
	else if ((*ps)[1] == '?')
		*ps += set_prompt_size(result, ft_numlen(shell->errorlevel), 2);
	else if ((*ps)[1] == '\"' || (*ps)[1] == '%')
		*ps += set_prompt_size(result, 1, 2);
	else
		*ps += ((*result)++, 1);
}
