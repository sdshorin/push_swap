# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bjesse <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/06 17:09:44 by bjesse            #+#    #+#              #
#    Updated: 2019/06/18 21:22:39 by bjesse           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

SOURCE = checker.c exe_command_2.c exe_command.c stack_check.c stack.c

OBJ = $(patsubst %.c,%.o,$(SOURCE))

LIB = libft/libft.a

all: $(NAME)


$(NAME): $(OBJ) lib
	gcc -g -Wall -Wextra -Werror -o $(NAME) $(SOURCE:.c=.o) $(LIB)

lib:
	make -C ./libft


%.o: %.c
	gcc -g -Wall -Wextra -Werror -c -o $@ $<

clean:
	/bin/rm -f $(SOURCE:.c=.o)
	make -C ./libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C ./libft fclean

re: fclean all
