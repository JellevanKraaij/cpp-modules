NAME		=	zombies

HEADERS		=	Zombie.hpp
SRC			=	main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
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

re: fclean all

.PHONY:	all clean fclean re
