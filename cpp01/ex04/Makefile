NAME = sed

CC = c++
CCFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp \

OBJ = $(SRC:%.cpp=%.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(CCFLAGS) $(OBJ) -o $(NAME) 
	@echo "--------------------------------"
	@echo "${NAME} compiled"
	@echo "--------------------------------"

%.o : %.cpp
	$(CC) ${CCFLAGS} -o $@ -c $<

clean:
	@rm -rf $(OBJ) *.txt *.replace

fclean: clean
	@rm -rf $(NAME) *.txt *.replace

re:	fclean all

.PHONY: clean fclean re