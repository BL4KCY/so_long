# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 10:12:32 by melfersi          #+#    #+#              #
#    Updated: 2024/01/18 11:41:09 by melfersi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# command and their flags
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
CC = cc
AR = ar -crs
INCLUDES = includes

#diractories
OBJ_DIR = obj
BDIR_OB = bns_obj
SRC_DIR  = src
BNS_DIR = bonus
INCLUDES = includes

#file names
FIlES = ft_atoi.c ft_calloc.c ft_isalpha.c ft_isdigit.c ft_itoa.c ft_memcmp.c\
		ft_memmove.c ft_putchar_fd.c ft_putnbr_fd.c ft_split.c ft_strdup.c ft_strjoin.c\
		ft_strlcpy.c ft_strmapi.c ft_strnstr.c ft_strtrim.c ft_tolower.c ft_bzero.c\
		ft_isalnum.c ft_isascii.c ft_isprint.c ft_memchr.c ft_memcpy.c ft_memset.c\
		ft_putendl_fd.c ft_putstr_fd.c ft_strchr.c ft_striteri.c ft_strlcat.c ft_strlen.c\
		ft_strncmp.c ft_strrchr.c ft_substr.c ft_toupper.c ft_printf.c ft_memprint.c\
		ft_putchar.c ft_putnbr.c ft_putstr.c ft_hexprint.c ft_puts.c\
		ft_get_next_line.c ft_get_next_line_utils.c

BONUS_FIlES = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c\
				ft_lstiter.c ft_lstlast.c ft_lstnew.c ft_lstsize.c

#patterns subs
SOURCES = $(FIlES:ft_%.c=$(SRC_DIR)/ft_%.c)

BONUS_SOURCES = $(BONUS_FIlES:ft_%.c=$(BNS_DIR)/ft_%.c)

OBJECTS = $(SOURCES:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

BONUS_OBJECTS = $(BONUS_SOURCES:$(BNS_DIR)%.c=$(BDIR_OB)%.o)

# static library name
NAME = libft.a

# Rules

$(NAME):$(OBJECTS)

bonus: $(BONUS_OBJECTS)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -I$(INCLUDES) -o $@
	@$(AR) $(NAME) $@

$(BDIR_OB)/%.o:$(BNS_DIR)/%.c
	@mkdir -p $(BDIR_OB)
	@$(CC) $(CFLAGS) -c $< -I$(INCLUDES) -o $@
	@$(AR) $(NAME) $@

clean:
	$(RM) $(OBJ_DIR)
	$(RM) $(BDIR_OB)

fclean: clean
	$(RM) $(NAME)

all: $(NAME) bonus

re: fclean all

.PHONY: clean
