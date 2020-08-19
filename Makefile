NAME 		= avm

CXX			= g++ -std=c++11
CXXFLAGS	= -Wall -Werror -Wextra

INC			= -I include
SRC			= main.cpp instructionsClass.cpp error.cpp factory.cpp
OBJ			= $(SRC:%.cpp=obj/%.o)

all: $(NAME)

$(NAME): obj $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ) $(LIB)

obj/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) $(INC) -o $@ -c $<

obj:
	mkdir -p obj

clean:
	rm -rf obj

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: fclean all clean
