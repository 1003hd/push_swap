# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baserbet <baserbet@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/30 16:15:34 by baserbet          #+#    #+#              #
#    Updated: 2026/05/30 20:17:55 by baserbet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= push_swap.c parsing.c parsing_utils.c create_stacks.c \
		operation_stacks.c utils.c presorting.c

OBJ		= ${SRC:.c=.o}

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

%.o:		%.c ${HEAD}
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@${RM} ${OBJ}
	@$(MAKE) -C $(LIB_DIR) clean
	@echo "Objects files has been deleted."


fclean: clean
	@${RM} ${NAME}
	@$(MAKE) -C $(LIB_DIR) fclean
	@echo "The ${NAME} has been deleted."

re:		fclean all

.PHONY: all clean fclean re test