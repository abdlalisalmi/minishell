# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/03 18:34:17 by aes-salm          #+#    #+#              #
#    Updated: 2021/05/24 12:02:55 by atahiri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
OBJS	= $(SRCS:.c=.o)
SRCS 	=	minishell.c\
			functions/ft_strlen.c\
			functions/ft_gnl.c\
			functions/ft_strjoin.c\
			functions/ft_split.c\
			parsing/parsing.c\
			
			
			

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $@


all: 		$(NAME)

clean:
			@rm -rf *.o functions/*.o parsing/*.o execution/*.o

fclean: 	clean
			@rm -rf $(NAME)

re: 		fclean all