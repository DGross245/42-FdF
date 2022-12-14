# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgross <dgross@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 19:03:57 by dgross            #+#    #+#              #
#    Updated: 2022/10/03 18:37:02 by dgross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= fdf

LIBFT 		= libft/libft.a

SRC 		= main.c event.c read_map.c utils.c utils2.c pixel_draw.c convert.c event2.c utils3.c

OBJ_DIR		= ./obj/

OBJ			= $(addprefix $(OBJ_DIR),$(SRC:.c=.o))

CC			= cc

CFLAGS		= -Wall -Wextra -Werror -g

INCLUDES	= -I./includes -I./libft/includes -I./MLX42/include/MLX42

LINCLUDES	= -L./libft -lft

GLFW 		= -lglfw -L "/Users/dgross/.brew/opt/glfw/lib/"

MLX			= MLX42/libmlx42.a

all: $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

mlx:
	@$(MAKE) -C ./MLX42

obj/%.o: src/%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): mlx obj $(OBJ)
	@$(MAKE) -C ./libft
	@$(CC) $(OBJ) $(CFLAGS) $(INCLUDES) $(LIBFT) $(MLX) $(GLFW) $(LINCLUDES) -o $(NAME)

clean:
	@make clean -C libft/
	@make clean -C MLX42/
	@rm -rf obj

fclean: clean
	@make fclean -C libft/
	@make fclean -C MLX42/
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus