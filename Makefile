CC = cc
CFLAGS = -Wall -Werror -Wextra -Iminilibx -Ilibft
NAME = so_long
SRC = new_window.c

OBJ = $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

$(NAME): libft mlx $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ -Lminilibx -Llibft -lmlx -lft -framework OpenGL -framework AppKit


libft:
	@$(MAKE) -C libft
	@echo "Made libft"

mlx:
	@$(MAKE) -C minilibx
	@echo "Made mlx"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C libft fclean
	make -C minilibx clean

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re libft mlx
