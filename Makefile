# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romain <romain@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/17 17:00:39 by romain            #+#    #+#              #
#    Updated: 2024/02/22 11:43:19 by romain           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES	=	color.c \
				error.c \
				hook.c \
				main.c \
				render_julia.c \
				render_mandelbrot.c \
				window.c \
				mouvement.c \
				zoom.c

CFLAGS 		=	-Wall -Wextra -Werror
NAME		=	fractol
NAME_MAC	=	fractol_MAC
LIBX		=	minilibx-linux/libmlx_Linux.a
LIBX_MAC	=	minilibx-linux/libmlx_Darwin.a
LIBFT		=	libft/libft.a
SRC_DIR		=	src
OBJ_DIR		=	obj
INCLUDES	=	includes
FT_LST		=	ft_lst/liblst.a
SRC 		=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
MAC_FLAGS	=	-L/opt/homebrew/Cellar/libxext/1.3.5/lib -lXext -L/opt/homebrew/Cellar/libx11/1.8.7/lib -lX11
all: $(NAME)

remac: fclean mac 

re: fclean all

mac: $(NAME_MAC)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -g3 -I$(INCLUDES) -c -o $@ $<

debug: $(OBJS) $(LIBX) $(LIBFT) $(FT_LST)
	$(CC) $(CFLAGS) -g3 -gdwarf-4 $(MAC_FLAGS) -Lminilibx-linux/ -lmlx $^ -o $(NAME)_debug

$(NAME_MAC): $(OBJS) $(LIBX_MAC) $(LIBFT) $(FT_LST)
	$(CC) $(CFLAGS)   $(MAC_FLAGS) -Lminilibx-linux/ -lmlx $^ -o $@

$(NAME): $(OBJS) $(LIBX) $(LIBFT) $(FT_LST)
	$(CC) $(CFLAGS) -lXext -lX11 -Lminilibx-linux/ -lmlx $^ -o $@

$(LIBX_MAC):
	make -C minilibx-linux/

$(LIBX):
	make -C minilibx-linux/

$(LIBFT):
	make -C libft/

$(FT_LST):
	make -C ft_lst/

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf *.o $(NAME) $(NAME)_debug $(NAME_MAC)
	make -C minilibx-linux/ clean
	make -C libft/ fclean

.PHONY: all clean fclean re
