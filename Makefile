CC = cc
CFLAGS = -Wall -Werror -Wextra $(DEBUG_FLAGS) -Iminilibx -Ilibft
DEBUG_FLAGS =
NAME = so_long
SRC = main.c\
key_commands.c\
map.ber\
events.c\
errors.c\
put_images.c\

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

debug: fclean debug_cflags $(NAME)

debug_cflags:
	@$(eval DEBUG_FLAGS = -g)

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
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft mlx
