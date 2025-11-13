NAME = so_long
CFLAGS = gcc -Wall -Wextra -Werror -I/usr/include -I$(LIBFT_PATH)
MLXFLAGS = -L$(MINILIBX_PATH) -lmlx -lXext -lX11 -lm
MINILIBX_PATH = ./mlx
MINILIBX = $(MINILIBX_PATH)/libmlx.a
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
SRC = src/main.c src/parsing.c src/flood_fill.c src/close.c \
      src/init.c src/moves.c src/rendering.c src/map.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJ)
	@$(CFLAGS) $(OBJ) $(LIBFT) $(MINILIBX) -lXext -lX11 -lm -o $(NAME)
	@printf "\n\033[0;37m"
	@echo "\033[0;34mso_long compiled OK! Hope you're ready to play!"
	@echo "\033[0;34mThe captain requested his kitten to retrieve all the maps. Have fun!"

%.o: %.c
	@mkdir -p $(dir $@)
	@$(CFLAGS) -c $< -o $@

clean:
	@$(RM) -f $(OBJ)
	@$(MAKE) -C $(MINILIBX_PATH) clean
	@$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	@$(RM) -f $(NAME)
	@$(MAKE) -C $(MINILIBX_PATH) clean
	@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

$(MINILIBX):
	chmod 777 $(MINILIBX_PATH)
	@$(MAKE) -C $(MINILIBX_PATH)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

.PHONY: all clean fclean re