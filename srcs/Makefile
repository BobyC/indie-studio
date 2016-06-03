##
## Makefile for Makefile in /home/drozdz_b/Documents/Unix System/LemIPC/test_semaphore
##
## Made by drozdz_b
## Login   <drozdz_b@epitech.net>
##
## Started on  Sat Mar 19 16:37:34 2016 drozdz_b
## Last update Fri Jun  3 17:13:33 2016 drozdz_b
##

SRC	=	main.cpp		\
		Character.cpp		\
		KeyReceiver.cpp		\
		PlayerController.cpp	\
		CharacterInfo.cpp	\
		Object.cpp		\
		Plan.cpp		\
		Box.cpp

NAME	=	testIrrlitch

OBJ	=	$(SRC:.cpp=.o)

RM	=	rm -rf

CC	=	g++

$CFLAGS	+= -g

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(SRC) -lIrrlicht -lGL -lX11 -lXxf86vm -g

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
