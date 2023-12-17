SRCS	= $(wildcard *.c)
OBJS	= $(SRCS:.c=.o)
CFLAGS 	= -Wall -Wextra -Werror
NAME	= fractol
LIBX	= minilibx-linux/libmlx_Darwin.a

all: $(NAME)

re: fclean all

$(NAME): $(OBJS) $(LIBX)
	cc $(CFLAGS) -L/opt/homebrew/Cellar/libxext/1.3.5/lib -lXext -L/opt/homebrew/Cellar/libx11/1.8.7/lib -lX11 -Lminilibx-linux/ -lmlx $^ -o $(NAME)

$(LIBX) : 
	make -C minilibx-linux/

fclean:
	rm -rf *.o $(NAME)
	rm -rf minilibx-linux/*.o

make re : fclean all
