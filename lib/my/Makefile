##
## EPITECH PROJECT, 2021
## MAKEFILE
## File description:
## c pool Makefile
##

SRC	=	my_putchar.c	\
		my_putstr.c	\
		my_strcat.c	\
		my_strncat.c	\
		my_swap.c	\
		my_revstr.c	\
		my_strlen.c	\
		my_strcmp.c	\
		nbr_to_str.c \
		my_strncmp.c	\
		my_putstr_error.c	\
		my_get_nbr.c	\

CPPFLAGS	=	-I./../../include

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME)  $(OBJ)
	make clean

clean: 	clean
	@rm -f $(OBJ)
	@rm -rf *~

fclean	: clean
	@rm -rf $(NAME)

re	: clean all
