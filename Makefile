# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/29 14:54:41 by rmarguri          #+#    #+#              #
#    Updated: 2020/12/05 14:38:19 by rmarguri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRC = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s

OBJ = $(SRC:.s=.o)

COMPILE = nasm -fmacho64

%.o: %.s
	$(COMPILE) $<

all: $(NAME)

$(NAME): $(OBJ) main.c
	ar rcs $(NAME) $^
	
go: re
	rm -rf *.o
	gcc main.c -L. -lasm
	touch file
	chmod 777 file
	touch donttouchme
	chmod -w donttouchme
	touch readfile
	chmod 777 readfile
	echo "read this for me" > readfile
	./a.out

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	rm -f donttouchme
	rm -f file
	rm -f readfile
	rm -f a.out

re: fclean all

.PHONY: all clean fclean re go