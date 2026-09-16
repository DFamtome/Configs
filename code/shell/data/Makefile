MAIN   = main.c 
TESTS  = tests.c
OBJ    = $(SRC:.c=.o) 
MOBJ   = $(MAIN:.c=.o)
TOBJ   = $(TESTS:.c=.o)

CFLAGS = -std=c99 -pedantic -Wall -Wextra -Wvla -Werror 
CRITER = -lcriterion

EXEC   = main.out

check: $(OBJ) $(TOBJ)
	gcc $^ -o $(EXEC) $(CFLAGS) $(CRITER)

prod: $(OBJ) $(MOBJ)
	gcc $^ -o $(EXEC) $(CFLAGS)

%.o: %.c
	gcc -c $< -o $@ $(CFLAGS) 

debug: $(SRC) $(MAIN)
	gcc $^ -o $(EXEC) $(CFLAGS) -g

clean:
	rm -f $(OBJ) $(MOBJ) $(TOBJ) $(EXEC)
