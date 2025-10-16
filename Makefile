NAME = so_long

CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -framework OpenGL -framework AppKit

MINILIBX_PATH = ./mlx2
MINILIBX = $(MINILIBX_PATH)/libmlx.a

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

SRC = src/main.c src/map_parsing.c src/flood_fill.c src/close.c src/create.c src/player.c src/images.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MINILIBX)
	gcc $(OBJ) $(LDFLAGS) $(LIBFT) $(MINILIBX) -o $(NAME)
	@echo "\033[0;32mso_long compiled OK! Hope you're ready to play!"

%.o: %.c
	gcc $(CFLAGS) -I/usr/include -I$(LIBFT_PATH) -O3 -c $< -o $@

clean: 
	rm -f $(OBJ)
	make -C $(MINILIBX_PATH) clean
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(MINILIBX_PATH) clean
	make -C $(LIBFT_PATH) clean

re: fclean all

$(MINILIBX):
	chmod 777 $(MINILIBX_PATH)
	make -C $(MINILIBX_PATH)

$(LIBFT):
	make -C $(LIBFT_PATH)

.PHONY: all clean fclean re