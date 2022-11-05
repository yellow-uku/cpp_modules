NAME = phonebook 

CC = c++
CCFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp \
	Contact.cpp \
	PhoneBook.cpp

H = Contact.hpp \
	PhoneBook.hpp

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
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re:	fclean all

.PHONY: clean fclean re