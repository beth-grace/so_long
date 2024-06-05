CC = cc
CFLAGS = -Wall -Werror -Wextra -Iminilibx -Ilibft
NAME = so_long
SRC = new_window.c

OBJ = $(patsubst %.c,%.o,$(SRC))
LFLAGS =

UNAME := $(shell uname -s)
ifeq ($(UNAME),Darwin)
	CFLAGS += -DMAC_OS
	FMLX = minilibx
	LFLAGS += -framework OpenGL -framework AppKit
endif
ifeq ($(UNAME),Linux)
	CFLAGS += -DLINUX
	FMLX = minilibx-linux
	LFLAGS += -lXext -lX11 -lm
endif


all: $(NAME)

$(NAME): libft mlx $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ -L$(FMLX) -Llibft -lmlx -lft $(LFLAGS)


libft:
	@$(MAKE) -C libft
	@echo "Made libft"

mlx:
	@$(MAKE) -C $(FMLX)
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
