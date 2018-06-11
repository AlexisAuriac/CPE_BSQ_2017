##
## EPITECH PROJECT, 2017
## bsq
## File description:
## Makefile for bsq.
##

SRC	=	main.c		\
		load_map.c	\
		map_testing.c	\
		rate.c

SRCS	=	$(addprefix src/, $(SRC))

OBJ	=	$(SRCS:.c=.o)

CPPFLAGS+=	-I include

CFLAGS	+=	-Wall -Wextra

LIB	=	-Llib -lmy

NAME	=	bsq

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJMAIN) $(OBJ) $(LIB)

clean	:
		$(RM) -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean	all

.PHONY	:	all clean fclean re
