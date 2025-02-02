##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

CC	:=	g++

CPPFLAGS	=	-std=c++20
CPPFLAGS	+=	-W
CPPFLAGS	+=	-Wall
CPPFLAGS	+=	-Wextra
CPPFLAGS	+=	-Wundef
CPPFLAGS	+=	-Wshadow
CPPFLAGS	+=	-Wunreachable-code
CPPFLAGS	+=	-pedantic
CPPFLAGS	+=	-iquote src

LDFLAGS	=	-lsfml-graphics
LDFLAGS	+=	-lsfml-window
LDFLAGS	+=	-lsfml-system
LDFLAGS	+=	-lncurses

BDIR	=	.build/release

SRC	=	$(shell find src -name "*.cpp")

OBJ = $(SRC:%.cpp=$(BDIR)/%.o)

NAME = MyGKrellm

.PHONY: all
all: $(NAME)

$(BDIR)/%.o: %.cpp
	@ mkdir -p $(dir $@)
	$(CC) -o $@ -c $< $(CPPFLAGS) $(LDFLAGS)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CPPFLAGS) -o $(NAME) $(LDFLAGS)

.PHONY: clean
clean:
	@ rm -f $(OBJ)
	@ rm -rf .build

.PHONY: fclean
fclean: clean
	@ rm -f $(NAME)

.NOTPARRALEL: re
.PHONY: re
re: fclean all
