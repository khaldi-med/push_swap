# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohkhald <mohkhald@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 22:35:22 by mohkhald          #+#    #+#              #
#    Updated: 2025/03/18 22:51:50 by mohkhald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc

CFLAGS = -Wall -Wextra -Werror

PRINTF = ft_printf/libftprintf.a

LIBFT = libft/libft.a

SOURCE = push_swap.c

NAME = push_swap

RM = rm -Rf

all: $(NAME)

$(NAME): $(SOURCE)
	@make -C ft_printf/
	@make -C libft/
	@$(CC) $(CFLAGS) $(SOURCE)  $(PRINTF) $(LIBFT) -o $(NAME)

clean: 
	@make clean -C ft_printf/
	@make clean -C libft/

fclean: clean
	@$(RM) $(LIBFT) $(NAME) $(PRINTF)

re: fclean all

.PHONY: clean fclean re all
