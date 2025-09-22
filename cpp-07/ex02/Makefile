CXX:= c++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98
SRCS:=  main.cpp

OBJS:= $(SRCS:.cpp=.o) 
HEADERS:= iter.hpp
RM:= rm -f
NAME:= ex01

all: $(NAME)

$(NAME): $(OBJS) 
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re