# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvidot <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/27 13:51:57 by cvidot            #+#    #+#              #
#    Updated: 2023/07/27 13:52:00 by cvidot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = minitalk

SRCS = server.c client.c
PRINTF = ./ft_printf/

SRC_DIR = ./src/
INC_DIR = ./include/
OBJ_DIR = ./obj/

OBJS = $(SRCS:%.c=$(OBJ_DIR)%.o)

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(NAME): $(OBJS)
	@$(MAKE) -sC $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJS) -L$(PRINTF) -lftprintf -o $(NAME)
	@echo "Compiled."

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) -sC $(PRINTF) fclean
	rm -f $(NAME)

re: fclean all


