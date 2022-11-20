NAME		=	mysed

HEADERS		=
SRC			=	main.cpp
OBJ			=	$(SRC:.cpp=.o)

CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98 -fsanitize=address

all: $(NAME)

%.o : %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $< -c -o $@

$(NAME):$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: 	fclean all

test: $(NAME)
	./$(NAME) test.txt REPLACE replace


.PHONY:	all clean fclean re
