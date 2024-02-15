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
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
CYAN = \033[0;36m
BLUE = \033[0;34m
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
	@echo "$(GREEN)Compiling $(NAME)...$(NC)"
	@$(CC) $(CFLAGS) $^ -I$(INCLUDES) -I$(LIB_INCLUDES) -lmlx -lXext -lX11 -o $@ || echo "$(RED)Compilation failed!$(NC)"

# impicit rule for mandatory
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(GREEN)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -I$(INCLUDES) -I$(LIB_INCLUDES) -c $< -o $@ || echo "$(RED)Compilation failed!$(NC)"

$(LIB)/%.a:
	@echo "$(GREEN)Compiling Libft...$(NC)"
	@$(MAKE) all -C $(LIB)
	@echo "$(GREEN)Libft compiled!$(NC)"

bonus:$(BONUS_NAME)

$(BONUS_NAME): $(NAME)

re: fclean all

all: $(NAME) $(BONUS_NAME)

#______cleaning______#
clean:
	@echo "$(BLUE)Cleaning...$(NC)"
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -C $(LIB) fclean
	@echo "$(YELLOW)Cleaning done!$(NC)"
fclean: clean
	@echo "$(BLUE)Full cleaning...$(NC)"
	@$(RM) $(NAME)
	@echo "$(YELLOW)Full cleaning done!$(NC)"
