# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/26 20:31:36 by umeneses          #+#    #+#              #
#    Updated: 2024/01/18 19:00:31 by umeneses         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 				= libft.a

AUTHOR				= umeneses

SRC_FTS				= ft_atoi.c
SRC_FTS				+= ft_bzero.c
SRC_FTS				+= ft_calloc.c
SRC_FTS				+= ft_isalnum.c
SRC_FTS				+= ft_isalpha.c
SRC_FTS				+= ft_isascii.c
SRC_FTS				+= ft_isdigit.c
SRC_FTS				+= ft_isprint.c
SRC_FTS				+= ft_memchr.c
SRC_FTS				+= ft_memcmp.c
SRC_FTS				+= ft_memcpy.c
SRC_FTS				+= ft_memmove.c
SRC_FTS				+= ft_memset.c
SRC_FTS				+= ft_strchr.c
SRC_FTS				+= ft_strdup.c
SRC_FTS				+= ft_strlcat.c
SRC_FTS				+= ft_strlcpy.c
SRC_FTS				+= ft_strlen.c
SRC_FTS				+= ft_strncmp.c
SRC_FTS				+= ft_strnstr.c
SRC_FTS				+= ft_strrchr.c
SRC_FTS				+= ft_tolower.c
SRC_FTS				+= ft_toupper.c
SRC_FTS				+= ft_substr.c
SRC_FTS				+= ft_itoa.c		
SRC_FTS				+= ft_putchar_fd.c
SRC_FTS				+= ft_putstr_fd.c
SRC_FTS				+= ft_putendl_fd.c
SRC_FTS				+= ft_putnbr_fd.c
SRC_FTS				+= ft_striteri.c
SRC_FTS				+= ft_strmapi.c
SRC_FTS				+= ft_strjoin.c
SRC_FTS				+= ft_split.c	
SRC_FTS				+= ft_strtrim.c
# ****** libft functions ****** #

SRC_FTS				+= ft_printf.c
SRC_FTS				+= ft_printf_placeholder.c
SRC_FTS				+= ft_put_unsigned_nbr.c
SRC_FTS				+= ft_putnbrbase.c
SRC_FTS				+= ft_putptr.c
# ****** ft_printf functions ****** #

BONUS_FTS			= ft_lstadd_front_bonus.c
BONUS_FTS			+= ft_lstadd_back_bonus.c
BONUS_FTS			+= ft_lstclear_bonus.c
BONUS_FTS			+= ft_lstdelone_bonus.c
BONUS_FTS			+= ft_lstiter_bonus.c
BONUS_FTS			+= ft_lstlast_bonus.c
BONUS_FTS			+= ft_lstmap_bonus.c
BONUS_FTS			+= ft_lstnew_bonus.c
BONUS_FTS			+= ft_lstsize_bonus.c
# ****** bonus libft functions ****** #

INCLUDE				= libft.h

OBJS 				= $(SRC_FTS:.c=.o)

BONUS_OBJS			= $(BONUS_FTS:.c=.o)

AR 					= ar -rcs

RM 					= rm -f

CC 					= cc

CFLAGS 				= -Wall -Wextra -Werror

all:				$(NAME)

$(NAME):			$(OBJS) bonus

%.o: %.c
					$(CC) -c $(CFLAGS) $< -o $@
					$(AR) $(NAME) $@

bonus:				$(BONUS_OBJS)

clean:
					$(RM) $(OBJS) $(BONUS_OBJS)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re