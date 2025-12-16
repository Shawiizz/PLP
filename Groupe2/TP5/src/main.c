#include "ex5_1bis.h"

int main() {
    char infix[100];      // Expression infixée entrée par l'utilisateur
    char postfix[100];    // Expression postfixée générée
    Pair variables[100] = {0}; // Tableau pour stocker les variables
    
    while (1) {
        printf("Entrez une expression infixée (ou 'quit' pour quitter) : ");
        
        // Lecture de l'expression depuis le terminal
        if (fgets(infix, sizeof(infix), stdin) != NULL) {
            // Suppression du retour à la ligne
            infix[strcspn(infix, "\n")] = '\0';
            
            // Vérifier si l'utilisateur veut quitter
            if (strcmp(infix, "quit") == 0 || strcmp(infix, "exit") == 0) {
                printf("Au revoir !\n");
                break;
            }
            
            // Ignorer les entrées vides
            if (infix[0] == '\0') {
                continue;
            }

            // Conversion de l'expression infixée en postfixée
            infix_to_postfix(infix, postfix, variables);
            
            // Affichage des résultats
            printf("Infixe : %s\n", infix);
            printf("Postfixée : %s\n", postfix);

            // afficher les variables
            printf("Variables définies :\n");
            for (int i = 0; i < 100; i++) {
                if (variables[i].key[0] != '\0') {
                    printf("%s = %s (type %d)\n", variables[i].key, variables[i].value, variables[i].type);
                }
            }
            
            // Calculer et afficher le résultat seulement s'il y a une expression postfixée
            if (postfix[0] != '\0') {
                int result = 0;
                evaluate_postfix(postfix, &result);
                printf("Résultat : %d\n", result);
            }
            printf("\n");
        } else {
            printf("Erreur de lecture.\n");
            break;
        }
    }
    
    return 0;
}
