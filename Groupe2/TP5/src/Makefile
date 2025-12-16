# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -g

# Nom de l'exécutable
TARGET = calculatrice

# Fichiers sources et objets
SRCS = ex5_1.c ex5_1bis.c main.c
OBJS = $(SRCS:.c=.o)

# Règle par défaut
all: $(TARGET)

# Lien de l'exécutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compilation des fichiers .c en .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Dépendances
ex5_1.o: ex5_1.c ex5_1.h
ex5_1bis.o: ex5_1bis.c ex5_1bis.h ex5_1.h
main.o: main.c ex5_1bis.h

# Nettoyage
clean:
	rm -f $(OBJS) $(TARGET)

# Exécution
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run

