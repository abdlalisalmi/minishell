# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/03 18:34:17 by aes-salm          #+#    #+#              #
#    Updated: 2021/05/23 11:01:34 by aes-salm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
OBJS	= $(SRCS:.c=.o)
SRCS 	= main.c\

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $@


all: 		$(NAME)

clean:
			@rm -rf *.o

fclean: 	clean
			@rm -rf $(NAME)

re: 		fclean all