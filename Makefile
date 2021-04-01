# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/03 18:34:17 by aes-salm          #+#    #+#              #
#    Updated: 2021/04/01 14:11:59 by atahiri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CFLAGS= -Wall -Werror -Wextra

CC= gcc

SRCS = main.c

OBJS=	$(SRCS:.c=.o)


all: 		$(NAME)

$(NAME):
	gcc $(CFLAGS) -c $(SRCS)
	gcc -o $(NAME) $(OBJS) -g

clean:
			@rm -rf *.o

fclean: 	clean
			@rm -rf $(NAME)

re: 		fclean all