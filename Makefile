# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/03 18:34:17 by aes-salm          #+#    #+#              #
#    Updated: 2021/05/25 21:10:54 by aes-salm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
			parsing/parsing.c\
			execution/env.c\
			execution/builtins/ft_pwd.c\
			execution/builtins/ft_cd.c\

			
			
			

$(NAME) : 	$(SRCS)
			@ $(CC) $(FLAGS) -c $(SRCS)
			@ ar rc $(NAME) *.o



all: 		$(NAME)

clean:
			@rm -rf *.o functions/*.o parsing/*.o execution/*.o a.out

fclean: 	clean
			@rm -rf $(NAME) minishell a.out

re: 		fclean all

amine: 		re
			@ $(CC) $(FLAGS) minishell.c $(NAME) -o minishell
			@ rm -rf $(NAME) minishell.a *.o

abdlali: 	re
			@ $(CC) $(FLAGS) execution/main.c $(NAME) -g
			@ rm -rf $(NAME) minishell.a *.o
