# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 19:34:08 by tguerran          #+#    #+#              #
#    Updated: 2024/10/23 00:32:25 by tguerran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

OBJDIR = obj

SRC = megaphone.cpp

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
