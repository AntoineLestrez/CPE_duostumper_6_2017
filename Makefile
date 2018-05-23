##
## EPITECH PROJECT, 2017
## duo_stumper
## File description:
## makefile
##

SRC	=	src/main.c		\
		src/recup.c		\
		src/play.c		\
		src/check.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -I./include

NAME	=	lingo

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
