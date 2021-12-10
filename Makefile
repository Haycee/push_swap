NAME		=	push_swap

INCS		=	./includes/push_swap.h \

SRCS		=	./srcs/push_swap.c \
				./srcs/push_swap_utils.c \
				./srcs/operations.c \
				./srcs/parse_args.c \

LIBFT_AR	=	./libft/libft.a \

OBJS		=	${SRCS:.c=.o}

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -I ${INCS}

RM			=	rm -rf

all : libft ${NAME}

libft:
	make -C ./libft

%.o: %.c ${INCS}
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS} ${LIBFT_AR}
	${CC} ${OBJS} ${LIBFT_AR} -o ${NAME}

clean:
	${RM} ${OBJS}
	make clean -C ./libft

fclean: clean
	${RM} ${LIBFT_AR}
	${RM} ${NAME}

re: fclean all

.PHONY: all libft clean fclean re
