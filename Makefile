NAME		=	push_swap

INCS		=	./includes/push_swap.h

SRCS		=	./srcs/push_swap.c \
				./srcs/push_swap_utils.c \
				./srcs/operations.c \
				./srcs/check_args.c \

LIBFT_AR	=	./libft/libft.a

OBJS		=	${SRCS:.c=.o}

CC			=	GCC

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -rf

all	:	${NAME}

${NAME}	:	${OBJS}
	make -C ./libft
	${CC} ${OBJS} ${LIBFT_AR} -o ${NAME}

%.o: %.c ${INCS} ${LIBFT_AR}
	${CC} ${FLAGS} -c $< -o $@

clean :
	${RM} ${OBJS}
	make clean -C ./libft

fclean : clean
	${RM} ${LIBFT_AR}
	${RM} ${NAME}
	
re : fclean all

.PHONY: all clean fclean re
