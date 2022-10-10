NAME	=		matrix

SRCS	=		./main.cpp \
				./linear_combination.cpp

OBJS		=	$(SRCS:.c=.o)

CC			=	g++

CFLAGS		=	-Wall -Wextra -Werror -g3 -std=c++17

$(NAME)		:	$(OBJS)
				$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all			:	$(NAME)

fclean		:	
				rm -rf $(NAME) $(NAME).dSYM

re			:	fclean all

.PHONY		:	all fclean re bonus
