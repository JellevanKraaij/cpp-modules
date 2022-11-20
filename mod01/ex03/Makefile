NAME		=	violence

HEADERS		=	Weapon.hpp HumanA.hpp HumanB.hpp
SRC			=	main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
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

.PHONY:	all clean fclean re
