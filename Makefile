NAME = so_long

CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -framework OpenGL -framework AppKit

MINILIBX_PATH = ./mlx2
MINILIBX = $(MINILIBX_PATH)/libmlx.a

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

SRC = src/main.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MINILIBX)
	gcc $(OBJ) $(LDFLAGS) $(LIBFT) $(MINILIBX) -o $(NAME)
	@echo "\033[0;32mso_long is ready"

%.o: %.c
	gcc $(CFLAGS) -I/usr/include -I$(LIBFT_PATH) -O3 -c $< -o $@

clean: 
	rm -f $(OBJ)
	make -C $(MINILIBX_PATH) clean
	make -C $(LIBFT_PATH) clean

$(MINILIBX):
	chmod 777 $(MINILIBX_PATH)
	make -C $(MINILIBX_PATH)

$(LIBFT):
	make -C $(LIBFT_PATH)
