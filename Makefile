# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/20 14:39:47 by fvastena          #+#    #+#              #
#    Updated: 2023/10/04 12:24:36 by fvastena         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#          ----------========== {     VARS     } ==========----------

NAME = so_long
BONUS_NAME = so_long_bonus
RMF = rm -f
RMD = rm -rf
CFLAGS = -Wall -Wextra -Werror -O3
HDDIR = -Iincludes
LIB = -Llibft -llibft
LIB_INC = -Ilibft/includes
MLX_MACOS_FLAGS = -lmlx -framework OpenGL -framework AppKit

#          ----------========== {     SRCS     } ==========----------

MANDATORY_SRCS =	main.c \
					datas.c \
					errors.c \
					ft_free.c \
					img_to_win.c \
					key_handler.c \
					pathfinding.c \
					player.c \
					read.c \
					render.c \
					so_long.c \
					verify_map.c

BONUS_SRCS = 		antag_key_handler_bonus.c \
					datas_bonus.c \
					errors_bonus.c \
					exit_handler_bonus.c \
					ft_free_bonus.c \
					get_img_from_file_bonus.c \
					img_to_win_bonus.c \
					main_bonus.c \
					pathfinding_bonus.c \
					player_key_handler_bonus.c \
					players_bonus.c \
					put_players_to_win_bonus.c \
					read_bonus.c \
					render_bonus.c \
					so_long_bonus.c \
					time_bonus.c \
					utils_bonus.c \
					verify_map_bonus.c	

#          ----------========== {     OBJS     } ==========----------

SRCS_DIR = mandatory/
OBJS_DIR = mandatory_objs/
SRCS_BONUS_DIR = bonus/
OBJS_BONUS_DIR = bonus_objs/

OBJS = $(addprefix $(OBJS_DIR), $(MANDATORY_SRCS:.c=.o))
OBJS_BONUS = $(addprefix $(OBJS_BONUS_DIR), $(BONUS_SRCS:.c=.o))

VPATH = $(shell find $(SRCS_DIR) $(SRCS_BONUS_DIR) -type d)

#           ----------========== {    RULES    } ==========----------

all:
	@$(MAKE) $(NAME)

bonus:
	@$(MAKE) $(BONUS_NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	@$(MAKE) -C libft
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) $(MLX_MACOS_FLAGS) -o $@
	@printf "\n$(GREEN)$(NAME) created!$(DEFAULT)\n"	

$(BONUS_NAME):  $(OBJS_BONUS_DIR) $(OBJS_BONUS)
	@$(MAKE) -C libft
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIB) $(MLX_MACOS_FLAGS) -o $@
	@printf "\n$(GREEN)$(BONUS_NAME) created!$(DEFAULT)\n"

$(OBJS_DIR)%.o:%.c
	@$(CC) $(CFLAGS) $(HDDIR) $(LIB_INC) -c $< -o $@
	@printf "$(GREEN).$(DEFAULT)"

$(OBJS_BONUS_DIR)%.o:%.c
	@$(CC) $(CFLAGS) $(HDDIR) $(LIB_INC) -c $< -o $@
	@printf "$(GREEN).$(DEFAULT)"
	
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_BONUS_DIR):
	@mkdir -p $(OBJS_BONUS_DIR)

clean:
	@$(MAKE) -C libft clean
	@$(RMF) $(OBJS) $(OBJS_BONUS)
	@$(RMD) $(OBJS_DIR) $(OBJS_BONUS_DIR)
	@printf "$(YELLOW)object files for $(NAME) && $(BONUS_NAME) cleaned!$(DEFAULT)\n"


fclean:
	@$(MAKE) clean
	@$(MAKE) -C libft fclean
	@$(RMF) $(NAME) $(BONUS_NAME)
	@printf "$(RED)executables for $(NAME) && $(BONUS_NAME) cleaned!$(DEFAULT)\n"

re: 
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all bonus clean fclean re

#           ----------========== {    COLORS    } ==========----------

RED = \033[1;31m
GREEN = \033[1;32m
GREEN_BG = \033[1;42m
YELLOW = \033[1;33m
DEFAULT = \033[0m