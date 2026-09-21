SRC = main.c hello.c
OBJ = $(SRC:.c=.o)

all : $(OBJ)
	gcc -o main $^

%.o: %.c
	gcc -c $< -o $@
