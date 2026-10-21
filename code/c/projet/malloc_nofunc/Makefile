SRC     = src/malloc.c
MAIN    = main.c
TESTS   = tests/tests.c
OBJ     = $(SRC:.c=.o)

CFLAGS  = -std=c99 -pedantic -Werror -Wall -Wextra -Wvla  -fPIC 
LDFALGS = -L. -lmalloc -Wl,--no-undefined
CRITER  = -lcriterion

EXEC   = malloc
EDEV   = $(EXEC)-dev.out
TEST   = $(EXEC)-test.out

LIBMAL = libmalloc.so

COMPL  = $(CFLAGS) $(LDFALGS)

library: $(LIBMAL)

dev: $(EDEV)

check: $(TEST)

$(LIBMAL): $(OBJ)
	gcc $^ -o $@ -shared 

$(EDEV): $(OBJ) $(MAIN:.c=.o)
	gcc $^ -o $@ $(LDFALGS)

$(TEST): $(TESTS:.c=.o) $(LIBMAL)
	gcc $< -o $@ $(CRITER)
	./tests/test.sh
	./malloc-test.out

%.o: %.c
	gcc -c $< -o $@ $(CFLAGS) 

debug: $(LIBMAL) $(MAIN)
	gcc -c $(MAIN) -o $(MAIN:.c=.o)  $(CFLAGS)-g
	gcc $(MAIN:.c=.o) -o $@ $(LDFALGS)

clean:
	rm -f $(OBJ) $(EXEC)* $(LIBMAL) $(MAIN:.c=.o) $(TESTS:.c=.o) debug

.PHONY: debug clean dev all test
