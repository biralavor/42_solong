# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 15:54:10 by umeneses          #+#    #+#              #
#    Updated: 2024/01/03 18:21:18 by umeneses         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

AUTHOR		= umeneses

CFLAGS		= -Ofast

MLXCODAM_D	= ./libs/codam

LIBFT_D		= ./libs/libft

HEADERS		= -I ./headers/ -I $(MLXCODAM_D)/include/MLX42/

MLX42_A		= $(MLXCODAM_D)/build

SRC_D		= ./src/

SRCS		= $(SRC_D)main.c

AR			= ar -rcs

RM			= rm -rf

OBJS		= ${SRCS:.c=.o}

all:		libmlx $(NAME)

$(NAME):	$(OBJS)
			cp $(LIBFT_D)/libft.a $(NAME)
			cp $(MLX42_A)/libmlx42.a $(NAME)
			$(AR) $(NAME) $(OBJS)
			$(CC) $(OBJS) $(MLX42_A)/libmlx42.a -ldl -lglfw -pthread -lm \
				$(HEADERS) -o $(NAME)

libmlx:		libft_lib
			@cmake $(MLXCODAM_D) -B $(MLXCODAM_D)/build
			$(MAKE) -C $(MLXCODAM_D)/build -j4

libft_lib:
			$(MAKE) -C $(LIBFT_D)

%.o: 		%.c
			@$(CC) -c $(CFLAGS) $< -o $@ $(HEADERS)
			@echo "Compiling: $(notdir $<)"

clean:
			$(RM) $(OBJS)
			$(RM) $(MLXCODAM_D)/build
			$(MAKE) -C $(LIBFT_D) clean

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(MLXCODAM_D)/build
			$(MAKE) -C $(LIBFT_D) fclean

re:			fclean all

.PHONY:		libft_lib libmlx all clean fclean re