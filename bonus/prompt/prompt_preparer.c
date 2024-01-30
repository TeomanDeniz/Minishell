/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_preparer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:59:38 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 13:59:39 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
# define MALLOC_ERROR;
#typedef t_shell;
#    int prompt_size_detector(t_shell, char *);
#   void error_shell(t_shell, char *, int, char *);
#   char *get_variable(char *, t_shell);
#   void set_base_pwd(t_shell, int *, char **);
#   void set_term_name_prompt(t_shell, int *, char **);
#   void set_history_prompt(t_shell, int *, char **);
#   void set_return_status_prompt(t_shell, int *, char **);
#   int prompt_tilda(char * , t_shell, int *);
#*/
#include "../../libft/libft.h" /*
#   bool ft_safe_free(char **);
#   void *ft_calloc(Uint, Uint);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
static void	prompt_preparer_slash(t_shell shell, int *prompt_index, char **ps);
static void	prompt_preparer_percent(t_shell shell, int *prompt_index, char \
**ps);
static void	set_one_prompt(t_shell shell, int *prompt_index, char **ps);
static void	set_var_prompt(t_shell shell, int *prompt_index, char *var, \
char **ps);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	prompt_preparer(t_shell shell, char *ps)
{
	int	prompt_index;

	prompt_index = 0;
	ft_safe_free(&shell->prompt);
	shell->prompt = (char *) ft_calloc(sizeof(char), \
		prompt_size_detector(shell, ps) + 1);
	if (!shell->prompt)
		error_shell(shell, MALLOC_ERROR, (__LINE__ - 3), "ft_calloc()");
	if (!shell->prompt)
		return ;
	while (!!*ps)
	{
		if (*ps == '\\')
			prompt_preparer_slash(shell, &prompt_index, &ps);
		else if (*ps == '%')
			prompt_preparer_percent(shell, &prompt_index, &ps);
		else
			set_one_prompt(shell, &prompt_index, &ps);
	}
	shell->prompt[prompt_index] = 0;
}

static void
	prompt_preparer_slash(t_shell shell, int *prompt_index, char **ps)
{
	if ((*ps)[1] == 'w')
		set_var_prompt(shell, prompt_index, get_variable("PWD", shell), ps);
	else if ((*ps)[1] == 'W')
		set_base_pwd(shell, prompt_index, ps);
	else if ((*ps)[1] == 's')
		set_term_name_prompt(shell, prompt_index, ps);
	else if ((*ps)[1] == '!' || (*ps)[1] == '#')
		set_history_prompt(shell, prompt_index, ps);
	else if ((*ps)[1] == 'v' || (*ps)[1] == 'V')
		set_var_prompt(shell, prompt_index, \
			get_variable("CMD42_VERSION", shell), ps);
	else
		set_one_prompt(shell, prompt_index, ps);
}

static void
	prompt_preparer_percent(t_shell shell, int *prompt_index, char **ps)
{
	if ((*ps)[1] == 'd' || (*ps)[1] == '/')
		set_base_pwd(shell, prompt_index, ps);
	else if ((*ps)[1] == '~')
		set_var_prompt(shell, prompt_index, get_variable("PWD", shell), ps);
	else if ((*ps)[1] == 's')
		set_term_name_prompt(shell, prompt_index, ps);
	else if ((*ps)[1] == '!' || (*ps)[1] == 'h')
		set_history_prompt(shell, prompt_index, ps);
	else if ((*ps)[1] == '?')
		set_return_status_prompt(shell, prompt_index, ps);
	else if ((*ps)[1] == 'V')
		set_var_prompt(shell, prompt_index, \
			get_variable("CMD42_VERSION", shell), ps);
	else
		set_one_prompt(shell, prompt_index, ps);
}

static void
	set_one_prompt(t_shell shell, int *prompt_index, char **ps)
{
	shell->prompt[*prompt_index] = **ps;
	*prompt_index += 1;
	*ps += 1;
}

static void
	set_var_prompt(t_shell shell, int *prompt_index, char *var, char **ps)
{
	register int	index;

	index = prompt_tilda(var, shell, prompt_index);
	while (!!var && !!var[index])
	{
		shell->prompt[*prompt_index] = var[index];
		*prompt_index += 1;
		++index;
	}
	*ps += 2;
}
