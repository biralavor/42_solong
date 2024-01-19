# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 15:54:10 by umeneses          #+#    #+#              #
#    Updated: 2024/01/19 11:34:44 by umeneses         ###   ########.fr        #
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

SRC_D			= src/
SRC_UTILS_D		= $(SRC_D)utils/
LIBS_D			= ./libs/
LIBFT_D			= $(LIBS_D)libft/
MLX42_D			= $(LIBS_D)codam/
MLX42_BUILD		= $(MLX42_D)build/
BUILD_D			= ./build/
HEADERS			= ./headers/ $(HEADERS_ADDED)
HEADERS_ADDED	= $(LIBFT_D)
HEADERS_ADDED	+= $(MLX42_D)include/MLX42/

# **************************************************************************** #
#								FILES										   #
# **************************************************************************** #

LIBTF			= $(addprefix $(LIBFT_D), libft.a)
MLX42			= $(addprefix $(MLX42_BUILD), libmlx42.a)
LIBS			= $(LIBTF) $(MLX42)

NAME			= so_long
NAME_BONUS		= so_long_bonus

FILES			= main.c
SRCS			= $(addprefix $(SRC_D), $(FILES))
#SRCS			= $(addprefix $(SRC_D), main.c \
					loading_images.c)
#SRCS_UTILS		= $(addprefix $(SRC_UTILS_D), \
					map_builder/map_build.c \
					map_builder/map_read.c)
SCRS_BONUS		= 

OBJS			= $(addprefix $(BUILD_D), $(SRCS:%.c=%.o))
#OBJS_UTILS		= $(addprefix $(BUILD_D), $(SRCS_UTILS:%.c=%.o))
OBJS_ALL		= $(OBJS) $(OBJS_UTILS)

#BONUS_FILES	= $(SCRS_BONUS:%.=%.o)
#BONUS_OBJS		= $(BONUS_FILES:%.c=$(BUILD_D)%.o)

# **************************************************************************** #
#								COMMANDS									   #
# **************************************************************************** #

RM				= rm -rf
MKDIR			= mkdir -p
MV_OBJS			= find . -type f \( -name '.o' -o -name '.a'\) -exec mv {} \

# **************************************************************************** #
#								COMPILATION									   #
# **************************************************************************** #

AUTHOR			= umeneses
CC				= cc
#CFLAGS			= -Wall -Wextra -Werror
CFLAGS			= -Ofast
CPPFLAGS		= $(addprefix -I , $(HEADERS)) -MMD -MP
DFLAGS			= -g3
#LDLIBS			= $(addprefix -L , $(dir $(LIBS)))
LDFLAGS			= -ldl -lglfw -pthread -lm
COMPILE_OBJS	= $(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
COMPILE_EXE		= $(CC) $(OBJS_ALL) $(LDFLAGS) $(LIBS) -o $(NAME)

# **************************************************************************** #
#								TARGETS										   #
# **************************************************************************** #

all:			libft_lib mlx_lib $(NAME)

$(BUILD_D)%.o:	%.c 
				$(MKDIR) $(dir $@)
				$(COMPILE_OBJS)
				@echo "Compiling: $(notdir $<)"

$(NAME):		$(OBJS_ALL)
				$(COMPILE_EXE)
				@echo "Game Ready!"
				@echo "Now, hit on terminal: './so_long map/CHOSE-YOUR-MAP'"

libft_lib:
				@printf "$(CYAN)"
				$(MAKE) -C $(LIBFT_D)
				@echo "Checking File..."
				nm $(LIBTF)
				@printf "$(RESET)"

mlx_lib:
				@cmake $(MLX42_D) -B $(MLX42_D)build
				$(MAKE) -C $(MLX42_D)build -j4


bonus:			libft_lib mlx_lib $(NAME_BONUS)

#$(NAME_BONUS):	$(BONUS_OBJS)

clean:
				$(RM) $(OBJS_ALL)
				$(RM) $(BUILD_D)
				$(RM) $(MLX42_BUILD)
				$(MAKE) -C $(LIBFT_D) fclean

fclean:			clean
				$(RM) $(NAME)

re:				fclean all
rebonus:		fclean bonus

.PHONY:			all clean fclean re bonus rebonus $(NAME)