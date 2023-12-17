SRCS	= $(wildcard *.c)
OBJS	= $(SRCS:.c=.o)
CFLAGS 	= -Wall -Wextra -Werror
NAME	= fractol
LIBX	= minilibx-linux/libmlx_Darwin.a
LIBFT	= libft/libft.a

all: $(NAME)

re: fclean all

debug: $(OBJS) $(LIBX) $(LIBFT)
	cc -g3 -gdwarf-4 $(CFLAGS) -L/opt/homebrew/Cellar/libxext/1.3.5/lib -lXext -L/opt/homebrew/Cellar/libx11/1.8.7/lib -lX11 -Lminilibx-linux/ -lmlx $^ -o $(NAME)_debug

$(NAME): $(OBJS) $(LIBX) $(LIBFT)
	cc $(CFLAGS) -L/opt/homebrew/Cellar/libxext/1.3.5/lib -lXext -L/opt/homebrew/Cellar/libx11/1.8.7/lib -lX11 -Lminilibx-linux/ -lmlx $^ -o $(NAME)

$(LIBX):
	make -C minilibx-linux/

$(LIBFT):
	make -C libft/

fclean:
	rm -rf *.o $(NAME)
	rm -rf minilibx-linux/*.o
	make -C libft/ clean

make re : fclean all
