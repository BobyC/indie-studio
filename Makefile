##
## Makefile for  in /home/homes_d/rendu/cpp_plazza
## 
## Made by David Homes
## Login   <homes_d@epitech.net>
## 
## Started on  Tue Apr  5 14:44:24 2016 David Homes
## Last update Wed Apr 27 16:59:39 2016 Anaïs Foncel
##

NAME		=	indie_studio

CXX		=	g++

RM		=	rm -f

CFLAGS		+=	-I./include/
CFLAGS		+=	-W
CFLAGS		+=	-Wall
CFLAGS		+=	-Wextra
CFLAGS		+=	-Werror
CFLAGS		+=	-std=gnu++11

LDFLAGS		+=	

LDLIBS		+=	

DIR		=	srcs/

SRC		=	main.cpp	\
			Errors.cpp

SRCS		=	$(addprefix $(DIR), $(SRC))

OBJS		=	$(SRCS:.cpp=.o)

%.o:		%.cpp
		@echo "g++ -c -o $@ $^"
		@$(CXX) -c -o $@ $^ $(CFLAGS) $(LDFLAGS) $(LDLIBS)

$(NAME):	$(OBJS)
		$(CXX) -o $(NAME) $(OBJS) $(CXXFLAGS) $(LDFLAGS) $(LDLIBS)

all:		$(NAME)

mvo:
		mv $(OBJS) $(OBJS_DIR)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
