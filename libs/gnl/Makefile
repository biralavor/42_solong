# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 13:35:45 by umeneses          #+#    #+#              #
#    Updated: 2024/01/16 13:58:15 by umeneses         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= gnl.a

AUTHOR			= umeneses

SRC_FTS			= get_next_line.c				\
					get_next_line_utils.c		\
					get_next_line_bonus.c		\
					get_next_line_utils_bonus.c

INCLUDE			= get_next_line.h				\
					get_next_line_bonus.h

OBJS			= $(SRC_FTS:.c=.o)

OBJS_BONUS		= $(SCR_BONUS_FTS:.c=.o)

OBJS_ALL		= $(OBJS) $(OBJS_BONUS)

AR				= ar -rcs

RM				= rm -rf

CC				= cc

CFLAGS			= -Wall -Wextra -Werror

all:			$(NAME)

$(NAME):		$(OBJS_ALL)

%.o:			%.c
				$(CC) -c $(CFLAGS) $< -o $@
				$(AR) $(NAME) $@

clean:
				$(RM) $(OBJS_ALL)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean clean re