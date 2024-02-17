# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romain <romain@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/17 17:00:39 by romain            #+#    #+#              #
#    Updated: 2024/02/17 17:06:11 by romain           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	color.c \
				error.c \
				hook.c \
				main.c \
				render_julia.c \
				render_mandelbrot.c \
				window.c
OBJS		=	$(SRCS:.c=.o)
CFLAGS 		=	-Wall -Wextra -Werror
NAME		=	fractol
NAME_MAC	=	fractol_MAC
LIBX		=	minilibx-linux/libmlx_Linux.a
LIBX_MAC	=	minilibx-linux/libmlx_Darwin.a
LIBFT		=	libft/libft.a

all: $(NAME)

re: fclean all

mac: $(NAME_MAC)

debug: $(OBJS) $(LIBX) $(LIBFT)
	cc $(CFLAGS) -g3 -gdwarf-4 -L/opt/homebrew/Cellar/libxext/1.3.5/lib -lXext -L/opt/homebrew/Cellar/libx11/1.8.7/lib -lX11 -Lminilibx-linux/ -lmlx $^ -o $(NAME)_debug

$(NAME_MAC): $(OBJS) $(LIBX_MAC) $(LIBFT)
	cc $(CFLAGS) -L/opt/homebrew/Cellar/libxext/1.3.5/lib -lXext -L/opt/homebrew/Cellar/libx11/1.8.7/lib -lX11 -Lminilibx-linux/ -lmlx $^ -o $(NAME)

$(NAME): $(OBJS) $(LIBX) $(LIBFT)
	cc $(CFLAGS) -L/opt/homebrew/Cellar/libxext/1.3.5/lib -lXext -L/opt/homebrew/Cellar/libx11/1.8.7/lib -lX11 -Lminilibx-linux/ -lmlx $^ -o $(NAME)

$(LIBX_MAC):
	make -C minilibx-linux/

$(LIBX):
	make -C minilibx-linux/

$(LIBFT):
	make -C libft/

fclean:
	rm -rf *.o $(NAME) $(NAME)_debug
	rm -rf minilibx-linux/*.o
	make -C libft/ clean

make re : fclean all
