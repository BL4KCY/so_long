#______command and their flags______#
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
CC = gcc
AR = ar -crs
INCLUDES = includes

#______directories______#
OBJ_DIR = obj
SRC_DIR = src
INCLUDES = includes
LIB_INCLUDES = libft/includes

#______colors______#
RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;34m
BOLD = \033[1m
UNDERLINE = \033[4m
NC = \033[0m

#______mandatory and bonus files______#
FILES = main.c parse_map.c parse_map_utils.c exit.c init.c init_utils.c input.c moves.c\
		player.c player_utils.c rendering.c rendering_utils.c gameOver.c\
		enemy_move.c enemy_move_utils.c

#______patterns and substitutions______#
SOURCES = $(FILES:%.c=$(SRC_DIR)/%.c)
OBJECTS = $(SOURCES:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

#______static library name______#
NAME = so_long
BONUS_NAME = $(NAME)_bonus
LIB = libft

#______________Rules______________#

$(NAME): $(OBJECTS) $(LIB)/libft.a
	@echo "$(BLUE)Compiling $@...$(NC)"
	@$(CC) $(CFLAGS) $^ -I$(INCLUDES) -I$(LIB_INCLUDES) -lmlx -lXext -lX11 -o $@ || echo "$(RED)$(UNDERLINE)$(BOLD)$@ Compilation failed!$(NC)"
	@if [ -f $(NAME) ]; then echo "$(GREEN)$(UNDERLINE)$(BOLD)$@ compiled!$(NC)"; fi

# impicit rule for mandatory
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(BLUE)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -I$(INCLUDES) -I$(LIB_INCLUDES) -c $< -o $@ || echo "$(RED)$(UNDERLINE)$(BOLD)$< Compilation failed!$(NC)"

$(LIB)/%.a:
	@echo "$(BLUE)Compiling Libft...$(NC)"
	@$(MAKE) all -C $(LIB) >> /dev/null || echo "$(RED)$(UNDERLINE)$(BOLD)Libft compilation failed!$(NC)"
	@echo "$(GREEN)$(UNDERLINE)$(BOLD)Libft compiled!$(NC)"

bonus:$(BONUS_NAME)

$(BONUS_NAME): $(NAME)

re: fclean all

all: $(NAME) $(BONUS_NAME)

#______cleaning______#
clean:
	@echo "$(BLUE)Cleaning...$(NC)"
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -C $(LIB) fclean >> /dev/null || echo "$(RED)Libft cleaning failed!$(NC)"
	@if [ ! -d $(OBJ_DIR) ]; then echo "$(GREEN)$(UNDERLINE)$(BOLD)Cleaning done!$(NC)"; fi
fclean:
	@echo "$(BLUE)Full cleaning...$(NC)"
	@$(RM) $(NAME)
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -C $(LIB) fclean >> /dev/null || echo "$(RED)Libft cleaning failed!$(NC)"
	@if [ ! -f $(NAME) ]; then echo "$(GREEN)$(UNDERLINE)$(BOLD)Full cleaning done!$(NC)"; fi
