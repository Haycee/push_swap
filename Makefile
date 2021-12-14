# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agirardi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 14:41:22 by agirardi          #+#    #+#              #
#    Updated: 2021/12/14 15:23:35 by agirardi         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

INCS		=	./includes

SRCS		=	./srcs/push_swap.c \
				./srcs/push_swap_utils.c \
				./srcs/operations.c \
				./srcs/parse_args.c \
				./srcs/swap.c \

LIBFT_AR	=	./libft/libft.a

OBJS		=	${SRCS:.c=.o}

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -I ${INCS}

RM			=	rm -rf

all : libft ${NAME}

libft:
	@make -C ./libft --no-print-directory

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
