##
## Makefile for indie studio in /home/rigola_s/rendu/C++/cpp_indie_studio
## 
## Made by Rigolat Sébastien
## Login   <rigola_s@epitech.net>
## 
## Started on  Mon May  2 00:01:51 2016 Rigolat Sébastien
## Last update Mon May  2 17:40:01 2016 Anaïs Foncel
##

NAME		=	indie_studio

CXX		=	g++

RM		=	rm -f

PATH_OBJS	=	./objs/
PATH_SRCS	=	./srcs/

CFLAGS		+=	-W
CFLAGS		+=	-Wall
CFLAGS		+=	-Wextra
CFLAGS		+=	-Werror
CFLAGS		+=	-std=gnu++11
CFLAGS		+=	-g

LDFLAGS		+=	-I./include/
LDFLAGS		+=	-Llib/
LDFLAGS		+=	-L/usr/lib64
LDFLAGS		+=	-L/usr/X11R6/lib

LDLIBS		+=	-lGL
LDLIBS		+=	-lXxf86vm
LDLIBS		+=	-lXext
LDLIBS		+=	-lX11
LDLIBS		+=	-lXcursor
LDLIBS		+=	-lIrrlicht
LDLIBS		+=	-lpthread

SRC		=	main.cpp	\
			Errors.cpp

OBJS		=	$(addprefix $(PATH_OBJS), $(SRCS:.cpp=.o))

FIRST           :=	$(shell test -d $(PATH_OBJS) || mkdir $(PATH_OBJS))

$(PATH_OBJS)%.o : $(PATH_SRCS)%.cpp
		@echo "g++ -c -o $@ $^"
		@$(CXX) -c -o $@ $^ $(CFLAGS) $(LDFLAGS) $(LDLIBS)

$(NAME):	$(OBJS)
		$(CXX) -o $(NAME) $(OBJS) $(CXXFLAGS) $(LDFLAGS) $(LDLIBS)
		@echo -e "\e[1;31mDON'T FORGET TO REMOVE THE DEBUG FLAG BEFORE LAST PUSH !\e[0;m"

all:		$(NAME)

mvo:
		mv $(OBJS) $(OBJS_DIR)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
