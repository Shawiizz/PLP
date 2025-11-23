#ifndef PARSEUR_H
#define PARSEUR_H

#include "lexer.h"
#include <stdio.h>
#include <string.h>
#include <stddef.h>

// expression: structure interne représentant une opération binaire A op B
typedef struct {
	char operation; // '+', '-', '*', '/'
	char* operand1;
	char* operand2;
} Expression;

#endif // PARSEUR_H