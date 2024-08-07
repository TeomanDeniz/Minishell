# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 10:48:13 by hdeniz            #+#    #+#              #
#    Updated: 2024/10/26 16:31:01 by hdeniz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# *************************** [v] MAIN SOURCES [v] *************************** #
LIBFT_SRC	=	./libft/get_next_line/get_next_line.c\
					./libft/ft_atoi.c \
					./libft/ft_bzero.c \
					./libft/ft_calloc.c \
					./libft/ft_free_matrix.c \
					./libft/ft_numindex.c \
					./libft/ft_numlen.c \
					./libft/ft_putchar_fd.c \
					./libft/ft_putnbr_fd.c \
					./libft/ft_safe_free.c \
					./libft/ft_split.c \
					./libft/ft_strboolcmp.c \
					./libft/ft_strcasecmp.c \
					./libft/ft_strchr.c \
					./libft/ft_strcmp.c \
					./libft/ft_strdup.c \
					./libft/ft_strjoin.c \
					./libft/ft_strjoinfree.c \
					./libft/ft_strlen.c \
					./libft/ft_substr.c

MAIN_SRC	=	$(LIBFT_SRC) \
					./main/arguments/arg_counter.c \
					./main/arguments/arg_set_quote.c \
					./main/arguments/arg_strlen.c \
					./main/arguments/char_quote_o.c \
					./main/arguments/operate_job.c \
					./main/arguments/dollar_valid.c \
					./main/arguments/fill_the_argument.c \
					./main/arguments/fill_the_operator.c \
					./main/arguments/get_varaible_by_name.c \
					./main/arguments/prepare_args.c \
					./main/arguments/tilda_valid.c \
					./main/arguments/variable_name_len.c \
					./main/cmd/check_syntax_error.c \
					./main/cmd/rd_input_ctrl_c_bypass.c \
					./main/cmd/suppress_cat_io.c \
					./main/cmd/check_term_env_exist.c \
					./main/cmd/move_cursor_up.c \
					./main/commands/check_direct_variable_creation.c \
					./main/commands/check_equal_valid.c \
					./main/commands/check_equal_valid_true.c \
					./main/commands/command_cd.c \
					./main/commands/command_echo.c \
					./main/commands/command_env.c \
					./main/commands/command_exit.c \
					./main/commands/command_export.c \
					./main/commands/command_if_builtin.c \
					./main/commands/command_not_found.c \
					./main/commands/command_pwd.c \
					./main/commands/command_set_varible.c \
					./main/commands/command_unset.c \
					./main/commands/direct_variable_creation.c \
					./main/commands/process_command.c \
					./main/commands/skip_docs.c \
					./main/commands/not_a_valid_identifier.c \
					./main/docs/dollar_is_valid.c \
					./main/docs/replace_dollar_with_value.c \
					./main/docs/reset_here_doc_operator.c \
					./main/docs/set_here_doc_operator.c \
					./main/docs/file_doc/arg_file_document.c \
					./main/docs/file_doc/prepare_arg_file_doc.c \
					./main/docs/file_doc/prepare_filedoc.c \
					./main/docs/here_doc/prepare_arg_here_doc.c \
					./main/docs/quate_doc/check_quate_here_doc.c \
					./main/docs/quate_doc/here_doc_just_one_char.c \
					./main/docs/quate_doc/quote_here_doc.c \
					./main/docs/here_doc/arg_here_document.c \
					./main/docs/cancel_here_doc.c \
					./main/docs/prepare_here_doc.c \
					./main/error/error_shell.c \
					./main/error/perror_shell.c \
					./main/error/werror_shell.c \
					./main/execute/check_command_found_in_path.c \
					./main/execute/check_if_semicolon.c \
					./main/execute/check_next_pipe.c \
					./main/execute/check_pipe_doc.c \
					./main/execute/child_process.c \
					./main/execute/do_the_event.c \
					./main/execute/execute.c \
					./main/execute/execute_recursive.c \
					./main/execute/fork_job.c \
					./main/execute/is_executable.c \
					./main/execute/normal_job.c \
					./main/execute/parent_process.c \
					./main/execute/prepare_execute_arguments.c \
					./main/execute/prepare_execute_program.c \
					./main/execute/return_execve_status.c \
					./main/free/free_all_variables.c \
					./main/free/free_arg.c \
					./main/free/reset_content_pipe.c \
					./main/free/reset_pipe.c \
					./main/free/free_shell.c \
					./main/history/set_readline_history.c \
					./main/history/set_history.c \
					./main/history/edit_history_file.c \
					./main/prompt/prompt_preparer.c \
					./main/prompt/prompt_size_detector.c \
					./main/prompt/prompt_tilda.c \
					./main/prompt/set_base_pwd.c \
					./main/prompt/set_history_prompt.c \
					./main/prompt/set_return_status_prompt.c \
					./main/prompt/set_term_name_prompt.c \
					./main/setup/signals_setup.c \
					./main/setup/shell_setup.c \
					./main/setup/get_certain_home.c \
					./main/signals/ignore_sigint_for_child.c \
					./main/signals/just_handle_signal.c \
					./main/signals/update_row_and_col_variables.c \
					./main/signals/handle_sigint.c \
					./main/syntax/arg_operator.c \
					./main/syntax/char_operator.c \
					./main/syntax/char_operator_o.c \
					./main/syntax/char_whitespace.c \
					./main/syntax/char_whitespace_o.c \
					./main/syntax/check_arrow_syntax.c \
					./main/syntax/check_heredoc_syntax.c \
					./main/syntax/check_next_syntax.c \
					./main/syntax/check_outpend_syntax.c \
					./main/syntax/file_checker.c \
					./main/syntax/set_double_quote.c \
					./main/syntax/set_single_quote.c \
					./main/syntax/skip_whitespaces.c \
					./main/syntax/there_is_slash_on_command.c \
					./main/variables/env_to_variable.c \
					./main/variables/get_variable.c \
					./main/variables/get_variable_direct_value.c \
					./main/variables/get_variable_len.c \
					./main/variables/remove_variable.c \
					./main/variables/set_var_by_int.c \
					./main/variables/set_variable.c \
					./main/variables/sort_variables.c \
					./main/variables/variable_setup.c \
					./main/variables/variable_to_env.c \
					./main/variables/set_and_free_variable.c \
					./main/variables/first_creating_variable.c \
					./main/variables/existing_variable.c \
					./main/variables/prepare_name.c \
					./main/variables/prepare_value.c \
					./main/print_header/print_header.c \
					./main/print_header/write_color_f.c \
					./main/print_header/header_elemans/a.c \
					./main/print_header/header_elemans/b.c \
					./main/print_header/header_elemans/c.c \
					./main/print_header/header_elemans/d.c \
					./main/print_header/header_elemans/e.c \
					./main/print_header/header_elemans/f.c
# *************************** [^] MAIN SOURCES [^] *************************** #

# ************************** [v] BONUS SOURCES [v] *************************** #
BONUS_SRC	=	$(LIBFT_SRC) \
					./bonus/arguments/arg_counter.c \
					./bonus/arguments/arg_set_quote.c \
					./bonus/arguments/arg_strlen.c \
					./bonus/arguments/char_quote_o.c \
					./bonus/arguments/operate_job.c \
					./bonus/arguments/dollar_valid.c \
					./bonus/arguments/fill_the_argument.c \
					./bonus/arguments/fill_the_operator.c \
					./bonus/arguments/get_varaible_by_name.c \
					./bonus/arguments/prepare_args.c \
					./bonus/arguments/tilda_valid.c \
					./bonus/arguments/variable_name_len.c \
					./bonus/cmd/check_syntax_error.c \
					./bonus/cmd/rd_input_ctrl_c_bypass.c \
					./bonus/cmd/suppress_cat_io.c \
					./bonus/cmd/check_term_env_exist.c \
					./bonus/cmd/move_cursor_up.c \
					./bonus/commands/check_direct_variable_creation.c \
					./bonus/commands/check_equal_valid.c \
					./bonus/commands/check_equal_valid_true.c \
					./bonus/commands/command_cd.c \
					./bonus/commands/command_echo.c \
					./bonus/commands/command_env.c \
					./bonus/commands/command_exit.c \
					./bonus/commands/command_export.c \
					./bonus/commands/command_if_builtin.c \
					./bonus/commands/command_not_found.c \
					./bonus/commands/command_pwd.c \
					./bonus/commands/command_set_varible.c \
					./bonus/commands/command_unset.c \
					./bonus/commands/direct_variable_creation.c \
					./bonus/commands/process_command.c \
					./bonus/commands/skip_docs.c \
					./bonus/commands/not_a_valid_identifier.c \
					./bonus/docs/dollar_is_valid.c \
					./bonus/docs/replace_dollar_with_value.c \
					./bonus/docs/reset_here_doc_operator.c \
					./bonus/docs/set_here_doc_operator.c \
					./bonus/docs/file_doc/arg_file_document.c \
					./bonus/docs/file_doc/prepare_arg_file_doc.c \
					./bonus/docs/file_doc/prepare_filedoc.c \
					./bonus/docs/here_doc/prepare_arg_here_doc.c \
					./bonus/docs/operate_doc/check_operate_doc.c \
					./bonus/docs/operate_doc/add_just_one_char.c \
					./bonus/docs/operate_doc/operate_doc.c \
					./bonus/docs/here_doc/arg_here_document.c \
					./bonus/docs/cancel_here_doc.c \
					./bonus/docs/prepare_here_doc.c \
					./bonus/error/error_shell.c \
					./bonus/error/perror_shell.c \
					./bonus/error/werror_shell.c \
					./bonus/execute/check_command_found_in_path.c \
					./bonus/execute/check_if_semicolon.c \
					./bonus/execute/check_next_pipe.c \
					./bonus/execute/check_pipe_doc.c \
					./bonus/execute/child_process.c \
					./bonus/execute/do_the_event.c \
					./bonus/execute/execute.c \
					./bonus/execute/execute_recursive.c \
					./bonus/execute/fork_job.c \
					./bonus/execute/is_executable.c \
					./bonus/execute/normal_job.c \
					./bonus/execute/parent_process.c \
					./bonus/execute/prepare_execute_arguments.c \
					./bonus/execute/prepare_execute_program.c \
					./bonus/execute/return_execve_status.c \
					./bonus/free/free_all_variables.c \
					./bonus/free/free_arg.c \
					./bonus/free/reset_content_pipe.c \
					./bonus/free/reset_pipe.c \
					./bonus/free/free_shell.c \
					./bonus/history/set_readline_history.c \
					./bonus/history/set_history.c \
					./bonus/history/edit_history_file.c \
					./bonus/prompt/prompt_preparer.c \
					./bonus/prompt/prompt_size_detector.c \
					./bonus/prompt/prompt_tilda.c \
					./bonus/prompt/set_base_pwd.c \
					./bonus/prompt/set_history_prompt.c \
					./bonus/prompt/set_return_status_prompt.c \
					./bonus/prompt/set_term_name_prompt.c \
					./bonus/setup/signals_setup.c \
					./bonus/setup/shell_setup.c \
					./bonus/setup/get_certain_home.c \
					./bonus/signals/ignore_sigint_for_child.c \
					./bonus/signals/just_handle_signal.c \
					./bonus/signals/update_row_and_col_variables.c \
					./bonus/signals/handle_sigint.c \
					./bonus/syntax/arg_operator.c \
					./bonus/syntax/char_operator.c \
					./bonus/syntax/char_operator_o.c \
					./bonus/syntax/char_whitespace.c \
					./bonus/syntax/char_whitespace_o.c \
					./bonus/syntax/check_arrow_syntax.c \
					./bonus/syntax/check_heredoc_syntax.c \
					./bonus/syntax/check_next_syntax.c \
					./bonus/syntax/check_outpend_syntax.c \
					./bonus/syntax/file_checker.c \
					./bonus/syntax/set_double_quote.c \
					./bonus/syntax/set_single_quote.c \
					./bonus/syntax/skip_whitespaces.c \
					./bonus/syntax/there_is_slash_on_command.c \
					./bonus/syntax/check_brackets.c \
					./bonus/variables/env_to_variable.c \
					./bonus/variables/get_variable.c \
					./bonus/variables/get_variable_direct_value.c \
					./bonus/variables/get_variable_len.c \
					./bonus/variables/remove_variable.c \
					./bonus/variables/set_var_by_int.c \
					./bonus/variables/set_variable.c \
					./bonus/variables/sort_variables.c \
					./bonus/variables/variable_setup.c \
					./bonus/variables/variable_to_env.c \
					./bonus/variables/set_and_free_variable.c \
					./bonus/print_header/print_header.c \
					./bonus/print_header/write_color_f.c \
					./bonus/print_header/header_elemans/a.c \
					./bonus/print_header/header_elemans/b.c \
					./bonus/print_header/header_elemans/c.c \
					./bonus/print_header/header_elemans/d.c \
					./bonus/print_header/header_elemans/e.c \
					./bonus/print_header/header_elemans/f.c
# ************************** [^] BONUS SOURCES [^] *************************** #

# ****************************** [v] BONUS [v] ******************************* #
	# [EXE]
		BONUS_EXE	=	"minishell_bonus"
		BONUS		=	./bonus/main.c
	# [EXE]
	# [ARCHIVE AND OVERLINKING CHECKER]
		BONUS_NAME		=	./main_bonus.a
	# [ARCHIVE AND OVERLINKING CHECKER]
	# [.c STRINGS TO .o]
		BONUS_OBJ	=	$(eval BONUS_OBJ := $$(BONUS_SRC:.c=.o))$(BONUS_OBJ)
	# [.c STRINGS TO .o]
# ****************************** [^] BONUS [^] ******************************* #

# **************************** [v] VARIABLES [v] ***************************** #
	# [COMPILER]
		CC			=	gcc
	# [COMPILER]
	# [EXE]
		MAIN_EXE	=	"minishell"
		MAIN		=	./main/main.c
	# [EXE]
	# [ARCHIVE AND OVERLINKING CHECKER]
		NAME		=	./main.a
	# [ARCHIVE AND OVERLINKING CHECKER]
	# [COMPILER FLAGS]
		CFLAGS		=	-Wall -Wextra -Werror # -g
		MAIN_FLAGS	=	$(CFLAGS) -lreadline -lncurses
	# [COMPILER FLAGS]
	# [.c STRINGS TO .o]
		MAIN_OBJ	=	$(eval MAIN_OBJ := $$(MAIN_SRC:.c=.o))$(MAIN_OBJ)
	# [.c STRINGS TO .o]
	# ANIMATION VARIABLES
		TERMINAL_LEN	:=	\
			$(eval TERMINAL_LEN := $(shell tput cols))$(TERMINAL_LEN)
		NUMBER_OF_FILES	:=	0
		FILE_COUNTER	:=	0
	# ANIMATION VARIABLES
# **************************** [^] VARIABLES [^] ***************************** #

# ****************************** [v] COLORS [v] ****************************** #
	C_RESET	=	$(shell tput sgr0)
	C_BLINK	=	$(shell tput blink)
	F15		=	$(shell tput setaf 15)
	B1F11	=	$(shell tput setab 1)$(shell tput setaf 11)
	B12F15	=	$(shell tput setab 12)$(shell tput setaf 15)
	B1F15	=	$(shell tput setab 1)$(shell tput setaf 15)
	B2F15	=	$(shell tput setab 2)$(shell tput setaf 15)
	F11		=	$(shell tput setaf 11)
	F13		=	$(shell tput setaf 13)
	F14		=	$(shell tput setaf 14)
	F10		=	$(shell tput setaf 10)
# ****************************** [^] COLORS [^] ****************************** #

# ***************************#* [v] FUNCIONS [v] ***************************** #
define progress_bar
	$(eval PBAR := $(shell echo $(1)*100/$(2)*100/100 | bc))
	$(eval PDONE := $(shell echo $(PBAR)*3/10 | bc))
	$(eval PLEFT := $(shell echo 30-$(PDONE) | bc))
	$(eval PSEQ := $(shell seq 0 1 $(PLEFT) 2>/dev/null))
	$(eval PEMPTY := $(shell if [ "$(1)" -ne "$(2)" ]; \
		then printf ".%.0s" $(PSEQ); fi))
	$(eval PFILL := $(shell printf "\#%.0s" $(shell seq 1 $(PDONE))))
	@printf "\r%*s\r $(F11)[$(F14)$(PFILL)$(PEMPTY)$(F11)] $(PBAR)%% - \
		$(F10)[$(1)/$(2)]$(F11) [$(F13)$(3)$(F11)$(C_RESET)]" \
		$(TERMINAL_LEN) " "
endef
# ***************************#* [^] FUNCIONS [^] ***************************** #

%.o: %.c
	$(eval FILE_COUNTER := $(shell echo $(FILE_COUNTER) + 1 | bc))
	$(call progress_bar,$(FILE_COUNTER),$(NUMBER_OF_FILES),$<)
	@rm -f $(MAIN_EXE) 2>/dev/null
	@rm -f $(BONUS_EXE) 2>/dev/null
	@$(CC) $(CFLAGS) -c $< -o $@

all: files_n_calculator $(NAME)

$(NAME): $(MAIN) $(MAIN_OBJ)
	@ar rc $(NAME) $(MAIN_OBJ) 2>/dev/null && \
	echo "\n\n $(C_BLINK)$(B2F15) $(NAME) is ready! $(C_RESET)\n"
	@$(CC) $(MAIN) $(NAME) -o "./$(MAIN_EXE)" $(MAIN_FLAGS) && \
	echo "\n\n $(C_BLINK)$(B2F15) $(MAIN_EXE) is ready! $(C_RESET)\n"

$(BONUS_NAME): $(BONUS) $(BONUS_OBJ)
	@ar rc $(BONUS_NAME) $(BONUS_OBJ) 2>/dev/null && \
	echo "\n\n $(C_BLINK)$(B2F15) $(BONUS_NAME) is ready! $(C_RESET)\n"
	@$(CC) $(MAIN_FLAGS) $(BONUS) $(BONUS_NAME) -o "./$(BONUS_EXE)" && \
	echo "\n\n $(C_BLINK)$(B2F15) $(BONUS_EXE) is ready! $(C_RESET)\n"

b: bonus
bonus: bonus_files_n_calculator $(BONUS_NAME)

c: clean
clear: clean
clean:
	@rm $(MAIN_OBJ) $(BONUS_OBJ) 2>/dev/null && \
		echo "\n $(B1F15) Objects are cleared! $(C_RESET)\n" || \
		echo "\n $(B12F15) Nothing to clear! $(C_RESET)\n"

fc: fclean
fclean: clean
	@rm $(NAME) $(BONUS_NAME) 2>/dev/null && \
	echo "\n $(B1F11) $(NAME) $(F15)deleted! $(C_RESET)\n" || \
	echo "\n $(B12F15) $(NAME) is not exist already! $(C_RESET)\n"
	@rm $(MAIN_EXE) $(BONUS_EXE) 2>/dev/null && \
	echo "\n $(B1F11) $(MAIN_EXE) $(F15)deleted! $(C_RESET)\n" || \
	echo "\n $(B12F15) $(MAIN_EXE) is not exist already! $(C_RESET)\n"

re: fc all

files_n_calculator:
	@echo ""
	$(eval FILE_COUNTER := 0)
	$(eval NUMBER_OF_FILES := $(shell echo $(MAIN_SRC) \
		| wc -w | sed "s/ //g" | bc))
	$(eval N_OBJ := \
		$(shell find "./main" "./libft" \
		-name '*.o' -type f | wc -w | sed "s/ //g" | bc))
	$(eval NUMBER_OF_FILES := $(shell echo $(NUMBER_OF_FILES) - $(N_OBJ) | bc))
	$(if $(filter 0,$(NUMBER_OF_FILES)), $(eval NUMBER_OF_FILES := 1))

bonus_files_n_calculator:
	@echo ""
	$(eval FILE_COUNTER := 0)
	$(eval NUMBER_OF_FILES := $(shell echo $(BONUS_SRC) \
		| wc -w | sed "s/ //g" | bc))
	$(eval N_OBJ := \
		$(shell find "./bonus" "./libft" \
		-name '*.o' -type f | wc -w | sed "s/ //g" | bc))
	$(eval NUMBER_OF_FILES := $(shell echo $(NUMBER_OF_FILES) - $(N_OBJ) | bc))
	$(if $(filter 0,$(NUMBER_OF_FILES)), $(eval NUMBER_OF_FILES := 1))

.PHONY: all fclean fc clean clear c bonus b
