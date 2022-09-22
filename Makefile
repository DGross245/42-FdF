# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgross <dgross@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 19:03:57 by dgross            #+#    #+#              #
#    Updated: 2022/09/22 13:48:38 by dgross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= fdf

LIBFT 		= libft/libft.a

SRC 		= main.c event.c read_map.c utils.c utils2.c pixel_draw.c

OBJ_DIR		= ./obj/

OBJ			= $(addprefix $(OBJ_DIR),$(SRC:.c=.o))

CC			= cc

CFLAGS		= -Wall -Wextra -Werror -g

INCLUDES	= -I./includes -I./libft/includes -I./MLX42/include/MLX42

LINCLUDES	= -L./libft

GLFW 		= -lglfw -L "/Users/dgross/.brew/opt/glfw/lib/"

MLX			= MLX42/libmlx42.a

all: $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

mlx:
	@$(MAKE) -C ./MLX42
	
$(LIBFT):
	@$(MAKE) -C ./libft

obj/%.o: src/%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT) mlx obj $(OBJ)
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