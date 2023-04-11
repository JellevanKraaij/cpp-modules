NAME		=	btc

DEPS		=	$(wildcard *.hpp) $(wildcard *.tpp)
SRC			=	$(wildcard *.cpp)
OBJ			=	$(SRC:.cpp=.o)

CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98 -fsanitize=address -g

all: $(NAME)

%.o : %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) $< -c -o $@

$(NAME):$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
