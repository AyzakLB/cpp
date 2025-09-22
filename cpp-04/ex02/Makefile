CXX:= c++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98
SRCS:=  main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp
OBJS:= $(SRCS:.cpp=.o)
RM:= rm -f
NAME:= animal

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp Animal.hpp Brain.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re