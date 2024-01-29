# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yichan <yichan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/08 18:30:38 by yichan            #+#    #+#              #
#    Updated: 2024/01/22 21:37:29 by yichan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLACK	= \033[30m
RED		= \033[31m
GREEN	= \033[32m
YELLOW	= \033[33m
BLUE	= \033[34m
PURPLE	= \033[35m
CYAN	= \033[36m
WHITE	= \033[37m
RESET	= \033[0m

NAME		:= cub3d
CC			:= gcc

MLX					:= ./mlx/libmlx.a
MLXFLAGS			:= -framework OpenGL -framework AppKit
MLX_WARNING_SILENT	:= 2> /dev/null
MLX_MAKE			:= make -C mlx 2> /dev/null ${MLX_WARNING_SILENT}
# MLX_PACK			:- ./mlx/mlx

CSAN		:= -fsanitize=address -g3
CPPFLAG		:= -Wall -Werror -Wextra ${CSAN}

UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
	MLXFLAGS	= -Lmlx_linux -lmlx_Linux -L/usr/lib -I/usr/include -Imlx_linux -lXext -lX11 -lm -lz
	MLXFLAGS2	= -Lmlx_linux -lmlx_Linux -L/usr/lib -I/usr/include -Imlx_linux -lXext -lX11 -lm -lz
else
# MLXFLAGS	= -L/usr/local/lib -Lmlx -lmlx -framework OpenGL -framework AppKit -Imlx
	MLXFLAGS	= -Lmlx -lmlx -framework OpenGL -framework AppKit -Imlx
	MLXFLAGS2	=
endif

SRCS_PATH	= ./srcs/**
OBJS_PATH	= ./objs
LIBFT_PATH	= ./libft
INCLUDES	= ./includes
SRCS		= ${shell find $(SRCS_PATH) -name "*.c"}
# SRCS		=	${wildcard ${SRCS_PATH}/*.c}
OBJS		= ${patsubst %.c, ${OBJS_PATH}/%.o, ${notdir ${SRCS}}}
# OBJS		= ${patsubst ${SRCS_PATH}/%.c, ${OBJS_PATH}/%.o, ${SRCS}}

all			:	${NAME}

${NAME}		:	${OBJS}
				make -C ${LIBFT_PATH}
				${MLX_MAKE}
				$(CC) ${CPPFLAG} ${MLXFLAGS} $^ -I${INCLUDES} -lft -L${LIBFT_PATH} ${MLX} -o $@
				@echo "The program name is $(RED)./$(NAME) $(RESET)"

${OBJS_PATH}/%.o:	${SRCS_PATH}/%.c ./includes/*.h ./Makefile 
					@mkdir -p $(@D)
					${CC} ${CPPFLAG} ${MLXFLAGS2} -c -I${INCLUDES} $< -o $@
						
clean		:
				${MAKE} -C ${LIBFT_PATH} $@
				rm -rf ${OBJS_PATH}

fclean		: 	clean
				${MAKE} -C ${LIBFT_PATH} $@
				rm -rf ${NAME}

re			:	fclean all

.PHONY		:	clean fclean all re