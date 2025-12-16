#include "ex5_1bis.h"

void evaluate_postfix(const char* postfix, int* result) {
    int stack[100];  // Pile pour stocker les opérandes
    int top = -1;    // Indice du sommet de la pile

    for (int i = 0; postfix[i] != '\0'; ) {
        // Ignorer les espaces
        if (postfix[i] == ' ') {
            i++;
            continue;
        }

        // Si c'est un chiffre, on le pousse sur la pile
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            stack[++top] = postfix[i] - '0';
            i++;
            continue;
        } 

        // Si c'est un opérateur, on dépile deux opérandes et on effectue l'opération, puis on stocke le résultat en haut de la pile
        int val2 = stack[top--];
        int val1 = stack[top--];
        switch (postfix[i]) {
            case '+':
                stack[++top] = val1 + val2;
                break;
            case '-':
                stack[++top] = val1 - val2;
                break;
            case '*':
                stack[++top] = val1 * val2;
                break;
            case '/':
                stack[++top] = val1 / val2;
                break;
        }
        i++;
        
    }
    // Le résultat final est au sommet de la pile
    *result = stack[top];
}

// int main () {
//     char infix[100];      // Expression infixée entrée par l'utilisateur
//     char postfix[100];    // Expression postfixée générée
//     printf("Entrez une expression infixée : ");
//     // Lecture de l'expression depuis le terminal
//     if (fgets(infix, sizeof(infix), stdin) != NULL) {
//         // Suppression du retour à la ligne
//         infix[strcspn(infix, "\n")] = '\0';

//         // Conversion de l'expression infixée en postfixée
//         infix_to_postfix(infix, postfix);
//         // Affichage des résultats
//         printf("Infixe : %s\n", infix);
//         printf("Postfixée : %s\n", postfix);
//         int result = 0;
//         evaluate_postfix(postfix, &result);
//         printf("Résultat : %d\n", result);
//     } else {
//         printf("Erreur de lecture.\n");
//     }
//     return 0;
// }