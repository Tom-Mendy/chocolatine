##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

SRC			=	main.c \
				my_project.c

DIR_SRC		=	$(addprefix src/, $(SRC))

TEST		=	test.c

DIR_TESTS	=	$(addprefix tests/, $(TEST))

OBJ     	=	$(DIR_SRC:.c=.o)

LDLIBS		=	-L lib/ -l my_str -l my_printf -l my_linked_list -l my_int

CPPFLAGS	=	-I include/ -I lib/my_str/include -I lib/my_printf/include\
				-I lib/my_linked_list/include -I lib/my_int/include

CFLAGS		=	-Wall -Wextra -ggdb3

NAME		=	a.out

LIBS		=	lib/libmy_str.a\
				lib/libmy_printf.a\
				lib/libmy_linked_list.a\
				lib/libmy_int.a

all: make_libs $(NAME)

$(NAME):	$(LIBS) $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDLIBS) $(CPPFLAGS) $(CFLAGS)

make_libs:
	make -C lib/my_int
	make -C lib/my_str
	make -C lib/my_printf
	make -C lib/my_linked_list

clean:
		make clean -C lib/my_int
		make clean -C lib/my_str
		make clean -C lib/my_printf
		make clean -C lib/my_linked_list
		rm -f $(OBJ)

fclean: clean
		make fclean -C lib/my_int
		make fclean -C lib/my_str
		make fclean -C lib/my_printf
		make fclean -C lib/my_linked_list
		rm -rf unit_tests
		rm -rf *.gcov
		rm -f $(NAME)

re:		fclean all

unit_tests:
	mkdir unit_tests

unit_tests/unit_tests:	re unit_tests
		make unit_tests/unit_tests -C lib/my_int
		make unit_tests/unit_tests -C lib/my_str
		gcc -o unit_tests/unit_tests src/my_project.c $(DIR_TESTS)\
		$(CPPFLAGS) $(LDLIBS) --coverage -lcriterion

tests_run:	unit_tests/unit_tests
		make tests_run -C lib/my_int
		make tests_run -C lib/my_str
		./unit_tests/unit_tests

.PHONY: all clean fclean re make_libs tests_run
