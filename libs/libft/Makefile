# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/26 20:31:36 by umeneses          #+#    #+#              #
#    Updated: 2023/09/11 15:08:24 by umeneses         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 				= libft.a

AUTHOR				= umeneses

SRC_FTS				= ft_atoi.c		\
					ft_bzero.c		\
					ft_calloc.c		\
					ft_isalnum.c	\
					ft_isalpha.c	\
					ft_isascii.c	\
					ft_isdigit.c	\
					ft_isprint.c	\
					ft_memchr.c		\
					ft_memcmp.c		\
					ft_memcpy.c		\
					ft_memmove.c	\
					ft_memset.c		\
					ft_strchr.c		\
					ft_strdup.c		\
					ft_strlcat.c	\
					ft_strlcpy.c	\
					ft_strlen.c		\
					ft_strncmp.c	\
					ft_strnstr.c	\
					ft_strrchr.c	\
					ft_tolower.c	\
					ft_toupper.c	\
					ft_substr.c		\
					ft_itoa.c		\
					ft_putchar_fd.c	\
					ft_putstr_fd.c	\
					ft_putendl_fd.c	\
					ft_putnbr_fd.c	\
					ft_striteri.c	\
					ft_strmapi.c	\
					ft_strjoin.c	\
					ft_split.c		\
					ft_strtrim.c

BONUS_FTS			= ft_lstadd_front_bonus.c	\
					ft_lstadd_back_bonus.c		\
					ft_lstclear_bonus.c			\
					ft_lstdelone_bonus.c		\
					ft_lstiter_bonus.c			\
					ft_lstlast_bonus.c			\
					ft_lstmap_bonus.c			\
					ft_lstnew_bonus.c			\
					ft_lstsize_bonus.c			\

INCLUDE				= libft.h

OBJS 				= $(SRC_FTS:.c=.o)

BONUS_OBJS			= $(BONUS_FTS:.c=.o)

AR 					= ar -rcs

RM 					= rm -f

CC 					= cc

CFLAGS 				= -Wall -Wextra -Werror

all:				$(NAME)

$(NAME):			$(OBJS)

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