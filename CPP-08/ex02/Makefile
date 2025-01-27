# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 00:46:23 by tguerran          #+#    #+#              #
#    Updated: 2025/01/27 01:57:22 by tguerran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex02

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

OBJDIR = obj

SRC = main.cpp

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
