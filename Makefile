NAME	= minishell.a
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
SRCS 	=	functions/ft_strlen.c\
			functions/ft_strjoin.c\
			functions/ft_gnl.c\
			functions/ft_split.c\
			functions/ft_putstr_fd.c\
			functions/ft_memcopy.c\
			functions/ft_strcmp.c\
			functions/ft_strdup.c\
			functions/ft_strchr.c\
			functions/ft_isdigit.c\
			functions/ft_strappend.c\
			functions/free_d_pointer.c\
			functions/ft_dplen.c\
			functions/init_all_struct.c\
			parsing/parsing.c\
			parsing/signals.c\
			parsing/trim_spaces.c\
			parsing/splitting_by_semicolon.c\
			execution/env.c\
			execution/history.c\
			execution/start_execution.c\
			execution/exec_single_cmd.c\
			execution/builtins/ft_pwd.c\
			execution/builtins/ft_cd.c\
			execution/builtins/ft_export.c\
			execution/builtins/ft_unset.c\
			execution/builtins/ft_env.c\
			execution/builtins/ft_exit.c\
			execution/builtins/ft_echo.c\
			execution/functions/get_cmd_path.c\

			
			
			

$(NAME) : 	$(SRCS)
			@ $(CC) $(FLAGS) -c $(SRCS)
			@ ar rc $(NAME) *.o



all: 		$(NAME)

clean:
			@rm -rf *.o functions/*.o parsing/*.o execution/*.o a.out

fclean: 	clean
			@rm -rf $(NAME) minishell a.out minishell.dSYM

re: 		fclean all

amine: 		re
			@ $(CC) $(FLAGS) minishell.c $(NAME) -o minishell
			@ rm -rf $(NAME) minishell.a *.o

abdlali: 	re
			@ $(CC) $(FLAGS) execution/main.c $(NAME) -g3 -fsanitize=address
			@ rm -rf $(NAME) minishell.a *.o
