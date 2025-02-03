##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## makefile hunter
##

my_lib	=	lib

MAIN	=	DUCKS

GON		=	hunter

BONUS	=	features

ERROR	=	error_handling

SRC		=	$(ERROR)/error_handling.c \
			$(GON)/$(MAIN)/main.c \
			$(GON)/$(BONUS)/music.c \
			$(GON)/$(BONUS)/menu.c \
			$(GON)/$(MAIN)/ducks_interactions.c \
			$(GON)/$(MAIN)/ducks.c \
			$(GON)/$(BONUS)/sprites.c \
			$(my_lib)/my_putstr.c \
			$(my_lib)/my_putchar.c \
			$(my_lib)/my_strlen.c \
			$(my_lib)/my_put_nbr.c \
			$(my_lib)/my_strcpy.c \
			$(my_lib)/my_printf.c \
			$(my_lib)/my_isalnum.c \
			$(my_lib)/handle_char.c \
			$(my_lib)/handle_str.c \
			$(my_lib)/handle_int.c \
			$(my_lib)/percent.c \
			$(my_lib)/handle_hex.c \
			$(my_lib)/handle_hexmaj.c \
			$(my_lib)/handle_oct.c \
			$(my_lib)/handle_ptr.c \
			$(my_lib)/handle_flottants.c \
			$(my_lib)/handle_e.c \
			$(my_lib)/my_put_unsigned_nbr.c \
			$(my_lib)/handle_unsigned.c \
			$(my_lib)/my_revstr.c \
			$(my_lib)/my_strncpy.c

OBJ		=	$(SRC:.c=.o)

EXEC	=	my_hunter

CFLAGS	+=	-W -Wall -Wextra -g

LIB		=	libmy.a

CFLAGS	+= -lcsfml-graphics -lcsfml-window

CFLAGS	+=	-lcsfml-audio -lcsfml-network -lcsfml-system

all:			$(EXEC) $(LIB) $(my_LIB) $(GON)

$(EXEC): $(SRC)
		gcc -g -o $(EXEC) $(SRC) $(CFLAGS)

$(LIB):		$(OBJ)
		ar rc $(LIB) $(OBJ)

%.o: %.c
		gcc -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(LIB) $(EXEC)

re: fclean all
