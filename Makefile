# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/10 21:54:20 by cdelamar          #+#    #+#              #
#    Updated: 2024/05/13 17:12:30 by cdelamar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

LIBFT = lib/libft.a
LIBMLXLINUX = lib/libmlx_Linux.a

CC = cc
CFLAGS =	-g -Wall -Wextra -Werror -Iinclude
LFLAGS =	-Llib -lft -lmlx_Linux -lX11 -lXext

SRC_DIR = src/
PAR_DIR = src/parsing/
OBJ_DIR = obj/

FILES =	main args_checker str_manager map_checker gnl

PARS = $(addprefix $(PAR_DIR), $(addsuffix .c, $(FILES)))
SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(LIBMLXLINUX)
	@echo "\033[32m✔ Compilating sources files...\033[37m"
	@$(CC) -o $@ $(OBJS) $(LFLAGS)
	@echo "\033[32m✔ Executable created.\033[37m"

$(LIBFT):
	@make -C lib


$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(PAR_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJ_DIR)

fclean : clean
	@rm -rf $(NAME)
	@make fclean -C lib

re: fclean all

valgrind: $(NAME)
	valgrind --show-leak-kinds=all --leak-check=full --track-origins=yes --track-fds=yes --trace-children=yes ./$(NAME)

.PHONY: all clean fclean re bonus
$(OBJS): | $(LIBFT)