##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

SRC     =	my_count_nb_char_in_str.c	\
			my_is_alpha.c				\
			my_is_lower.c				\
			my_is_num.c					\
			my_is_printable.c			\
			my_is_upper.c				\
			my_load_file_in_array.c		\
			my_load_file_in_memory.c	\
			my_put_char.c				\
			my_put_str.c				\
			my_rev_str.c				\
			my_show_mem.c				\
			my_show_str.c				\
			my_show_word_array.c		\
			my_str_capitalize.c			\
			my_str_cat.c				\
			my_str_cmp.c				\
			my_str_cpy.c				\
			my_str_is_alpha.c			\
			my_str_is_lower.c			\
			my_str_is_num.c				\
			my_str_is_printable.c		\
			my_str_is_upper.c			\
			my_str_len.c				\
			my_str_low_case.c			\
			my_str_n_cat.c				\
			my_str_n_cmp.c				\
			my_str_n_cpy.c				\
			my_str_str.c				\
			my_str_to_word_array.c		\
			my_str_up_case.c			\
			spliter/add_word.c			\
			spliter/change_begin_str.c	\
			spliter/generate_tab.c		\
			spliter/spliter.c			\
			my_swap.c

DIR_SRC	=		$(addprefix src/, $(SRC))

TEST	=	test_my_put_char.c				\
			test_my_put_str.c				\
			test_my_rev_str.c				\
			test_my_show_word_array.c		\
			test_my_str_capitalize.c		\
			test_my_str_cat.c				\
			test_my_str_cmp.c				\
			test_my_str_cpy.c				\
			test_my_str_is_alpha.c			\
			test_my_str_is_lower.c			\
			test_my_str_is_num.c			\
			test_my_str_is_printable.c		\
			test_my_str_is_upper.c			\
			test_my_str_len.c				\
			test_my_str_low_case.c			\
			test_my_str_n_cat.c				\
			test_my_str_n_cmp.c				\
			test_my_str_n_cpy.c				\
			test_my_str_str.c				\
			test_my_str_to_word_array.c		\
			test_my_str_up_case.c			\
			test_my_swap.c

DIR_TESTS	=		$(addprefix tests/, $(TEST))

OBJ			=		$(DIR_SRC:.c=.o)

OBJ_TESTS	=		$(DIR_TESTS:.c=.o)

CPPFLAGS	= -I include -ggdb3

NAME		=		../libmy_str.a

$(NAME):		$(OBJ)
	ar rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf unit_tests
	rm -rf *.gcov
	rm -f $(NAME)

re: fclean all

unit_tests:
	mkdir unit_tests

unit_tests/unit_tests:	re	unit_tests $(OBJ)
		gcc -o unit_tests/unit_tests $(OBJ) $(DIR_TESTS) -I include/\
		--coverage -lcriterion

tests_run:	unit_tests/unit_tests
			./unit_tests/unit_tests

.PHONY: all clean fclean re tests_run
