# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agirardi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 14:41:22 by agirardi          #+#    #+#              #
#    Updated: 2022/04/23 02:02:06 by agirardi         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME:=	push_swap

INC_PATH:=	includes
SRC_PATH:=	srcs
OBJ_PATH:=	.objects

LST_INCS	:=	push_swap.h

LST_SRCS	:=	push_swap.c \
				push_swap_utils.c \
				operations.c \
				parse_args.c \
				swap.c

LST_OBJS	:=	$(LST_SRCS:.c=.o)

INCS		:=	$(addprefix $(INC_PATH)/,$(LST_INCS))
SRCS		:=	$(addprefix $(SRC_PATH)/,$(LST_SRCS))
OBJS		:=	$(addprefix $(OBJ_PATH)/,$(LST_OBJS))

LIBFT_AR	=	./libft/libft.a

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -rf

ERASE		:=	\033[2K\r
BOLD		:=	\033[1m
redir		:=	\033[31m
GREEN		:=	\033[32m
BLUE		:=	\033[34m
PINK		:=	\033[35m
BOLD		:=	\033[1m
END			:=	\033[0m

all : libft $(NAME)

.SILENT:

libft:
	make -C ./libft

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)
	
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INCS) Makefile | $(OBJ_PATH)
	$(CC) $(CFLAGS) -I $(INC_PATH) -c $< -o $@
	printf "$(BLUE)> Compiling :$(END) $<\n"
	
	
$(NAME): $(OBJS) $(LIBFT_AR)
	printf "$(GREEN)> All the .c files from push_swap have been compiled successfully !$(END)\n"
	printf "$(BLUE)> Creating the executable file :$(END) $@\n"
	$(CC) $(OBJS) $(LIBFT_AR) -o $(NAME)
	printf "$(GREEN)> Executable file has been created successfully !$(END)\n"

clean:
	make clean -C ./libft
	$(RM) $(OBJ_PATH)
	printf "$(GREEN)> All the .o files have been removed successfully !$(END)\n"

fclean: clean
	$(RM) $(LIBFT_AR)
	$(RM) $(NAME)
	printf "$(GREEN)> all executable files have been removed successfully !$(END)\n"

re: fclean all

.PHONY: all libft clean fclean re
