SRCS	= $(wildcard *.c)
OBJS	= $(SRCS:.c=.o)
CFLAGS 	= -Wall -Wextra -Werror
NAME	= fractol
LIBX	= mlx/libmlx.a

all: $(NAME)

re: fclean all

$(NAME): $(OBJS) $(LIBX)
	$(CC) $(CFLAGS) -framework OpenGL -framework AppKit $^ -o $(NAME)


$(LIBX) : 
	make -C minilibx-linux/

fclean:
	rm -rf *.o $(NAME)
	rm -rf mlx/*.o

make re : fclean all
