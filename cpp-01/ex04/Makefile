CXX:= c++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98
SRCS:=  main.cpp myReplace.cpp
OBJS:= $(SRCS:.cpp=.o)
RM:= rm -f
NAME:= sed-ish

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re