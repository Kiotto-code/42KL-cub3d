# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yichan <yichan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/08 21:38:41 by etlaw             #+#    #+#              #
#    Updated: 2024/03/17 20:11:21 by yichan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror -I -g3 
LDFLAGS = -fsanitize=address -g3
MLX = -I /usr/X11/include -g -L /usr/local/lib -l mlx -framework OpenGL -framework AppKit
LIBFT_PATH = ./libft

# OBJS = obj/init.o \
# 	   obj/main.o \
# 	   obj/hooking.o \
# 	   obj/test.o \
# 	   obj/drawing.o \
# 	   obj/libft.o \
# 	   obj/raycast.o \

SRCS = $(wildcard *.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

re: fclean all

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(MLX) $(LDFLAGS) -L${LIBFT_PATH} -lft

obj:
	mkdir obj

obj/%.o: ./%.c | obj
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

.PHONY: all re clean fclean