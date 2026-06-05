NAME = fractol
CC = cc
CFLAGS = -Wextra -Werror -Wall
MLX_FLAGS = -Lmini -lmlx -L/usr/lib -lX11 -lXext -lm -lpthread
MLX_DIR = minilibx-linux
SRC = TOOOOOOOOOOOOOODOOOOOOOOOOOOOO
OBJ = $(SRC:.c=.o)
MLX = $(MLX_DIR)/libmlx.a

all: $(NAME)

$(NAME) : $(MLX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)

$(MLX):
	make -C $(MLX_DIR)

clean:
	rm -rf $(OBJ)
	make -C $(MLX_DIR) clean

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re