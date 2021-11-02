# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjanulek <mjanulek@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/18 20:18:18 by mjanulek          #+#    #+#              #
#    Updated: 2021/10/18 21:19:38 by mjanulek         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAMES = server client

NAME = minitalk

CFLAGS = -Werror -Wextra -Wall

SRCS_S = 	server.c \
			lib.c \
			lib2.c

SRCS_C = 	client.c \
			lib.c \
			lib2.c

OBJS_S = $(SRCS_S:.c=.o)

OBJS_C = $(SRCS_C:.c=.o)

all : $(NAMES)

$(NAME) : all

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

client : $(OBJS_C)
	$(CC) $(CFLAGS) $(OBJS_C) -o client

server : $(OBJS_S)
	$(CC) $(CFLAGS) $(OBJS_S) -o server

clean:
	rm -f $(OBJS_C)
	rm -f $(OBJS_S)
	
fclean: clean
	rm -f $(NAMES)

re: fclean all

.PHONY : $(NAME) clean fclean all re
