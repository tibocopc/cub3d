# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xx <xx@student.42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/28 14:31:24 by aaiache           #+#    #+#              #
#    Updated: 2025/11/07 14:22:41 by xx               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = cub3d
CC      = cc
CFLAGS  = -g3 -Wall -Wextra -Werror -Ilibft
RM      = rm -f

BUILD_DIR = objs

SRCS = srcs/main.c srcs/parsing/check_map.c srcs/parsing/get_map.c srcs/parsing/get_texture.c srcs/parsing/get_colors.c \
			srcs/parsing/get_params.c
ALL_SRCS   = $(SRCS)
OBJS       = $(ALL_SRCS:%.c=$(BUILD_DIR)/%.o)

$(BUILD_DIR)/%.o: %.c includes/cub3d.h
	@mkdir -p $(dir $@)
	@echo "\033[0;32mCompilation de $<"
	@$(CC) $(CFLAGS) -c $< -o $@

all: libft $(NAME)
	@echo "\033[0;32m\n----Compilation terminée avec succès.----"

libft:
	@echo "\033[0;32m-----Compilation de la libft-----\033[0m"
	@$(MAKE) -C libft

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) libft/ft_printf/ft_printf.a libft/libft.a -o $(NAME)

clean:
	@echo "\033[0;33mSuppression des fichiers objets"
	@$(RM) -r $(BUILD_DIR)

fclean: clean
	@echo "\033[0;33mSuppression de l'exécutable $(NAME)"
	@$(RM) $(NAME)
	@$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re libft 