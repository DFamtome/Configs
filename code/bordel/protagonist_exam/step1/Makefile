SRC = main.c hello.c
OBJ = $(SRC:.c=.o)
CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra -Wvla

all : main

main: $(OBJ)
	gcc -o main $^
	
%.o: %.c
	gcc -o $@ -c $<

