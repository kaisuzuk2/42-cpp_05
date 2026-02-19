# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/18 11:57:30 by kaisuzuk          #+#    #+#              #
#    Updated: 2026/02/19 08:32:19 by kaisuzuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	bureaucrat
CXX		=	c++
FLAG	=	-Wall -Werror -Wextra -std=c++98 -pedantic

SRCS	=	Bureaucrat.cpp \
			GradeTooHighException.cpp \
			GradeTooLowException.cpp \
			Form.cpp \
			main.cpp
OBJS	=	$(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(FLAG) -o $(NAME) $(OBJS)

%.o: %.cpp	
	$(CXX) $(FLAG) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all