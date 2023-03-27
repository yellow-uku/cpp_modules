NAME = animal

CC = c++ 
CCFLAGS = -g -ggdb -fsanitize=address -Wall -Wextra -Werror -std=c++98

SRC = main.cpp \
	Animal.cpp \
	Dog.cpp \
	Cat.cpp \
	Brain.cpp

H = Animal.hpp \
	Dog.hpp \
	Cat.hpp \
	Brain.hpp

OBJ = $(SRC:%.cpp=%.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(CCFLAGS) $(OBJ) -o $(NAME) 
	@echo "--------------------------------"
	@echo "${NAME} compiled 🐥"
	@echo "--------------------------------"

%.o : %.cpp $(H)
	@$(CC) ${CCFLAGS} -o $@ -c $<

clean:
	@rm -rf $(OBJ) *.tmp *.gch

fclean: clean
	@rm -rf $(NAME) *.tmp *.gch
	@echo "--------------------------------"
	@echo "cleaned 🐣"
	@echo "--------------------------------"
re:	fclean all

.PHONY: clean fclean re