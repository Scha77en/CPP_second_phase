# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/20 12:26:40 by aouhbi            #+#    #+#              #
#    Updated: 2024/05/20 12:32:10 by aouhbi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = c++ -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp ScalarConverter.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = ScalarConverter.hpp

NAME = convert

all: $(NAME)

$(NAME): $(OBJS)
	$(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp $(DEPS)
	$(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
