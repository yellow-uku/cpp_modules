NAME = bureaucrat

CC = c++ 
CCFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp \
	Bureaucrat.cpp

H = Bureaucrat.hpp

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