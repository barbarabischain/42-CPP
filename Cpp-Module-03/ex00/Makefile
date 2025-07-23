# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: babischa <babischa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/19 14:59:39 by babischa          #+#    #+#              #
#    Updated: 2025/07/08 16:55:10 by babischa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     	:= claptrap

CC 	     	:= c++
FLAGS 		:= -Wall -Werror -Wextra -std=c++98


SRC_FILES	:= main ClapTrap
HEADERS		:= ClapTrap.hpp
OBJ      	:= $(addprefix objects/, $(addsuffix .o, $(SRC_FILES)))

all: $(NAME)

objects/%.o: %.cpp $(HEADERS)| objects
	$(CC) $(FLAGS) -o $@ -c $< ; \
	echo "Compiling: $(notdir $<)"

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

objects:
	mkdir -p objects

bonus: all

clean:
	rm -rf objects

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
