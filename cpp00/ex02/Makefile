NAME = account

SRC =	tests.cpp \
		Account.cpp

OBJ = $(SRC:.cpp=.o)

CPP = c++ -Wall -Werror -Wextra -std=c++98 -g

all: $(NAME)
	@echo "all done"

$(NAME): $(OBJ)
	@$(CPP) $(OBJ) -o $(NAME)

%.o: %.cpp
	@$(CPP) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "clean done"

fclean: clean
	@rm -f $(NAME)
	@echo "fclean done"

re: fclean all

play: all clean

.PHONY: all clean fclean re