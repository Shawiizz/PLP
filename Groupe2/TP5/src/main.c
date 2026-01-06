#include "ex5_1bis.h"

// Fonction pour nettoyer les caractères UTF-8 invalides et ne garder que l'ASCII
void clean_utf8_input(char* str) {
    int i = 0, j = 0;
    while (str[i] != '\0') {
        unsigned char c = (unsigned char)str[i];
        
        // Si c'est un caractère ASCII standard (0-127), on le garde
        if (c < 128) {
            str[j++] = str[i++];
        }
        // Si c'est le début d'une séquence UTF-8 multi-octets
        else if ((c & 0xE0) == 0xC0) {
            // Séquence de 2 octets (ex: é, è, à)
            i += 2;
        }
        else if ((c & 0xF0) == 0xE0) {
            // Séquence de 3 octets
            i += 3;
        }
        else if ((c & 0xF8) == 0xF0) {
            // Séquence de 4 octets
            i += 4;
        }
        else {
            // Octet de continuation ou invalide, on le saute
            i++;
        }
    }
    str[j] = '\0';
}

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
            
            // Nettoyer les caractères UTF-8 non-ASCII
            clean_utf8_input(infix);
            
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
            //printf("Infixe : %s\n", infix);
            //printf("Postfixée : %s\n", postfix);

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
