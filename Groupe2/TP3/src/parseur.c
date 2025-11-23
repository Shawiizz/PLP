#include "parseur.h"

// Petit programme de test: tokenise la chaîne et affiche les tokens reconnus
const char* token_type_to_string(TokenType t) {
    switch (t) {
        case TOKEN_NUMBER: return "number";
        case TOKEN_PLUS: return "+";
        case TOKEN_MINUS: return "-";
        case TOKEN_MUL: return "*";
        case TOKEN_DIV: return "/";
        case TOKEN_UNKNOWN: return "unknown";
        default: return "invalid";
    }
}

void parse(char* input, Expression* out_expr, int* nb_expr) {
    Token tokens[20];
    int token_count = 0;

    tokenize(input, tokens, &token_count);

    printf("Nombre de tokens reconnus: %d\n", token_count);
    for (int i = 0; i < token_count; i++) {
        printf("Token %d: type=%s, value='%s'\n", i + 1, token_type_to_string(tokens[i].type), tokens[i].value);
    }

    // si le 1er token n'est pas un nombre, erreur
    if (token_count == 0 || tokens[0].type != TOKEN_NUMBER) {
        printf("Erreur de syntaxe: expression ne peut pas commencer par un opérateur.\n");
        return;
    }

    // si le dernier token n'est pas un nombre, erreur
    if (tokens[token_count - 1].type != TOKEN_NUMBER) {
        printf("Erreur de syntaxe: expression ne peut pas se terminer par un opérateur.\n");
        return;
    }

    char* opr1 = NULL;
    char* opr2 = NULL;
    char op = '\0';
    for (int i = 0; i < token_count; i++) {
        if (tokens[i].type == TOKEN_NUMBER) {
            if (opr1 == NULL) {
                opr1 = tokens[i].value;
            } else if (opr2 == NULL) {
                opr2 = tokens[i].value;
            }
        } else if (tokens[i].type == TOKEN_PLUS || tokens[i].type == TOKEN_MINUS ||
                   tokens[i].type == TOKEN_MUL || tokens[i].type == TOKEN_DIV) {
            op = tokens[i].value[0];
        }
    }

    *nb_expr = 1;

    // malloc les chaînes pour out_expr
    out_expr[0].operand1 = malloc(strlen(opr1) + 1);
    strcpy(out_expr[0].operand1, opr1);
    out_expr[0].operand2 = malloc(strlen(opr2) + 1);
    strcpy(out_expr[0].operand2, opr2);
    out_expr[0].operation = op;
}
