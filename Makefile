# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/10 07:14:57 by sydauria          #+#    #+#              #
#    Updated: 2022/05/22 18:56:12 by sydauria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
CC= gcc
CFLAGS= -Wall -Wextra -Werror


SRC = ft_printf.c converter.c converter_itoas.c utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

.c.o:
	gcc $(CFLAGS) -c $< -o $(<:.c=.o)
	
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

so:
	$(CC) -c -fPIC $(CFLAGS) $(SRC)
	gcc -shared -o libftprintf.so $(OBJ)
	
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

