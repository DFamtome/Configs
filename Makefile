SRC    = my_atoi_base.c
MAIN   = main.c
TESTS  = tests.c
OBJ    = $(SRC:.c=.o)

CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra -Wvla 
CRITER = -lcriterion

EXEC   = main.out


prod: $(OBJ) $(MAIN:.c=.o)
	gcc $^ -o $(EXEC) $(CFLAGS)

all: $(OBJ) $(TESTS:.c=.o)
	gcc $^ -o $(EXEC) $(CFLAGS) $(CRITER)

%.o: %.c
	gcc -c $< -o $@ 

debug: $(SRC)
	make clean
	gcc $^ -o $(EXEC) $(CFLAGS) -g

clean:
	rm -f $(OBJ) $(EXEC)
