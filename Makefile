#______command and their flags______#
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -lXext -lX11
CC = gcc
AR = ar -crs
INCLUDES = includes

#______directories______#
OBJ_DIR = obj
BNS_DIR_OBJ = $(OBJ_DIR)_bonus
SRC_DIR = src
BNS_DIR = bns
INCLUDES = includes
LIB_INCLUDES = libft/includes

#______mandatory and bonus files______#
FILES = main.c parse_map.c parse_map_utils.c exit.c init.c init_utils.c input.c moves.c\
		player.c player_utils.c rendering.c rendering_utils.c gameOver.c
FILES_BONUS = main.c parse_map.c parse_map_utils.c exit.c init.c init_utils.c input.c moves.c\
		player.c player_utils.c rendering.c rendering_utils.c gameOver.c\
		enemy_move.c enemy_move_utils.c
#______patterns and substitutions______#
SOURCES = $(FILES:%.c=$(SRC_DIR)/%.c)
OBJECTS = $(SOURCES:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
BONUS_SRC = $(FILES_BONUS:%.c=$(BNS_DIR)/%_bonus.c)
BONUS_OBJ = $(BONUS_SRC:$(BNS_DIR)%.c=$(BNS_DIR_OBJ)%.o)

#______static library name______#
NAME = so_long
NAME_BONUS = bonus
LIB = libft

#______________Rules______________#

$(NAME): $(OBJECTS) $(LIB)/libft.a
	$(CC) $(CFLAGS) $^ -I$(INCLUDES) -I$(LIB_INCLUDES) $(MLXFLAGS) -o $@

$(NAME_BONUS): $(BONUS_OBJ) $(LIB)/libft.a
	$(CC) $(CFLAGS) $^ -I$(INCLUDES) -I$(LIB_INCLUDES) $(MLXFLAGS) -o $@

# impicit rule for mandatory
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDES) -I$(LIB_INCLUDES) -c $< $(MLXFLAGS) -o $@

# impicit rule for bonus
$(BNS_DIR_OBJ)/%.o: $(BNS_DIR)/%.c
	@mkdir -p $(BNS_DIR_OBJ)
	$(CC) $(CFLAGS) -I$(INCLUDES) -I$(LIB_INCLUDES) -c $< $(MLXFLAGS) -o $@

$(LIB)/%.a:
	$(MAKE) all -C $(LIB)

re: fclean all

all: $(NAME) $(NAME_BONUS)

#______cleaning______#
clean:
	$(RM) $(OBJ_DIR)
	$(RM) $(BNS_DIR_OBJ)
	$(MAKE) -C $(LIB) fclean
fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
