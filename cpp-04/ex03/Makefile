CXX:= c++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98
SRCS:=  main.cpp MateriaSource.cpp AMateria.cpp Character.cpp Ice.cpp Cure.cpp 
		
OBJS:= $(SRCS:.cpp=.o) 
RM:= rm -f
NAME:= materia

all: $(NAME)

$(NAME): $(OBJS) 
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp AMateria.hpp ICharacter.hpp Character.hpp Ice.hpp Cure.hpp IMateriaSource.hpp MateriaSource.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re