#include "ex5_1.h"

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

void getVariableContent(const char* str, int* index, char* outStr, int* outType) {
    int j = 0;
    // Ignorer les espaces au début
    while (str[*index] == ' ') {
        (*index)++;
    }
    while (str[*index] != ';' && str[*index] != '\0') {
        if(str[*index] == '"') {
            *outType = 3; // string type
        } else if (str[*index] == '.') {
            *outType = 2; // float type
        } else if (str[*index] >= '0' && str[*index] <= '9' && *outType != 2) {
            *outType = 1; // int type
        }
        // Ne pas ajouter les espaces en fin de valeur
        if (str[*index] != ' ' || str[*index + 1] != ';' && str[*index + 1] != '\0') {
            outStr[j++] = str[*index];
        }
        (*index)++;
    }
    // Supprimer les espaces en fin de chaîne
    while (j > 0 && outStr[j - 1] == ' ') {
        j--;
    }
    outStr[j] = '\0';
}

void getFullStringUntilEqualSign(const char* str, int* index, char* outStr) {
    int j = 0;
    while (str[*index] != '=' && str[*index] != '\0') {
        // Ignorer les espaces
        if (str[*index] != ' ') {
            outStr[j++] = str[*index];
        }
        (*index)++;
    }
    if (str[*index] == '=') {
        (*index)++; // Skip the '=' character
    }
    // Ignorer les espaces après le signe '='
    while (str[*index] == ' ') {
        (*index)++;
    }

    outStr[j] = '\0';
}

// faire une fonction pour obtenir la chaine jusqu'a ce qu'on trouve un signe de calcul +, -, *, / ou la fin de la chaîne
void getFullStringUntilOperator(const char* str, int* index, char* outStr) {
    int j = 0;
    while (str[*index] != '+' && str[*index] != '-' && str[*index] != '*' && str[*index] != '/' && str[*index] != '\0' && str[*index] != ')' && str[*index] != '(') {
        // Ignorer les espaces
        if (str[*index] != ' ') {
            outStr[j++] = str[*index];
        }
        (*index)++;
    }
    outStr[j] = '\0';
    // Reculer l'index d'un cran pour que la boucle appelante traite l'opérateur
    if (str[*index] != '\0') {
        (*index)--;
    }
}

// Convertit une expression infixée (ex: "3 + 4 * 5") en postfixée (ex: "3 4 5 * +")
void infix_to_postfix(const char* infix, char* postfix, Pair* variables) {
    char stack[100];      // Pile pour stocker les opérateurs
    int top = -1;         // Indice du sommet de la pile
    int j = 0;            // Indice pour la chaîne de sortie postfixée
    char currentVarName[20] = {0};
    char currentVarValue[20] = {0};
    int currentVarType = 0;
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
        } else {
            // Gérer les variables (lettres)
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                // Chercher s'il y a un '=' après le nom de la variable
                int tempIndex = i;
                // Avancer tempIndex jusqu'à la fin du nom de variable
                while ((infix[tempIndex] >= 'a' && infix[tempIndex] <= 'z') || 
                       (infix[tempIndex] >= 'A' && infix[tempIndex] <= 'Z') ||
                       (infix[tempIndex] >= '0' && infix[tempIndex] <= '9') ||
                       infix[tempIndex] == '_') {
                    tempIndex++;
                }
                // Ignorer les espaces
                while (infix[tempIndex] == ' ') {
                    tempIndex++;
                }
                if (infix[tempIndex] != '=') {
                    // C'est une utilisation de variable, on l'ajoute à la sortie
                    getFullStringUntilOperator(infix, &i, currentVarName);
                
                    // Chercher la variable dans le tableau
                    for (int k = 0; k < 100; k++) {
                        if (strcmp(variables[k].key, currentVarName) == 0) {
                            if(variables[k].type == 0) {
                                // Variable non définie
                                printf("Erreur: variable '%s' non définie.\n", currentVarName);
                                break;
                            }
                            if(variables[k].type == 3) {
                                // Ajouter des guillemets si c'est une string
                                printf("Erreur: impossible d'effectuer un calcul avec une variable de type string '%s'.\n", currentVarName);
                                break;
                            }
                            // Ajouter la valeur de la variable à la sortie
                            int len = strlen(variables[k].value);
                            for (int m = 0; m < len; m++) {
                                postfix[j++] = variables[k].value[m];
                            }
                            postfix[j++] = ' ';
                            break;
                        }
                    }

                } else {
                    // C'est une définition de variable

                
                    // Récupérer le nom complet de la variable
                getFullStringUntilEqualSign(infix, &i, currentVarName);
                // Récupérer la valeur de la variable
                getVariableContent(infix, &i, currentVarValue, &currentVarType);

                // Chercher la variable dans le tableau pour l'ajouter 
                for (int k = 0; k < 100; k++) {
                    if (strcmp(variables[k].key, currentVarName) == 0) {
                        // Vérifier si le type est différent
                        if (variables[k].type != currentVarType) {
                            printf("Erreur: impossible de changer le type de la variable '%s' (type %d -> type %d).\n", 
                                   currentVarName, variables[k].type, currentVarType);
                            break;
                        }
                        // Mettre à jour la variable existante (même type)
                        strcpy(variables[k].value, currentVarValue);
                        break;
                    } else if (variables[k].key[0] == '\0') {
                        // Ajouter une nouvelle variable
                        strcpy(variables[k].key, currentVarName);
                        strcpy(variables[k].value, currentVarValue);
                        variables[k].type = currentVarType;
                        break;
                    }
                }
            }
            }
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

