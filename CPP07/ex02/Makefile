# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/09 14:34:46 by aouhbi            #+#    #+#              #
#    Updated: 2024/06/25 18:33:49 by aouhbi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = c++ -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp 
OBJS = $(SRCS:.cpp=.o)
DEPS = Array.hpp Array.tpp

NAME = Array

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