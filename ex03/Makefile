CC = c++

CC_FLAGS = -Wall -Werror -Wextra -std=c++98 -g3 -I./includes

NAME = intern

SOURCES =	./srcs/main.cpp \
			./srcs/AForm.cpp \
			./srcs/Bureaucrat.cpp \
			./srcs/Intern.cpp \
			./srcs/PresidentialPardonForm.cpp \
			./srcs/RobotomyRequestForm.cpp \
			./srcs/ShrubberyCreationForm.cpp

OBJECTS = $(SOURCES:.cpp=.o)

RM = rm

RM_FLAGS = -f

all : $(NAME)

$(NAME): $(OBJECTS)
		$(CC) $(CC_FLAGS) -o $(NAME) $(OBJECTS)

%.o:%.cpp
		$(CC) $(CC_FLAGS) -c $< -o $@

clean:
		$(RM) $(RM_FLAGS) $(OBJECTS)

fclean: clean
		$(RM) $(RM_FLAGS) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re