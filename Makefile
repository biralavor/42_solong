# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 15:54:10 by umeneses          #+#    #+#              #
#    Updated: 2024/01/03 15:55:45 by umeneses         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= so_long

AUTHOR		:= umeneses

CFLAGS		:= -Ofast

LIBMLX		:= ./libs/codam

HEADERS		:= -I ./include -I $(LIBMLX)/include/MLX42/

LIBS		:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRCS		:= $(shell find ./src -iname "main.c")

OBJS		:= ${SRCS:.c=.o}

all:		libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o:		%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME):	$(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean:		clean
	@rm -rf $(NAME)

re:			fclean clean all

.PHONY:		all, clean, fclean, re, libmlx