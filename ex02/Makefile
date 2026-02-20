# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/19 13:39:13 by kaisuzuk          #+#    #+#              #
#    Updated: 2026/02/20 08:13:59 by kaisuzuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	bureaucrat
CXX		=	c++
FLAG	=	-Wall -Werror -Wextra -std=c++98 -pedantic

SRCS	=	Bureaucrat.cpp \
			GradeTooHighException.cpp \
			GradeTooLowException.cpp \
			FormNotSignedException.cpp \
			PresidentialPardonForm.cpp \
			RobotomyRequestForm.cpp \
			ShrubberyCreationForm.cpp \
			AForm.cpp \
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