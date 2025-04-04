# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohkhald <mohkhald@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 22:35:22 by mohkhald          #+#    #+#              #
#    Updated: 2025/04/04 20:32:38 by mohkhald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = push_swap.c sort_stack.c sort_five.c sort_three.c free.c check_and_error.c\
push_items.c rotate_items.c rot_rev_items.c swap_items.c push_utilis.c

CC = cc

CFLAGS = -Wall -Wextra -Werror

PRINTF = ft_printf/libftprintf.a

LIBFT = libft/libft.a

NAME = push_swap

RM = rm -Rf

all: $(NAME)

$(NAME): $(OBJ) 
	@make -C ft_printf/
	@make -C libft/
	@$(CC) $(CFLAGS) $(SRCS) $(PRINTF) $(LIBFT) -o $(NAME)

clean: 
	@make clean -C ft_printf/
	@make clean -C libft/

fclean: clean
	@$(RM) $(LIBFT) $(NAME) $(PRINTF)

re: fclean all

.PHONY: clean fclean re all
