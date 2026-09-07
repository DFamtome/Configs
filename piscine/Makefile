CC = gcc
CFLAGS = -Wall -Wextra -g

# Liste des fichiers source
SRC = main.c 
# Conversion automatique des .c en .o
OBJ = $(SRC:.c=.o)
EXEC = mon_programme

# Règle principale
all: $(EXEC)

# Édition de liens
$(EXEC): $(OBJ)
	$(CC) -o $@ $^

# Compilation des fichiers objets (conservés après compilation)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des objets (uniquement si vous le demandez via 'make clean')
clean:
	rm -f $(OBJ)

# Nettoyage complet
fclean: clean
	rm -f $(EXEC)

.PHONY: all clean fclean
