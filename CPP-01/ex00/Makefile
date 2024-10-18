# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/18 14:23:18 by tguerran          #+#    #+#              #
#    Updated: 2024/10/18 16:32:27 by tguerran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Zombie

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

OBJDIR = obj

SRC = main.cpp \
		Zombie.cpp \
		newZombie.cpp \
		randomChump.cpp

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
