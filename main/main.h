/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:00:49 by hdeniz            #+#    #+#             */
/*   Updated: 2023/11/12 18:00:52 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/****************************************************************************\
|*                                  NOTES                                   *|
|****************************************************************************|
|*                                                                          *|
|* - The project must be compile with "-lreadline -lncurses" flags.         *|
|*                                                                          *|
|* - If "cat" returns "^M" while pressing ENTER key, then run command       *|
|* "stty sane" and try again. It's a Terminal issue.                        *|
|*                                                                          *|
|* TODO: %i (Number of total <ENTER> key pressed)                           *|
|* %c \W (Direct dir name)                                                  *|
|* %d %/ are dir without ~                                                  *|
|* %~ %w are dir with ~                                                     *|
|*                                                                          *|
\****************************************************************************/

/****************************************************************************\
|*                             PROMPT COMMANDS                              *|
|****************************************************************************|
|*                                                                          *|
|* - These are the commands that you can use in your promt.                 *|
|*                                                                          *|
|* - Its mixed with ZSH and BASH prompt commands. You can able to use both. *|
|*                                                                          *|
|* Examples: PS1="\w> " | PS1="[%?]> " | PS1="[%?]{\W}> "                   *|
|*                                                                          *|
|*..........................................................................*|
|*: %~ \w %d %/ : Full directory                                           :*|
|*:.............:..........................................................:*|
|*:          \W : The directory name (PWD)                                 :*|
|*:.............:..........................................................:*|
|*:          %s : Terminal name                                            :*|
|*:.............:..........................................................:*|
|*: %! \! \# %h : The total entered commands history (Number)              :*|
|*:.............:..........................................................:*|
|*:          %? : The ERRORLEVEL of last process (Return value)            :*|
|*:.............:..........................................................:*|
|*:    \v \V %V : Terminal version                                         :*|
|*:.............:..........................................................:*|
\****************************************************************************/

#ifndef MAIN_H
# define MAIN_H 202408
/* ************************* [v] ERROR MESSAGES [v] ************************* */
# define INCORRECT_COMMAND "Command not found!"
# define UNEX_EOF_MATCH "-%s: unexpected EOF while looking for matching `%c'\n"
# define UNEX_END_FILE "-%s: syntax error: unexpected end of file\n"
# define UNEX_TOKEN "-%s: syntax error near unexpected token `%s'\n"
# define UNEX_TOKEN_NEWLINE "-%s: syntax error near unexpected token \
`newline'\n"
# define EXIT_ARGUMENT "numeric argument required"
# define EXIT_TOO_MANY "too many arguments entered"
# define FORK_UNEXPECTED_END_ERROR "Child ended without exiting or executing \
anything!"
# define TOO_MANY_ARGUMENTS_ERROR "-%s: %s: Too many arguments entered\n"
# define HOME_NOT_SET "HOME not set!!!"
# define UNEXPECTED_PATH_ERROR " - There was an unexpected error while \
reading PATH.\n - Please make sure that your PATH has a correct syntax."
# define UNABLE_TO_OPEN_FORK "Shell failed to open a fork.\n - Please \
check all your process' for make sure there is no fork bomb running in \
the background via 'ps' or '/bin/ps'!"
# define MALLOC_ERROR "was not allocated!"
# define NOT_VALID_IDENTIFIER "not a valid identifier!"
# define FAILED_HOME "Failed to go to home directory!"
# define FAILED_TO_BACK "Failed to go back to current directory while fixing \
unexisting HOME variable. Whops -\\_(\"/)_/-"
# define IS_A_DIRECTORY "is a directory."
# define FILE_NAME_LONG "File name too long! (PATH_MAX)"
# define HOME_FAILED "WARNING: Failed to fix the corrupted HOME variable"
# define HOW_THE_FUCK_CD_FAILED "cd: error retrieving current directory: \
getcwd: cannot access parent directories"
/* ************************* [^] ERROR MESSAGES [^] ************************* */
/* ************************* [v] EXPORT OUTPUTS [v] ************************* */
# define EXPORT_OUT "declare -x "
/* ************************* [^] EXPORT OUTPUTS [^] ************************* */
/* ****************************** [v] PIPE [v] ****************************** */
# define CHILD_PROCESS 0
# define PIPE_READ 0
# define PIPE_WRITE 1
/* ****************************** [^] PIPE [^] ****************************** */
/* *********************** [v] BUILT IN VARIABLES [v] *********************** */
# define CMD42_PS1 "[%?]> "
# define CMD42_PS2 "dquote> "
# define CMD42_PS3 "quote> "
# define CMD42_PS4 "heredoc> "
# define CMD42_PS5 "pipe> "
# define CMD42_VERSION "4.2"
# define CMD42_NAME "CMD_42"
# define CMD42_PATH "/bin"
# define TERM_ROW "TERM_ROW"
# define TERM_COL "TERM_COL"
# define CMD42_HISFILE ".cmd42_history"
# define HISTFILE_LIMIT 500
/* *********************** [^] BUILT IN VARIABLES [^] *********************** */
/* **************************** [v] INCLUDES [v] **************************** */
# include <stdio.h> /*
# typedef FILE;
#         */
# include <unistd.h> /*
# typedef pid_t;
#         */
# include <signal.h> /*
# typedef sig_atomic_t;
#         */
# ifdef __APPLE__ /* MACOS */
#  include <sys/syslimits.h> /*
#   define PATH_MAX
#         */
# else
#  ifndef PATH_MAX
#   define PATH_MAX 1024
#  endif /* PATH_MAX */
# endif /* __APPLE__ */
/* **************************** [^] INCLUDES [^] **************************** */
/* *************************** [v] STRUCTURES [v] *************************** */
typedef union u_converter
{
	unsigned long	ul_var;
	void			*p_var;
}	t_converter;

typedef struct s_execute
{
	char	*file;
	char	**arg;
	char	**env;
	int		operator;
}	*t_execute;

typedef struct s_operator
{
	int	double_quote;
	int	single_quote;
	int	pipe;
}	*t_operator;

struct s_arg
{
	char	*this;
	int		operator;
};

typedef struct s_variable
{
	char				*name;
	char				*value;
	struct s_variable	*next;
}	*t_variable;

typedef struct s_shell
{
	char				*input;
	char				*org_input;
	char				*prompt;
	char				*quote_here_doc;
	char				*home;
	char				*histfile;
	char				**env;
	char				*execute_program;
	char				pwd[PATH_MAX];
	char				path_command[PATH_MAX];
	int					ws_row;
	int					ws_col;
	int					history_number_of_commands_in_file;
	int					history_number_of_commands;
	int					std_out_fd;
	int					histfile_fd;
	unsigned int		index;
	unsigned int		errorlevel;
	int					status_actknowledge;
	int					i_am_a_fork;
	int					fork_job;
	int					fix_extra_fucking_newline;
	int					command_not_found;
	int					fucking_filedock_happend;
	pid_t				last_pid;
	t_variable			variable;
	struct s_arg		*arg;
	struct s_operator	operator;
	void				*original_rl_getc_function;
}	*t_shell;
/* *************************** [^] STRUCTURES [^] *************************** */
/* ************************ [v] GLOBAL VARIABLES [v] ************************ */
extern volatile sig_atomic_t	g_signal;
/* ************************ [^] GLOBAL VARIABLES [^] ************************ */
/* ************************* [v] ./print_header [v] ************************* */
extern void	print_header(t_shell shell);
/* ************************* [^] ./print_header [^] ************************* */
/* *************************** [^] ./execute [^] **************************** */
extern void	execute(t_shell shell);
extern void	execute_recursive(t_shell shell, int arg_pipe[2]);
extern void	return_execve_status(t_shell shell);
extern int	check_pipe_doc(t_shell shell, int arg_pipe[2], int current_pipe[2]);
extern int	do_the_event(t_shell shell, int current_pipe[2], int arg_pipe[2]);
extern int	check_command_found_in_path(t_shell shell);
extern void	normal_job(t_shell shell, int arg_pipe[2]);
extern void	fork_job(t_shell shell, int current_pipe[2], int arg_pipe[2]);
extern char	*prepare_execute_program(t_shell shell);
extern char	**prepare_execute_arguments(t_shell shell, int arg_index);
extern void	parent_process(int next_pipe[2], int current_pipe[2], \
int arg_pipe[2]);
extern void	child_process(t_shell shell, int current_p[2], int arg_p[2], \
char **arg);
extern int	check_next_pipe(t_shell shell);
extern int	check_if_semicolon(t_shell shell);
extern int	is_executable(char *command, t_shell shell);
/* *************************** [^] ./execute [^] **************************** */
/* **************************** [v] ./error [v] ***************************** */
extern void	error_shell(t_shell shell, char *note, int line, char *from);
extern void	perror_shell(t_shell shell, char *note, int line, char *from);
extern void	werror_shell(t_shell shell, char *note, int line, char *from);
/* **************************** [^] ./error [^] ***************************** */
/* ***************************** [v] ./free [v] ***************************** */
extern void	free_shell(t_shell shell);
extern void	free_all_variables(t_shell shell);
extern void	reset_pipe(t_shell shell, int pipe_fd[2]);
extern void	free_arg(t_shell shell);
extern void	reset_content_pipe(int arg_pipe[2]);
/* ***************************** [^] ./free [^] ***************************** */
/* **************************** [v] ./setup [v] ***************************** */
extern void	signals_setup(void);
extern void	shell_setup(t_shell shell, char **env);
extern char	*get_certain_home(t_shell shell);
/* **************************** [^] ./setup [^] ***************************** */
/* *************************** [v] ./signals [v] **************************** */
extern void	handle_sigint(int signal);
extern void	ignore_sigint_for_child(int signal);
extern void	update_row_and_col_variables(int signal);
extern void	just_handle_signal(int signal);
/* *************************** [^] ./signals [^] **************************** */
/* ************************** [v] ./variables [v] *************************** */
extern void	variable_setup(t_shell shell);
extern void	sort_variables(t_shell shell);
extern void	env_to_variable(t_shell shell, char **env);
extern void	set_var_by_int(char *name, int x, t_shell shell);
extern void	set_variable(const char *name, const char *value, t_shell shell);
extern char	*get_variable_direct_value(const char *name, t_shell shell);
extern char	*get_variable(const char *name, t_shell shell);
extern int	get_variable_len(const char *name, t_shell shell);
extern void	remove_variable(const char *name, t_shell shell);
extern void	variable_to_env(t_shell shell);
extern void	set_and_free_variable(char *name, char *value, t_shell shell);
extern int	first_creating_variable(const char *name, const char *value, \
t_shell shell, register int check_if_value_null);
extern int	existing_variable(const char *name, const char *value, \
t_shell shell, register int check_value_null);
extern void	prepare_name(char **name, const char *const env);
extern void	prepare_value(char **value, char *env);
/* ************************** [^] ./variables [^] *************************** */
/* ***************************** [v] ./cmd [v] ****************************** */
extern int	check_term_env_exist(void);
extern int	move_cursor_up(void);
extern int	rd_input_ctrl_c_bypass(FILE *stream);
extern void	suppress_cat_io(register int echo_ctrl_character);
extern int	check_syntax_error(t_shell shell);
/* ***************************** [^] ./cmd [^] ****************************** */
/* *************************** [v] ./commands [v] *************************** */
extern void	process_command(t_shell shell);
extern int	skip_docs(t_shell shell);
extern int	check_direct_variable_creation(t_shell shell);
extern void	direct_variable_creation(t_shell shell);
extern int	check_equal_valid(t_shell shell, char *command);
extern int	check_equal_valid_true(t_shell shell, char *command);
extern void	command_echo(t_shell shell);
extern void	command_exit(t_shell shell);
extern void	command_cd(t_shell shell);
extern int	command_pwd(t_shell shell);
extern void	command_env(t_shell shell);
extern void	command_export(t_shell shell);
extern void	command_unset(t_shell shell);
extern void	command_set_varible(t_shell shell);
extern void	command_not_found(t_shell shell);
extern int	command_if_builtin(char *command);
extern int	not_a_valid_identifier(t_shell shell, char *command);
/* *************************** [^] ./commands [^] *************************** */
/* ************************** [v] ./arguments [v] *************************** */
extern void	prepare_args(t_shell shell);
extern void	fill_the_operator(t_shell shell, register int index);
extern void	fill_the_argument(t_shell shell, int arg_index);
extern int	operate_job(t_shell shell, int arg_index, int *string_index, \
t_operator op);
extern int	arg_strlen(t_shell shell, char *org_input);
extern char	*get_varaible_by_name(char *input, t_shell shell, \
register int index);
extern int	variable_name_len(char *input, register int index);
extern int	dollar_valid(t_shell shell, register int index);
extern int	tilda_valid(t_shell shell, t_operator op, register int index);
extern void	arg_set_quote(register char input, t_operator operator);
extern int	arg_counter(t_shell shell);
extern int	char_quote_o(register char character, struct s_operator operator);
/* ************************** [^] ./arguments [^] *************************** */
/* ***************************** [v] ./docs [v] ***************************** */
extern void	set_here_doc_operator(char *input, t_operator operator);
extern void	reset_here_doc_operator(char *input, t_operator operator);
extern char	*prepare_here_doc(t_shell shell, t_operator operator);
extern void	cancel_here_doc(t_shell shell, struct s_operator operator);
extern int	dollar_is_valid(const char *const input);
extern void	replace_dollar_with_value(char **input, t_shell shell);
/* ************************ [v] ./docs/file_doc [v] ************************* */
extern void	arg_file_document(t_shell shell, register int index);
extern void	prepare_arg_file_doc(t_shell shell);
extern void	prepare_filedoc(char **this, int fd, char *file, t_shell shell);
/* ************************ [^] ./docs/file_doc [^] ************************* */
/* ************************ [v] ./docs/here_doc [v] ************************* */
extern void	arg_here_document(t_shell shell, int index);
extern void	prepare_arg_here_doc(t_shell shell);
/* ************************ [^] ./docs/here_doc [^] ************************* */
/* ************************ [v] ./docs/quate_doc [v] ************************ */
extern void	quote_here_doc(t_shell shell);
extern void	here_doc_just_one_char(t_shell shell, char character);
extern int	check_quate_here_doc(t_shell shell);
/* ************************ [^] ./docs/quate_doc [^] ************************ */
/* ***************************** [^] ./docs [^] ***************************** */
/* **************************** [v] ./prompt [v] **************************** */
extern void	prompt_preparer(t_shell shell, char *ps);
extern void	set_return_status_prompt(t_shell shell, int *prompt_index, \
char **ps);
extern void	set_term_name_prompt(t_shell shell, int *prompt_index, char **ps);
extern void	set_history_prompt(t_shell shell, int *prompt_index, char **ps);
extern int	prompt_tilda(char *var, t_shell shell, int *prompt_index);
extern void	set_base_pwd(t_shell shell, int *prompt_index, char **ps);
extern int	prompt_size_detector(t_shell shell, char *ps);
/* **************************** [^] ./prompt [^] **************************** */
/* **************************** [v] ./syntax [v] **************************** */
extern int	arg_operator(const struct s_arg arg);
extern int	char_operator_o(register char character, \
struct s_operator operator);
extern int	char_operator(register char character);
extern void	skip_whitespaces(char **input, t_operator operator);
extern int	char_whitespace_o(register char character, t_operator operator);
extern int	char_whitespace(register char character);
extern void	set_double_quote(t_operator operator);
extern void	set_single_quote(t_operator operator);
extern int	check_next_syntax(const char *const input);
extern int	check_arrow_syntax(const char *const input);
extern int	check_outpend_syntax(const char *const input);
extern int	check_heredoc_syntax(const char *const input);
extern int	there_is_slash_on_command(const char *const command);
extern int	file_checker(char *command, register int debug, t_shell shell);
/* **************************** [^] ./syntax [^] **************************** */
/* *************************** [v] ./history [v] **************************** */
extern int	set_readline_history(t_shell shell);
extern void	set_history(t_shell shell);
extern void	edit_history_file(t_shell shell);
/* *************************** [^] ./history [^] **************************** */
#endif /* MAIN_H */
