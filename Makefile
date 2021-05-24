# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/03 18:34:17 by aes-salm          #+#    #+#              #
#    Updated: 2021/05/24 10:03:38 by atahiri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
OBJS	= $(SRCS:.c=.o)
SRCS 	=	minishell.c\
			libft/ft_strlen.c\
			ft_gnl.c\
			

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $@


all: 		$(NAME)

clean:
			@rm -rf *.o libft/*.o

fclean: 	clean
			@rm -rf $(NAME)

re: 		fclean all