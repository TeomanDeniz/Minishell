# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 10:48:13 by hdeniz            #+#    #+#              #
#    Updated: 2023/10/20 10:48:15 by hdeniz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
# [COMPILER]

FLAGS		:=	-Wall -Werror -Wextra # -g
# [COMPILER FLAGS]

MAIN_FLAGS	=	-Wall -Werror -Wextra -lreadline -lncurses # -g
# [COMPILER FLAGS]

# [LIBFT]

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
	# [FILES TO COMPILE]

	LIBFT_OBJ	=	$(eval LIBFT_OBJ := $$(LIBFT_SRC:.c=.o))$(LIBFT_OBJ)
	# [.c FILE NAMES TO .o]
# [LIBFT]

# [MAIN]
	MAIN_EXE	=	"minishell"
	# [EXECUTABLE PROGRAM NAME]

	NAME		=	./main/main.a
	# [COMPILED LIBRARY FILE'S NAME (STATIC LINK LIBRARY)]

	MAIN		=	./main/main.c
	# [MAIN PRODUCT TO COMPILE]

	SRC			=	./main/arguments/arg_counter.c \
					./main/arguments/arg_set_quote.c \
					./main/arguments/arg_strlen.c \
					./main/arguments/char_quote_o.c \
					./main/arguments/dollar_job.c \
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
					./main/docs/quate_doc/here_doc_just_newline.c \
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
					./main/print_header/print_header.c \
					./main/print_header/write_color_f.c \
					./main/print_header/header_elemans/a.c \
					./main/print_header/header_elemans/b.c \
					./main/print_header/header_elemans/c.c \
					./main/print_header/header_elemans/d.c \
					./main/print_header/header_elemans/e.c \
					./main/print_header/header_elemans/f.c
	# [FILES TO COMPILE]

	OBJ				=	$(eval OBJ := $$(SRC:.c=.o))$(OBJ)
	# [.c FILE NAMES TO .o]
# [MAIN]

# ANIMATION VARIABLES
	N_FILES		:=	0
	FILES_N		:=	0
# ANIMATION VARIABLES

# ANIMATION
define progress_bar
	$(eval PBAR := $(shell echo $(1)*100/$(2)*100/100 | bc))
	$(eval PDONE := $(shell echo $(PBAR)*4/10 | bc))
	$(eval PLEFT := $(shell echo 40-$(PDONE) | bc))
	$(eval PSEQ := $(shell seq 0 1 $(PLEFT) 2>/dev/null))
	$(eval PEMPTY := $(shell if [ "$(1)" -ne "$(2)" ]; then printf "░%.0s" $(PSEQ); fi))
	$(eval PFILL := $(shell printf "█%.0s" $(shell seq 1 $(PDONE))))
	@printf "\r $(shell tput setaf 11)[$(shell tput setaf 14)$(PFILL)$(PEMPTY)$(shell tput setaf 11)] $(PBAR)%% - $(shell tput setaf 10)[$(1)/$(2)]$(shell tput setaf 11) [$(shell tput setaf 13)$(3)$(shell tput setaf 11)]                                    "
endef
# ANIMATION

a: all
all: $(NAME)

%.o: %.c
	$(eval FILES_N := $(shell echo $(FILES_N) + 1 | bc))
	$(call progress_bar,$(FILES_N),$(N_FILES),$<)
	@$(CC) $(FLAGS) -c $< -o $@
	@if [ -a $(NAME) ]; then \
		rm -f $(NAME) ; \
	fi;
	@if [ -a $(MAIN_EXE) ]; then \
		rm -f $(MAIN_EXE) ; \
	fi;

$(NAME): files_n_calculator $(OBJ) $(LIBFT_OBJ) $(OBJ_READLINE) $(SRC_NCURSES)
	@ar -rcs $(NAME) $(OBJ)
	@ar -rcs "./libft.a" $(LIBFT_OBJ)
	@if [ -a $(MAIN) ]; then \
		if [ -a "./$(MAIN_EXE)" ]; then \
			echo " $(shell tput setab 12)$(shell tput setaf 15)$(MAIN) is up to date !$(shell tput sgr0)" ; \
		else \
			$(CC) $(FLAGS) $(MAIN) $(NAME) "libft.a" $(MAIN_FLAGS) -o $(MAIN:.c=); \
			mv "$(MAIN:.c=)" "./$(MAIN_EXE)"; \
			echo "" ; \
			echo "" ; \
			echo "" ; \
			echo " $(shell tput setab 2)$(shell tput setaf 15)$(MAIN) Done !$(shell tput sgr0)" ; \
		fi; \
	fi;
	@echo ""

c: clean
clear: clear
clean:
	@rm -f $(OBJ)
	@rm -f $(LIBFT_OBJ)
	@echo ""
	@echo " $(shell tput setaf 15)$(shell tput setab 1)Clearing Objective Files$(shell tput sgr0)"
	@echo ""

fc: fclean
fclear: fclean
fclean: clean
	@if [ -a $(NAME) ]; then \
		rm -f $(NAME) ; \
		echo "" ; \
		echo " $(shell tput setab 1)$(shell tput setaf 11)$(NAME)$(shell tput setaf 15) deleted$(shell tput sgr0)" ; \
		echo "" ; \
	fi;
	@if [ -a "libft.a" ]; then \
		rm -f "libft.a" ; \
		echo "" ; \
		echo " $(shell tput setab 1)$(shell tput setaf 11)"libft.a"$(shell tput setaf 15) deleted$(shell tput sgr0)" ; \
		echo "" ; \
	fi;
	@if [ -a $(MAIN_EXE) ]; then \
		rm -f $(MAIN_EXE) ; \
		echo "" ; \
		echo " $(shell tput setab 1)$(shell tput setaf 11)$(MAIN_EXE)$(shell tput setaf 15) deleted$(shell tput sgr0)" ; \
		echo "" ; \
	fi;

files_n_calculator:
	@echo "$(shell tput sgr0)"
	@echo ""
	$(eval FILES_N := 0)
	$(eval N_FILES := $(shell echo $(SRC) $(LIBFT_SRC) | wc -w | sed "s/ //g" | bc))
	$(eval N_OBJ := $(shell find . -name '*.o' -type f | wc -w | sed "s/ //g" | bc))
	$(eval N_FILES := $(shell echo $(N_FILES) - $(N_OBJ) | bc))
	$(if $(filter 0,$(N_FILES)), $(eval N_FILES := 1))

r: fclean all
re: fclean all

.PHONY: all a clean clear c fclean fclear fc re r norminette norm n