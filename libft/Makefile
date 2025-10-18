# libft/Makefile

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

# Source directories
SRC_DIRS := ft_fd ft_is ft_lst ft_mem ft_pri ft_str gnl

# Gather all .c files in those directories
SRCS := $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.c))

# Create corresponding .o filenames
OBJS := $(SRCS:.c=.o)

all: $(NAME)

# Compile and archive
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# Pattern rule for compiling .c to .o (supports subdirectories)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

