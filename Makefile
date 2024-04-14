# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/16 00:32:47 by sel-hasn          #+#    #+#              #
#    Updated: 2024/04/04 02:40:49 by sel-hasn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus
CFLAGS_COMPILING= -Wall -Werror -Wextra -I/usr/include -Imlx_linux  #tocompile in linux
CFLAGS_LINKING= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz #link in linux
SRC = mandatory/so_long.c mandatory/get_next_line.c mandatory/utils.c \
mandatory/utils1.c mandatory/utils2.c mandatory/utils3.c mandatory/parsing.c \
mandatory/utils4.c mandatory/moves.c
BSRC = bonus/so_long.c bonus/get_next_line.c bonus/utils.c bonus/utils1.c \
bonus/utils2.c bonus/utils3.c bonus/parsing.c bonus/utils4.c bonus/moves.c \
bonus/moves_enemy.c bonus/enemy_handl.c bonus/utils5.c
OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)
FLAGS =  #-Wall -Werror -Wextra #-g -fsanitize=address
CC = cc 
RM = rm -f
HEDR = so_long.h

#$(NAME) : $(OBJ)
#	$(CC) $(FLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS_LINKING) -o $(NAME)

$(NAME_BONUS) : $(BOBJ)
	$(CC) $(BOBJ) $(CFLAGS_LINKING) -g -fsanitize=address -o $(NAME_BONUS)

#%.o : %.c so_long.h
#	$(CC) $(FLAGS) -Imlx -c $< -o $@
mandatory/%.o: mandatory/%.c mandatory/so_long.h
	$(CC) $(CFLAGS_COMPILING) -c $< -o $@

bonus/%.o: bonus/%.c bonus/so_long_bonus.h
	$(CC) $(CFLAGS_COMPILING) -c $< -o $@

all : $(NAME)

bonus : $(NAME_BONUS)

clean :
	$(RM) $(OBJ) $(BOBJ)

fclean : clean
	$(RM) $(NAME) $(NAME_BONUS)

re : fclean all