# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/28 11:06:44 by arakotom          #+#    #+#              #
#    Updated: 2024/07/23 02:27:04 by arakotom         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

OBJ_DIR = objs

SRCS = $(filter-out *bonus.c, $(wildcard *.c))
BONUS_SRCS = $(wildcard *bonus.c)

OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))
BONUS_OBJS = $(patsubst %bonus.c,$(OBJ_DIR)/%bonus.o,$(BONUS_SRCS))

RM = rm -rf

NAME = libft.a

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(dir $@)
	cc $(CFLAGS) $ -c $< -o $@

bonus: $(OBJS) $(BONUS_OBJS)
	ar -rcs $(NAME) $(OBJS) $(BONUS_OBJS)

clean :
	$(RM) $(OBJ_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
