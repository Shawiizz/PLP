#include "ex4_2.h"

// Fonction pour obtenir la priorité d'un opérateur
int get_priority(char op) {
    // Les opérateurs + et - ont une priorité de 1
    // Les opérateurs * et / ont une priorité de 2
    // La parenthèse ouvrante a la priorité la plus basse (0)
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '(': 
            return 0;
        default:
            return -1; // Pour tout autre caractère
    }
}

// Convertit une expression infixée (ex: "3 + 4 * 5") en postfixée (ex: "3 4 5 * +")
void infix_to_postfix(const char* infix, char* postfix) {
    char stack[100];      // Pile pour stocker les opérateurs
    int top = -1;         // Indice du sommet de la pile
    int j = 0;            // Indice pour la chaîne de sortie postfixée
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if (c == ' ') continue; // Ignore les espaces
        // Si c'est un chiffre, on l'ajoute directement à la sortie
        if ((c >= '0' && c <= '9')) {
            postfix[j++] = c;
            postfix[j++] = ' ';
        } 
        // Si c'est une parenthèse ouvrante, on la pousse sur la pile
        else if (c == '(') { 
            stack[++top] = c;
        } 
        // Si c'est une parenthèse fermante, on dépile jusqu'à la parenthèse ouvrante
        else if (c == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[j++] = stack[top--];
                postfix[j++] = ' ';
            }
            if (top >= 0 && stack[top] == '(') top--; // Retire la parenthèse ouvrante
        } 
        // Si c'est un opérateur
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            // On dépile les opérateurs de priorité supérieure ou égale
            while (top >= 0 && get_priority(stack[top]) >= get_priority(c)) {
                postfix[j++] = stack[top--];
                postfix[j++] = ' ';
            }
            // On empile l'opérateur courant
            stack[++top] = c;
        }
    }
    // On vide la pile des opérateurs restants
    while (top >= 0) {
        if (stack[top] != '(') {
            postfix[j++] = stack[top];
            postfix[j++] = ' ';
        }
        top--;
    }
    postfix[j > 0 ? j-1 : 0] = '\0'; // Termine la chaîne postfixée
}

