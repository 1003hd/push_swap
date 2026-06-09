# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/30 16:15:34 by baserbet          #+#    #+#              #
#    Updated: 2026/06/09 19:01:46 by aselezen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= push_swap.c parsing.c parsing_utils.c create_stacks.c \
		operation_stacks.c utils.c push_stacks.c \
		rotate_stacks.c reverse_rotate_stacks.c simple_sort.c \
		complex_sort.c medium_sort.c strategy.c bench.c
OBJ		= ${SRC:.c=.o}
 
CHK_SRC	= checker.c checker_utils.c parsing.c parsing_utils.c \
		create_stacks.c utils.c operation_stacks.c push_stacks.c \
		rotate_stacks.c reverse_rotate_stacks.c
CHK_OBJ	= ${CHK_SRC:.c=.o}
CHK_HEAD	= checker.h push_swap.h
CHECKER	= checker
 
CFLAGS	= -Wall -Werror -Wextra
HEAD	= push_swap.h
CC		= cc
AR		= ar rcs
RM		= rm -f
NAME	= push_swap
LIB_DIR	= libft
LIB		= ${LIB_DIR}/libft.a
 
 
all:	${NAME}

$(LIB):
	make -C $(LIB_DIR)
 
${NAME}: $(LIB) ${OBJ}
	${CC} $(CFLAGS) ${OBJ} $(LIB) -o $(NAME)
	@echo "Compilation successful."
 
${CHECKER}: $(LIB) ${CHK_OBJ}
	${CC} $(CFLAGS) ${CHK_OBJ} $(LIB) -o $(CHECKER)
	@echo "Checker compilation successful."
 
%.o:		%.c ${HEAD}
	@${CC} ${CFLAGS} -c $< -o $@
 
checker.o checker_utils.o: %.o: %.c ${CHK_HEAD}
	@${CC} ${CFLAGS} -c $< -o $@
 
clean:
	@${RM} ${OBJ} ${CHK_OBJ}
	@$(MAKE) -C $(LIB_DIR) clean
	@echo "Objects files has been deleted."
 
 
fclean: clean
	@${RM} ${NAME} ${CHECKER}
	@$(MAKE) -C $(LIB_DIR) fclean
	@echo "The ${NAME} has been deleted."
 
re:		fclean all
 
.PHONY: all bonus clean fclean re test