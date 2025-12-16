#include <stdio.h>
#include <string.h>

typedef struct {
    char key[20];
    char value[20];
    int type; // 1 = int, 2 = float, 3 = string
} Pair;

void infix_to_postfix(const char* infix, char* postfix, Pair* variables);