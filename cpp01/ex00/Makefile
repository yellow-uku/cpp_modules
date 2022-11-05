NAME = zombie

CC = c++
CCFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp \
	Zombie.cpp \
	newZombie.cpp \
	randomChump.cpp

H = Zombie.hpp

OBJ = $(SRC:%.cpp=%.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(CCFLAGS) $(OBJ) -o $(NAME) 
	@echo "--------------------------------"
	@echo "${NAME} compiled"
	@echo "--------------------------------"

%.o : %.cpp $(H)
	$(CC) ${CCFLAGS} -o $@ -c $<

clean:
	@rm -rf $(OBJ) *.tmp *.gch

fclean: clean
	@rm -rf $(NAME) *.tmp *.gch

re:	fclean all

.PHONY: clean fclean re