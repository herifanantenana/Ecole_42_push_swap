# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/16 15:19:17 by arakotom          #+#    #+#              #
#    Updated: 2024/08/03 00:46:24 by arakotom         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs
OBJ_DIR = objs
LIBFT_DIR = libft
FT_PRINTF_DIR = ft_printf

SRCS = ps_error_handler.c \
	ps_init.c \
	ps_init_stack_a.c \
	ps_init_stack_b.c \
	ps_move_a_to_b.c \
	ps_move_b_to_a.c \
	ps_run_sort.c \
	instructions/ps_push.c \
	instructions/ps_reverse_rotate.c \
	instructions/ps_rotate.c \
	instructions/ps_swap.c \
	main.c \
	utils/ps_free.c \
	utils/ps_node.c \
	utils/ps_stack.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
LIB = $(LIBFT_DIR)/libft.a $(FT_PRINTF_DIR)/libftprintf.a

RM = rm -rf

NAME = push_swap

all : $(NAME)

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB) :
	@make -C $(LIBFT_DIR)
	@make -C $(FT_PRINTF_DIR)

clean :
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(FT_PRINTF_DIR)
	$(RM) $(OBJ_DIR)

fclean : clean
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(FT_PRINTF_DIR)
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re