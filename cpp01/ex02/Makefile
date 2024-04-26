NAME = brain

SRC =	main.cpp

OBJ = $(SRC:.cpp=.o)

CPP = c++ -std=c++98 -g

all: $(NAME)

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
	./$(NAME)

.PHONY: all clean fclean re