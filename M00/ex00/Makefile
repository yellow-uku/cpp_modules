NAME = megaphone 

CC = c++
CCFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = megaphone.cpp

OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CCFLAGS) $(OBJ) -o $(NAME) 
	@echo "--------------------------------"
	@echo "${NAME} compiled"
	@echo "--------------------------------"

%.o : %.cpp 
	$(CC) ${FLAGS} -o $@ -c $<

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re