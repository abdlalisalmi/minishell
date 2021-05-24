# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/03 18:34:17 by aes-salm          #+#    #+#              #
#    Updated: 2021/05/24 10:16:54 by aes-salm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
OBJS	= $(SRCS:.c=.o)
SRCS 	=	minishell.c\
			functions/ft_strlen.c\
			functions/ft_gnl.c\
			

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $@


all: 		$(NAME)

clean:
			@rm -rf *.o functions/*.o

fclean: 	clean
			@rm -rf $(NAME)

re: 		fclean all