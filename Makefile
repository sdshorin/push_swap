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

NAME_1 = checker
NAME_2 = push_swap

SOURCE =  exe_command_2.c exe_command.c stack_check.c stack.c stack_work.c \
print_answer.c sort_step_common.c manage_command.c sort_step_short.c tools.c
SOURCE_N_1 = checker.c
SOURCE_N_2 = push_swap.c

OBJ = $(patsubst %.c,%.o,$(SOURCE))
OBJ_N_1 = $(patsubst %.c,%.o,$(SOURCE_N_1))
OBJ_N_2 = $(patsubst %.c,%.o,$(SOURCE_N_2))

LIB = libft/libft.a

all: lib $(NAME_1) $(NAME_2)

$(NAME_1): $(LIB) $(OBJ) $(OBJ_N_1)
	gcc -g -Wall -Wextra -Werror -o $(NAME_1) $(SOURCE:.c=.o) $(SOURCE_N_1:.c=.o) $(LIB)

$(NAME_2): $(LIB) $(OBJ) $(OBJ_N_2)
	gcc -g -Wall -Wextra -Werror -o $(NAME_2) $(SOURCE:.c=.o) $(SOURCE_N_2:.c=.o) $(LIB)

$(LIB):
	$(MAKE) -C ./libft

lib:
	$(MAKE) -C ./libft

%.o: %.c $(LIB)
	gcc -g -Wall -Wextra -Werror -c -o $@ $<

clean:
	/bin/rm -f $(SOURCE:.c=.o)
	/bin/rm -f $(SOURCE_N_1:.c=.o)
	/bin/rm -f $(SOURCE_N_2:.c=.o)
	make -C ./libft clean

fclean: clean
	/bin/rm -f $(NAME_1)
	/bin/rm -f $(NAME_2)
	make -C ./libft fclean

re: fclean all
