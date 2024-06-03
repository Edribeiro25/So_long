# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/08 12:17:17 by eribeiro          #+#    #+#              #
#    Updated: 2022/01/12 10:54:34 by eribeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

CC = gcc
CFLAGS	=	-Wall -Wextra -Werror -g
IFLAGS = -I. -I./libft -I./mlx_linux
MFLAGS	= -L./mlx_linux -lmlx_Linux -lXext -lX11
MLX_DIR = ./mlx_linux
MLX = libmlx.a

SRC		=	main.c \
			mouvement.c \
			print.c \
			exit.c \
			ft_put_fd.c \
			ft_calloc.c \
			ft_strlen.c \
			gnl.c \
			parsingmaps.c\
			playerfind.c\
			check.c \

OBJ		=	$(SRC:%.c=%.o)

%.o: %.c
			$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@


$(NAME):	$(OBJ)
			chmod 777 $(MLX_DIR)/configure
			$(MAKE) -C ./$(MLX_DIR)
			cp ./$(MLX_DIR)/$(MLX) .
			$(CC) $(CFLAGS) $(OBJ) $(IFLAGS) $(LFLAGS) $(MFLAGS) -o $@

all:		$(NAME)

clean:
			rm -rf $(OBJ)

fclean:		clean
			$(MAKE) -C ./$(MLX_DIR) clean
			rm -rf $(MLX)
			rm -rf $(NAME)

re:			fclean all

.PHONY: all clean fclean re
