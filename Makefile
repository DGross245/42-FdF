# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgross <dgross@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 19:03:57 by dgross            #+#    #+#              #
#    Updated: 2023/05/21 15:00:52 by dgross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= fdf

LIBFT 		= libft/libft.a

SRC 		= main.c event.c read_map.c utils.c utils2.c pixel_draw.c convert.c event2.c utils3.c

OBJ_DIR		= ./obj/

OBJ			= $(addprefix $(OBJ_DIR),$(SRC:.c=.o))

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

INCLUDES	= -I./includes -I./libft/includes -I./MLX42/include/MLX42

LINCLUDES	= -L./libft -lft

GLFW 		= -lglfw -L "/Users/$(USER)/goinfre/.brew/opt/glfw/lib/"

MLX			= MLX42/build/libmlx42.a

all: $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

$(MLX):
	cd MLX42 && cmake -B build
	cd MLX42 && cmake --build build -j4

obj/%.o: src/%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(MLX) obj $(OBJ)
	@$(MAKE) -C ./libft
	@$(CC) $(OBJ) $(CFLAGS) $(INCLUDES) $(LIBFT) $(MLX) $(GLFW) $(LINCLUDES) -o $(NAME)

clean:
	@make clean -C libft/
	@rm -rf MLX42/build
	@rm -rf obj

fclean: clean
	@make fclean -C libft/
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus