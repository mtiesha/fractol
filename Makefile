# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtiesha < mtiesha@student.21-school.ru>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 17:56:30 by mtiesha           #+#    #+#              #
#    Updated: 2022/03/26 13:12:15 by mtiesha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = ./src/main.c ./src/keys.c ./src/render.c \
	./src/julia.c ./src/mandelbrot.c ./src/drow.c ./src/validator.c \
	./src/burningship.c ./src/utils.c ./src/init.c

HEADER = ./include/fractol.h

OBJ = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFT_LINKED = -Llibft -lft
MLX_LINKED = -Lmlx_linux -lmlx_Linux -Imlx_linux -L/usr/lib/ -Iusr/include -lXext -lX11 -lm -lz

all : $(NAME)

${NAME} : ${OBJ} Makefile $(HEADER)
	@$(MAKE) all -C ./mlx_linux
	@$(MAKE) all -C ./libft
	@clear
	@echo "\033[32mMLX Compiled"
	@echo "\033[32mLIBFT Compiled"
	@$(CC) $(OBJ) ${MLX_LINKED} ${LIBFT_LINKED} -o $(NAME)
	@echo "\033[32mProject Compiled"

%.o : %.c
	$(CC) ${CFLAGS} -I./include -I./libft -I./mlx_linux -O3 -c $< -o $@

clean :
	@$(MAKE) clean -C ./mlx_linux
	@$(MAKE) clean -C ./libft
	@rm -rf $(OBJ)
	@clear
	@echo "\033[32mClean"

fclean : clean
	@$(MAKE) fclean -C ./libft
	@$(RM) $(NAME)
	@clear
	@echo "\033[32mFclean"

re : fclean all

.PHONY : all clean fclean re
