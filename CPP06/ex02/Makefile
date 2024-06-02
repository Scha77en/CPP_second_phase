# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/31 20:26:19 by aouhbi            #+#    #+#              #
#    Updated: 2024/05/31 20:27:21 by aouhbi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = c++ -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = Base.hpp A.hpp B.hpp C.hpp

NAME = identify

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