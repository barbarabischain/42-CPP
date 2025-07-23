NAME     := megaphone

CC      := c++
CFLAGS := -Wall -Werror -Wextra -std=c++98

SRC      := megaphone.cpp
OBJ      := objects/megaphone.o

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

objects/%.o: %.cpp | objects
	@echo "Compiling: $(notdir $<)"
	$(CC) $(CFLAGS) -c $< -o $@

objects:
	mkdir -p objects

clean:
	rm -rf objects

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
