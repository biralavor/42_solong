# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 15:54:10 by umeneses          #+#    #+#              #
#    Updated: 2024/01/18 13:13:35 by umeneses         ###   ########.fr        #
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
LIBS_D			= libs/
FT_PRINTF_D		= $(LIBS_D)ft_printf/
GNL_D			= $(LIBS_D)gnl/
LIBFT_D			= $(LIBS_D)libft/
MLX42_D			= $(LIBS_D)codam/
MLX42_BUILD		= $(MLX42_D)build/
BUILD_D			= build/
HEADERS			= headers/ $(HEADERS_ADDED)
HEADERS_ADDED	= $(FT_PRINTF_D)
HEADERS_ADDED	+= $(GNL_D)
HEADERS_ADDED	+= $(LIBFT_D)
HEADERS_ADDED	+= $(MLX42_D)include/MLX42/

# **************************************************************************** #
#								FILES										   #
# **************************************************************************** #

FT_PRINTF		= $(addprefix $(FT_PRINTF_D), ft_printf.a)
GNL				= $(addprefix $(GNL_D), gnl.a)
LIBTF			= $(addprefix $(LIBFT_D), libft.a)
MLX42			= $(addprefix $(MLX42_BUILD), mlx_lib42.a)
LIBS			= $(FT_PRINTF) $(GNL) $(LIBTF) $(MLX42)

NAME			= so_long
NAME_BONUS		= so_long_bonus

SRCS			= $(addprefix $(SRC_D), main.c)
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
LDFLAGS			= $(addprefix -L , $(dir $(LIBS)))
LDLIBS			= -lft -lmlx42 -ldl -lglfw -pthread -lm
COMPILE_OBJS	= $(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
COMPILE_EXE		= $(CC) $(LDFLAGS) $(OBJS_ALL) $(LDLIBS) -o $(NAME)

# **************************************************************************** #
#								TARGETS										   #
# **************************************************************************** #

all:			ft_printf_lib gnl_lib libft_lib mlx_lib $(NAME)

$(BUILD_D)%.o:	%.c 
				$(MKDIR) $(dir $@)
				$(COMPILE_OBJS)
				@echo "Compiling: $(notdir $<)"


$(NAME):		$(OBJS_ALL)
				$(COMPILE_EXE)
				@echo "Game Ready!"
				@echo "Now, hit on terminal: './so_long map/CHOSE-YOUR-MAP'"

ft_printf_lib:
				@printf "$(PURPLE)"
				$(MAKE) -C $(FT_PRINTF_D)
				@printf "$(RESET)"

gnl_lib:
				@printf "$(YELLOW)"
				$(MAKE) -C $(GNL_D)
				@printf "$(RESET)"

libft_lib:
				@printf "$(CYAN)"
				$(MAKE) -C $(LIBFT_D)
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
				$(MAKE) -C $(FT_PRINTF_D) fclean
				$(MAKE) -C $(GNL_D) fclean
				$(MAKE) -C $(LIBFT_D) fclean

fclean:			clean
				$(RM) $(NAME)

re:				fclean all
rebonus:		fclean bonus

.PHONY:			all clean fclean re bonus rebonus $(NAME)