# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eriling <eriling@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/19 13:39:39 by eriling           #+#    #+#              #
#    Updated: 2021/08/31 14:26:31 by eriling          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = clang
HEAD = -Iinclude
CFLAGS = -Wall -Wextra $(DEBUG)
#  DEBUG = -fsanitize=address -g3

FILES = main.c parse.c free_programm.c \
				init.c time.c bon_appetit.c \
				god_is_watching.c message.c \
				
SRC_PATH = $(shell find srcs -type d)
vpath %.c $(foreach dir, $(SRC_PATH), $(dir))

OBJ_PATH = objs
OBJ = $(addprefix $(OBJ_PATH)/, $(FILES:%.c=%.o))

all :   $(NAME) 

$(NAME) : $(OBJ_PATH) $(OBJ)
	$(CC) -pthread $(CFLAGS) $(HEAD) $(OBJ) -o ${NAME}

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o : %.c
	$(CC) $(CFLAGS) $(HEAD) -c $< -o $@

print:
	@echo $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all