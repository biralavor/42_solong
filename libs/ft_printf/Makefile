# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 13:44:42 by umeneses          #+#    #+#              #
#    Updated: 2024/01/16 14:01:17 by umeneses         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= ft_printf.a

AUTHOR			= umeneses

SRC_FTS			= ft_printf.c				\
					ft_printf_utils.c

INCLUDE			= ft_printf.h

OBJS			= $(SRC_FTS:.c=.o)

AR				= ar -rcs

RM				= rm -rf

CC				= cc

CFLAGS			= -Wall -Wextra -Werror

all:			$(NAME)

$(NAME):		$(OBJS)

%.o:			%.c
				$(CC) -c $(CFLAGS) $< -o $@
				$(AR) $(NAME) $@

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re