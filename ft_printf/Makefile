# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvidot <cvidot@student.42prague.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 15:00:43 by cvidot            #+#    #+#              #
#    Updated: 2023/07/16 11:15:17 by cvidot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_printf_utils.c ft_print_nums.c ft_print_ptrs.c

NAME = libftprintf.a

CC = cc

CC_FLAGS = -Wall -Wextra -Werror

OBJS_DIR = objs/

OBJS = $(SRCS:.c=.o)

OBJS_PREFIXED = $(addprefix $(OBJS_DIR),$(OBJS))

$(OBJS_DIR)%.o: %.c ft_printf.h
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJS_PREFIXED)
	@ar rc $(NAME) $(OBJS_PREFIXED)

all: $(NAME)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
