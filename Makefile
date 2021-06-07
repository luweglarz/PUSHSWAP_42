# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/19 12:44:51 by user42            #+#    #+#              #
#    Updated: 2021/06/07 20:40:27 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

NAME = push_swap.a

FLAGS = -Wall -Wextra -Werror

SRCS  =   	srcs/fill_stack.c srcs/utils/error.c srcs/utils/lib_utils.c srcs/utils/stack_utils.c srcs/utils/find_utils.c  srcs/utils/check_sorting.c \
	 		srcs/instructions/instructions_a.c srcs/instructions/instructions_b.c srcs/instructions/instructions_ab.c  srcs/sort_short_stack.c srcs/sort_long_stack.c\


RM	= rm -f

OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "compile main push_swap with push_swap.a"
	@$(CC) main.c -o push_swap push_swap.a

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)
	$(RM) push_swap

re: fclean all