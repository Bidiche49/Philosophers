# **************************************************************************** #
#	                                                                          #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 20:28:47 by ntardy            #+#    #+#              #
#    Updated: 2023/06/05 20:29:14 by ntardy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS =	philosophers.c	\
		parsing.c		\
		fill.c			\
		thread.c		\
		utils.c			\
		error.c			\
		init.c			\
		free.c			\
		actions.c		\
		check.c			\
		mutex.c			\
		utils_lib.c

CC = gcc

CFLAGS = -Wall -Werror -Wextra -pthread -g3
#-g -fsanitize=thread#

OBJS = $(SRCS:.c=.o)

EXECUTABLE = $(NAME)

all : $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXECUTABLE)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
