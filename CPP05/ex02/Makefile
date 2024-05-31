# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/24 13:50:26 by aouhbi            #+#    #+#              #
#    Updated: 2024/05/30 15:38:14 by aouhbi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureaucratformSRP
CPP = c++

RED = \033[0;31m
GREEN = \033[0;32m
RESET = \033[0m

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

HEAD = Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp
SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
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