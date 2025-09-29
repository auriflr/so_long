NAME = libftprintf.a

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

INCDIR = ../lib

SRCS = ft_printf.c ft_printf_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(INCDIR)ft_printf.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re