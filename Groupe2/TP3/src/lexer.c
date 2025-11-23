#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "lexer.h"

// tokenize: remplit le tableau `tokens` avec uniquement les opérateurs '+' et '-'
// input: chaîne d'entrée
// tokens: tableau de tokens (taille externe gérée par l'appelant)
// token_count: sortie - nombre de tokens reconnus
void tokenize(char* input, Token tokens[], int* token_count) {
    if (input == NULL || tokens == NULL || token_count == NULL) return;

    *token_count = 0;

    for (char* p = input; *p != '\0';) {
        if (isspace((char)*p)) {
            p++;
            continue;
        }

        if (*p == '+') {
            tokens[*token_count].type = TOKEN_PLUS;
            strcpy(tokens[*token_count].value, "+");
            (*token_count)++;
            p++;
            continue;
        }

        if (*p == '-') {
            tokens[*token_count].type = TOKEN_MINUS;
            strcpy(tokens[*token_count].value, "-");
            (*token_count)++;
            p++;
            continue;
        }
        if (*p == '*') {
            tokens[*token_count].type = TOKEN_MUL;
            strcpy(tokens[*token_count].value, "*");
            (*token_count)++;
            p++;
            continue;
        }

        if (*p == '/') {
            tokens[*token_count].type = TOKEN_DIV;
            strcpy(tokens[*token_count].value, "/");
            (*token_count)++;
            p++;
            continue;
        }

        if (isdigit((char)*p)) {
            // read full number
            char buffer[100];
            int i = 0;
            while (*p != '\0' && isdigit((char)*p)) {
                buffer[i] = *p;
                i++;
                p++;
            }
            buffer[i] = '\0';
            tokens[*token_count].type = TOKEN_NUMBER;
            int sizeOfValueVariable = sizeof(tokens[*token_count].value) - 1;
            strncpy(tokens[*token_count].value, buffer, sizeOfValueVariable);
            tokens[*token_count].value[sizeOfValueVariable] = '\0'; // ajout à la fin pour être sur que c'est terminé
            (*token_count)++;
            continue;
        }

        // Unknown char: record as TOKEN_UNKNOWN so parser can report an error
        tokens[*token_count].type = TOKEN_UNKNOWN;
        char buf[2] = {*p, '\0'};
        strcpy(tokens[*token_count].value, buf);
        (*token_count)++;
        p++;
    }
}

