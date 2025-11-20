#include <stdio.h>

int main() {

    int num1, num2;
    char op;    

    printf("Choix num 1 : ");
    scanf("%d", &num1);

    printf("Choix num 2 : ");
    scanf("%d", &num2);

    printf("choisir un operateur : ");
    scanf(" %c", &op);
    
    
    switch (op)
    {
    case '+':
        printf("num1 + num2 = %d", num1 + num2);
        break;
    case '-' :
        printf("num1 - num2 = %d", num1 - num2);
        break;
    case '*' :
        printf("num1 * num2 = %d", num1 * num2);
        break;
    case '/' :
        if (num2 == 0) {
            printf("Erreur : division par zero");
            break;
        }
        printf("num1 / num2 = %f", (float)num1 / num2);
        break;
    case '%' :
        printf("num1 %% num2 = %d", num1 % num2);
        break;
    case '&' :
        printf("num1 & num2 = %d", num1 & num2);
        break;
    case '|' :
        printf("num1 | num2 = %d", num1 | num2);
        break;
    case '~':
        printf("~num1 = %d et ~num2 = %d", ~num1, ~num2);
        break;
    default:
        break;
    }
    
    printf("\n");
    return 0;
}