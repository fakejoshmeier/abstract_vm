NAME = avm
CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++11
SRC = main

CPP_SRC = $(addsuffix .cpp, $(addprefix src/, $(SRC)))

O_SRC = $(addsuffix .o, $(addprefix obj/, $(SRC)))

H_LOC = -I inc/*.hpp
HEADERS = 

all: $(NAME)

$(NAME): $(O_SRC)
	@/bin/echo -n "ララララ"
	@$(CC) $(CFLAGS) $^ -o $(NAME)
	@/bin/echo -n "ドラァァ！」"

$(O_SRC):
	@mkdir -p "obj/"
	@/bin/echo -n "「ドララララ"

$(O_SRC)/%.o: %.cpp
	@/bin/echo -n "ララララ"
	@$(CC) $(CFLAGS) $(H_LOC) -c $<
	@/bin/echo -n "ララララ"

clean:
	@/bin/rm -f $(O_SRC)
	@/bin/echo "「今オレのこの頭のことなんつった！？」"
	@/bin/rm -rf "obj/"

fclean: clean
	@/bin/rm -f $(NAME)

re:	fclean all
