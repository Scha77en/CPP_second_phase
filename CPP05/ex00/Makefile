# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/24 13:50:26 by aouhbi            #+#    #+#              #
#    Updated: 2024/05/30 10:43:47 by aouhbi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureaucrat
CPP = c++

RED = \033[0;31m
GREEN = \033[0;32m
RESET = \033[0m

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

HEAD = Bureaucrat.hpp
SRC = main.cpp Bureaucrat.cpp
OBJECTS = $(patsubst %.cpp,%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CPP) $(CPPFLAGS) $^ -o $@

%.o: %.cpp $(HEAD)
	@$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJECTS)
	@echo "${RED}--------------- Object files removed. ---------------${RESET}"

fclean: clean
	@rm -f $(NAME)
	@echo "${RED}--------------- $(NAME) removed. ---------------${RESET}"

re: fclean all