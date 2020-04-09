##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## compiles libmy
##

SRC = 	my_function_test.c \
		tests_my_putstr.c \
		tests_my_putchar.c \
		test_exec_function.c \
		tests_my_strcat.c \
		tests_my_strlen.c \
		tests_my_strncmp.c \
		tests_my_str_to_world_array.c \
		tests_my_str_to_world_array_colon.c \
		tests_minishel1.c \
		tests_recode_function.c \
		../src/minishel1.c \
		../src/init_struct.c \
		../src/recode_function.c \
		../src/exec_function.c \
		../lib/my_strncmp.c \
		../lib/my_putchar.c \
		../lib/my_strlen.c \
		../lib/my_strcat.c \
		../lib/my_putstr.c \
		../lib/my_str_to_world_array_colon.c \
		../lib/my_str_to_world_array.c \

CFLAGS	=	-I ../include --coverage

OBJ	=	$(SRC:.c=.o)

LDFLAGS	=	-L../lib -lgnl -lcriterion

NAME	=	unit_tests

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS) --coverage

all:	$(NAME)

re:	fclean all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm *.gcno *.gcda
