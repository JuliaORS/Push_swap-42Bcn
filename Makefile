# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 17:01:59 by julolle-          #+#    #+#              #
#    Updated: 2023/06/12 18:06:46 by julolle-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap
HEADER      := push_swap.h
SRC_DIR		:= src
SRCS		:= check_error.c ft_actions.c ft_free_mem.c ft_movements.c ft_sort_big_num.c ft_sort_num.c list_functions.c push_swap_libft.c push_swap.c

SRCS		:= $(SRCS:%=$(SRC_DIR)/%)

BUILD_DIR	:= .build
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
RM			:= @rm -fv
DIR_DUP 	= mkdir -p $(@D)

# Implicit Method
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c	Makefile $(HEADER)
	@$(DIR_DUP)
	$(CC) $(CFLAGS) -I. -c -o $@ $<

# My methods
all:	$(NAME)

$(NAME): $(OBJS)
	${CC} ${OBJS} -o ${NAME}

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

# Phony
.PHONY: all clean fclean re