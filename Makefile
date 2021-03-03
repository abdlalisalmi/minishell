# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/03 18:34:17 by aes-salm          #+#    #+#              #
#    Updated: 2021/03/03 18:49:56 by aes-salm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell.a
CFLAGS= -Wall -Werror -Wextra
CC= gcc
SRCS = 


all: 		$(NAME)

$(NAME) : 	$(SRCS)
			@$(CC) $(CFLAGS) -c $(SRCS)
			@ar rc $(NAME) *.o

clean:
			@rm -rf *.o

fclean: 	clean
			@rm -rf $(NAME)

re: 		fclean all