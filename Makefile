# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 15:54:10 by umeneses          #+#    #+#              #
#    Updated: 2025/03/12 11:25:51 by umeneses         ###   ########.fr        #
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
BONUS_D			= bonus/
SRC_UTILS_D		= $(SRC_D)utils/
BONUS_UTILS_D	= $(BONUS_D)utils/
LIBS_D			= ./libs/
LIBFT_D			= $(LIBS_D)libft/
MLX42_D			= $(LIBS_D)codam/
MLX42_BUILD		= $(MLX42_D)build/
BUILD_D			= ./build/
HEADERS_ADDED	= $(LIBFT_D)
HEADERS_ADDED	+= $(MLX42_D)include/MLX42/
HEADERS_ADDED	+= $(BONUS_D)/
HEADERS			= ./headers/ $(HEADERS_ADDED)

# **************************************************************************** #
#								FILES										   #
# **************************************************************************** #

LIBTF				= $(addprefix $(LIBFT_D), libft.a)
MLX42				= $(addprefix $(MLX42_BUILD), libmlx42.a)
LIBS				= $(LIBTF) $(MLX42)

NAME				= so_long
NAME_BONUS			= so_long

FILES				= main.c
FILES				+= loading_images.c
FILES				+= game_init.c
FILES_UTILS			= free_functions.c
FILES_UTILS			+= game_builder.c
FILES_UTILS			+= game_hooks.c
FILES_UTILS			+= game_rules.c
FILES_UTILS			+= gameplay.c
FILES_UTILS			+= map_builder/map_init_allocation.c
FILES_UTILS			+= map_builder/map_init_val_contents.c
FILES_UTILS			+= map_builder/map_init_validation.c
FILES_UTILS			+= map_builder/map_init_val_size_gnl.c
FILES_UTILS			+= map_builder/map_init.c
FILES_UTILS			+= map_builder/map_wall_validation.c
FILES_UTILS			+= map_builder/matrix_printer.c

SRCS				= $(addprefix $(SRC_D), $(FILES))
SRCS_UTILS			= $(addprefix $(SRC_UTILS_D), $(FILES_UTILS))

BONUS_FILES			= main.c
BONUS_FILES			+= loading_images_bonus.c
BONUS_FILES			+= game_init_bonus.c
BONUS_FILES_UTILS	= free_functions_bonus.c
BONUS_FILES_UTILS	+= game_builder_bonus.c
BONUS_FILES_UTILS	+= game_hooks_bonus.c
BONUS_FILES_UTILS	+= game_rules_bonus.c
BONUS_FILES_UTILS	+= gameplay_bonus.c
BONUS_FILES_UTILS	+= map_builder/map_init_allocation_bonus.c
BONUS_FILES_UTILS	+= map_builder/map_init_val_contents_bonus.c
BONUS_FILES_UTILS	+= map_builder/map_init_validation_bonus.c
BONUS_FILES_UTILS	+= map_builder/map_init_val_size_gnl_bonus.c
BONUS_FILES_UTILS	+= map_builder/map_init_bonus.c
BONUS_FILES_UTILS	+= map_builder/map_wall_validation_bonus.c
BONUS_FILES_UTILS	+= map_builder/matrix_printer_bonus.c

SRCS_BONUS			= $(addprefix $(BONUS_D), $(BONUS_FILES))
SRCS_BONUS_UTILS	= $(addprefix $(BONUS_UTILS_D), $(BONUS_FILES_UTILS))

OBJS				= $(addprefix $(BUILD_D), $(SRCS:%.c=%.o))
OBJS_UTILS			= $(addprefix $(BUILD_D), $(SRCS_UTILS:%.c=%.o))
OBJS_ALL			= $(OBJS) $(OBJS_UTILS)

OBJS_BONUS			= $(addprefix $(BUILD_D), $(SRCS_BONUS:%.c=%.o))
OBJS_BONUS_UTILS	= $(addprefix $(BUILD_D), $(SRCS_BONUS_UTILS:%.c=%.o))
OBJS_BONUS_ALL		= $(OBJS_BONUS) $(OBJS_BONUS_UTILS)

# **************************************************************************** #
#								COMMANDS									   #
# **************************************************************************** #

RM				= rm -rf
MKDIR			= mkdir -p
MV_OBJS			= find . -type f \( -name '.o' -o -name '.a'\) -exec mv {} \

# **************************************************************************** #
#								DEFINE										   #
# **************************************************************************** #
ifdef WITH_BONUS
	NAME		= $(NAME_BONUS)
	OBJS_ALL	= $(OBJS_BONUS_ALL)
endif

define bonus
	$(MAKE) WITH_BONUS=TRUE
endef

define			run_test
				echo $(1)
				valgrind --leak-check=full --show-leak-kinds=all \
				--track-origins=yes --log-file=valgrind-out.txt  \
				--suppressions=./valgrind_suppressions.sup ./so_long maps/$(1)
endef

# **************************************************************************** #
#								COMPILATION									   #
# **************************************************************************** #

AUTHOR			= umeneses
CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g3
CPPFLAGS		= $(addprefix -I , $(HEADERS)) -MMD -MP
DFLAGS			= -g3
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
				@printf "$(GREEN)"
				@echo "Game Ready!"
				@printf "$(YELLOW)"
				@echo "Now, hit on terminal: './so_long maps/CHOOSE-YOUR-MAP'"
				@printf "$(RESET)"

libft_lib:
				@printf "$(CYAN)"
				$(MAKE) -C $(LIBFT_D)
				@printf "$(RESET)"

mlx_lib:
				@cmake $(MLX42_D) -B $(MLX42_D)build
				$(MAKE) -C $(MLX42_D)build -j4

bonus:
				$(call bonus)

clean:
				$(RM) $(OBJS_ALL)
				$(RM) $(BUILD_D)
				$(RM) $(MLX42_BUILD)
				$(MAKE) -C $(LIBFT_D) fclean

fclean:			clean
				$(RM) $(NAME) $(NAME_BONUS)

re:				fclean all

leaks_%:		
				$(call run_test,$*)

.PHONY:			all clean fclean re leaks_ bonus