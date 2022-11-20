NAME		=	account-test

HEADERS		=	Account.hpp
SRC			=	tests.cpp Account.cpp
OBJ			=	$(SRC:.cpp=.o)

CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98

all: $(NAME)

%.o : %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $< -c -o $@

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: 	fclean all

test: $(NAME)
	@bash -c "diff <(./$(NAME) | cut -c 19-) <(cat reference.log | cut -c 19-) || exit 0"

.PHONY:	all clean fclean re test
