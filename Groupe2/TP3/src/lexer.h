#ifndef LEXER_H
#define LEXER_H

#include <stddef.h>

// Types de tokens détectés par le tokenizer
typedef enum {
	TOKEN_NUMBER,
	TOKEN_PLUS,
	TOKEN_MINUS,
	TOKEN_MUL,
	TOKEN_DIV,
	TOKEN_UNKNOWN
} TokenType;

// Token: type et valeur lexicale (sous forme de chaîne)
typedef struct {
	TokenType type;
	char value[100];
} Token;

// tokenize: parse input et stocke les tokens reconnus (nombres et opérateurs + / -)
// tokens: tableau de `Token` fourni par l'appelant, token_count: nombre retourné
void tokenize(char* input, Token tokens[], int* token_count);

#endif // LEXER_H