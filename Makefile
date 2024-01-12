# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 15:54:10 by umeneses          #+#    #+#              #
#    Updated: 2024/01/12 18:47:20 by umeneses         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#								COLORS										   #
# **************************************************************************** #

RED				:= \033[0;31m
GREEN			:= \033[0;32m
YELLOW			:= \033[0;33m
PURPLE			:= \033[0;35m
CYAN			:= \033[0;36m
RESET			:= \033[0m

# **************************************************************************** #
#								PATHS										   #
# **************************************************************************** #

SRC_D			:= src/
SRC_UTILS_D		:= $(SRC_D)utils/
LIBS_D			:= libs/
LIBFT_D			:= $(LIBS_D)libft/
GNL_D			:= $(LIBS_D)gnl/
FT_PRINTF_D		:= $(LIBS_D)ft_printf/
MLX42_D			:= $(LIBS_D)codam/
MLX42_BUILD		:= $(MLX42_D)build/
BUILD_D			:= build/
HEADERS			:= -I/headers/ $(HEADERS_ADDED)
HEADERS_ADDED	:= -I$(LIBFT_D) \
					-I$(GNL_D) \
					-I$(FT_PRINTF_D) \
					-I$(MLX42_D)include/MLX42/

# **************************************************************************** #
#								FILES										   #
# **************************************************************************** #

LIBTF			= $(addprefix $(LIBFT_D), libft.a)
MLX42			= $(addprefix $(MLX42_BUILD), libmlx42.a)
LIBS			= $(LIBTF) $(MLX42)

NAME			= so_long
NAME_BONUS		= so_long_bonus

SRCS			= $(addprefix $(SRC_D), main.c) \
					$(addprefix $(SRC_D), loading_images.c)
SRCS_UTILS		= $(addprefix $(SRC_UTILS_D), map_builder/map_build.c) \
					$(addprefix $(SRC_UTILS_D), map_builder/map_read.c)
SRCS_ALL		= $(SRCS) $(SRCS_UTILS)
SCRS_BONUS		= 

OBJS			= $(SRCS_ALL:%.c=$(BUILD_D)%.o)

BONUS_FILES		= $(SCRS_BONUS:%.=$(BUILD_D)%.o)
BONUS_OBJS		= $(BONUS_FILES:%.c=$(BUILD_D)%.o)

DEPENDENCIES	= $(OBJS:.o=.d)

# **************************************************************************** #
#								COMMANDS									   #
# **************************************************************************** #

#AR				= ar -rcs
RM				= rm -rf
MKDIR			= mkdir -p

# **************************************************************************** #
#								COMPILATION									   #
# **************************************************************************** #

AUTHOR			= umeneses
CC				= cc
#CFLAGS			= -Wall -Wextra -Werror
CFLAGS			= -Ofast
DFLAGS			= -g3
LDFLAGS			= $(addprefix -L, $(dir $(LIBS)))
LDLIBS			= -lft -lmlx42 -ldl -lglfw -pthread -lm
COMPILE_OBJS	= $(CC) $(CFLAGS) -c $< -o $@
COMPILE_EXE		= $(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) $(HEADERS) -o $(NAME)

# **************************************************************************** #
#								TARGETS										   #
# **************************************************************************** #

all:			libft_lib $(LIBTF) libmlx $(MLX42) $(NAME)

$(BUILD_D)%.o:	%.c
				$(MKDIR) $(dir $@)
				$(COMPILE_OBJS)
				@echo "Compiling: $(notdir $<)"
#				mv %.o $(BUILD_D)

$(NAME):		$(OBJS)
				$(COMPILE_EXE)
				@echo "Game Ready!"
				@echo "Now, hit on terminal: './so_long map/CHOSE-YOUR-MAP'"

libft_lib:
				$(MAKE) -C $(LIBFT_D)

libmlx:
				@cmake $(MLX42_D) -B $(MLX42_D)build
				$(MAKE) -C $(MLX42_D)build -j4

bonus:			libft_lib libmlx $(NAME_BONUS)

$(NAME_BONUS):	$(BONUS_OBJS)
#				$(AR) $(NAME_BONUS) $(BONUS_OBJS)
#				$(CC) $(BONUS_OBJS) $(LIBS) \
#				-ldl -lglfw -pthread -lm $(HEADERS) -o $(NAME_BONUS) $(CFLAGS)
#				@echo "Game BONUS Ready!"

clean:
				$(RM) $(OBJS)
				$(RM) $(BUILD_DIR)
				$(RM) $(MLX42_BUILD)
				$(MAKE) -C $(LIBFT_D) clean

fclean:			clean
				$(RM) $(NAME)
				$(MAKE) -C $(LIBFT_D) fclean

re:				fclean all
rebonus:		fclean bonus

.PHONY:			all clean fclean re bonus rebonus

#-include		$(DEPENDENCIES)