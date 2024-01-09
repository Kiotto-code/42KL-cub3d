# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yichan <yichan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/08 18:30:38 by yichan            #+#    #+#              #
#    Updated: 2023/08/16 02:48:49 by yichan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g3 
CSANT		=	-fsanitize=address
SRCS_PATH	=	./srcs/**
OBJS_PATH	=	./objs
LIBFT		=	./libft
INCLUDES	=	./includes
SRCS		+=	${wildcard ${SRCS_PATH}/*.c}
OBJS		+=	${patsubst %.c, ${OBJS_PATH}/%.o, ${notdir ${SRCS}}}
# OBJS		+=	${patsubst %.c, ${OBJS_PATH}/%.o, ${notdir ${SRCS}}}

UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
	MLXFLAGS	= -Lmlx_linux -lmlx_Linux -L/usr/lib -I/usr/include -Imlx_linux -lXext -lX11 -lm -lz
	MLXFLAGS2	= -Lmlx_linux -lmlx_Linux -L/usr/lib -I/usr/include -Imlx_linux -lXext -lX11 -lm -lz
endif
ifeq ($(UNAME), Darwin)
	MLXFLAGS	= -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit -Imlx
	MLXFLAGS2	=
endif

all					:	${NAME}
${NAME}				:	${OBJS}
						${MAKE} -C ${LIBFT}
						${CC} ${CFLAGS} ${CSANT} -I${INCLUDES} -L${LIBFT} $^ -lft -o $@
${OBJS_PATH}/%.o	:	${SRCS_PATH}/%.c ./includes/*.h ./Makefile | $(OBJ_PATH)
						mkdir -p ${@D}
						${CC} ${CFLAGS} ${CSANT} -c -I${INCLUDES} $< -o $@
clean				:	
						rm -rf ${OBJS_PATH}
						${MAKE} -C libft $@
fclean				:	clean
						rm -rf ${NAME}
re					:	fclean all
.PHONY				:	all clean fclean re