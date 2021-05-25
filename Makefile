# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/03 18:34:17 by aes-salm          #+#    #+#              #
#    Updated: 2021/05/25 15:39:07 by aes-salm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell.a
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
SRCS 	=	functions/ft_strlen.c\
			functions/ft_strjoin.c\
			functions/ft_gnl.c\
			functions/ft_split.c\
			parsing/parsing.c\
			execution/builtins/ft_pwd.c

			
			
			

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
			@ $(CC) $(FLAGS) execution/builtins/main.c $(NAME)
			@ rm -rf $(NAME) minishell.a *.o
