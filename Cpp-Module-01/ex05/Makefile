# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: babischa <babischa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/19 14:59:39 by babischa          #+#    #+#              #
#    Updated: 2025/06/23 17:12:35 by babischa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     	:= harl

CC 	     	:= c++
FLAGS 		:= -Wall -Werror -Wextra -std=c++98 -g3

HEADERS		:= -I ./include

SRC_FILES	:= main Harl
OBJ      	:= $(addprefix objects/, $(addsuffix .o, $(SRC_FILES)))

all: $(NAME)

objects/%.o: source/%.cpp | objects
	$(CC) $(FLAGS) -o $@ -c $< $(HEADERS) ; \
	echo "Compiling: $(notdir $<)"

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(HEADERS) -o $(NAME)

objects:
	mkdir -p objects

bonus: all

clean:
	rm -rf objects

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
