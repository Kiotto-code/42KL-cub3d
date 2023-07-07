NAME	:= libft.a
DEBUG	:= debugrun
CC		:= gcc
AR		:= ar
CFLAGS	:= -Wall -Werror -Wextra
CFLAGS	= -fsanitize=address -g3 -static-libsan
ARFLAGS	:= rcs
RM		:= rm -rf
# DEBUG	:= ${ARGS}

INCLUDES	= ./includes
# INCLUDES	+= includes
SRC_PATH	:= ./srcs/**
OBJ_PATH	:= ./obj

SRCS	:= ${wildcard ${SRC_PATH}/*.c}
# OBJS	= ${patsubst srcs/libft/%.c, ${OBJ_PATH}/%.o, ${SRCS}}
# OBJS	= ${patsubst srcs/printf/%.c, ${OBJ_PATH}/%.o, ${SRCS}}
# OBJS	:= ${addprefix ${OBJ_PATH}/, ${addsuffix .o, ${notdir ${basename ${SRCS}}}}}
OBJS	= $(patsubst %.c,$(OBJ_PATH)/%.o,$(notdir $(SRCS)))
# OBJS	= $(patsubst $(SRC_PATH)%.c,$(OBJ_PATH)/%.o,$(SRCS))

# all:		${OBJS_PATH} ${NAME}
all			:	${NAME}
debug		:	${DEBUG}

${NAME}:	${OBJS}
			${AR} ${ARFLAGS} $@ $^

${OBJ_PATH}/%.o:	${SRC_PATH}/%.c* ./Makefile ./includes/*.h
					mkdir -p ${@D}
					${CC} -I{INCLUDES} ${CFLAGS} -c $< -o $@

# ${OBJ_PATH}:
# 				mkdir -p ${OBJ_PATH}

clean:		
			${RM} ${OBJ_PATH}

fclean:		clean
			${RM} ${NAME}
			${RM} ./debug 

re:			fclean all

${DEBUG}:	${OBJS}
			${CC} ${CFLAGS} ./main.c $(OBJS) -o $(DEBUG)


# ${CC} ${CFLAGS} $< ./main.c  -o ./debug 

# debug:		${OBJS}
# 			${CC} libft.a ./main.c $^ -o ./debug 

# gcc -fsanitize=address -g3 ./libft.a ${ARGS}
# make ${NAME} ${ARGS}

# debug:		make ${NAME} main.c

.PHONY:		all clean fclean re debug