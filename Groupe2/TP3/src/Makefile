CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -g

SOURCES = parseur.c lexer.c evaluation.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = parseur

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean
