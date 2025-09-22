CXX:= c++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98
SRCS:=  main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJS:= $(SRCS:.cpp=.o)
RM:= rm -f
NAME:= war

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re