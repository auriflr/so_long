NAME = so_long
CFLAGS = -Wall -Wextra -Werror -I/usr/include -I$(LIBFT_PATH)
MLXFLAGS = -L$(MINILIBX_PATH) -lmlx -lXext -lX11 -lm
MINILIBX_PATH = ./mlx
MINILIBX = $(MINILIBX_PATH)/libmlx.a
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
SRC = src/main.c src/mcheck.c src/flood_fill.c src/close.c \
      src/create.c src/upnmove.c src/graphics.c src/mread.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJ)
	gcc $(OBJ) $(LIBFT) $(MINILIBX) -lXext -lX11 -lm -o $(NAME)
	@echo "\033[0;32mso_long compiled OK! Hope you're ready to play!"

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(MINILIBX_PATH) clean
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(MINILIBX_PATH) clean
	make -C $(LIBFT_PATH) fclean

re: fclean all

$(MINILIBX):
	chmod 777 $(MINILIBX_PATH)
	make -C $(MINILIBX_PATH)

$(LIBFT):
	make -C $(LIBFT_PATH)

.PHONY: all clean fclean re