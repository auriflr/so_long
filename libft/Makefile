NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

SRC_DIRS := ft_fd ft_is ft_lst ft_mem ft_pri ft_str
SRCS := $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.c))

OBJS := $(SRCS:.c=.o)
	
.c.o:
	@mkdir -p $(dir $@)
	${CC} ${CFLAGS} -c $< -o $@
	
$(NAME): ${OBJS}
	${AR} ${NAME} ${OBJS}

all: $(NAME)

clean:
	${RM} ${OBJS} ${OBJS_B}

fclean: clean
	${RM} ${NAME}

re: fclean all

bonus: $(NAME) ${OBJS_B}
	${AR} ${NAME} ${OBJS} ${OBJS_B}

.PHONY: all bonus clean fclean re
