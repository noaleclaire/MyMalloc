##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

SRC = 	src/malloc.c		\
		src/block.c			\
		src/free.c			\
		src/calloc.c		\
		src/realloc.c		\
		src/reallocarray.c

OBJ = $(SRC:%.c=%.o)

CFLAGS = -Wall -I./include -fpic

NAME = libmy_malloc.so

CC = gcc

RM = rm -f

$(NAME) :	$(OBJ)
		$(CC) -shared -o $(NAME) $(OBJ) $(CFLAGS)

all:		$(NAME)

clean :
			$(RM) $(OBJ)

fclean :	clean
			$(RM) $(NAME)

re:			fclean all

unit_tests:	fclean all
		make -C ./tests

tests_run:	unit_tests
		./tests/unit_test

.PHONY:	all clean fclean re