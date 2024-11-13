# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 00:46:23 by tguerran          #+#    #+#              #
#    Updated: 2024/11/13 15:34:50 by tguerran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex00

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

OBJDIR = obj

SRC = main.cpp \
		Animal.cpp \
		Cat.cpp \
		Dog.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp

OFILES = $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

DIRS = $(sort $(dir $(OFILES)))

all: $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(DIRS):
	mkdir -p $(DIRS)

$(OBJDIR)/%.o: %.cpp | $(DIRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES) -o $(NAME)

clean:
	rm -f $(OFILES)
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
