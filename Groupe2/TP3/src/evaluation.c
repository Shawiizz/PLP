#include "evaluation.h"

int evaluer_expression(Expression* expr) {
    int op1 = atoi(expr->operand1);
    int op2 = atoi(expr->operand2);
    switch (expr->operation) {
        case '+':
            return op1 + op2;
        case '-':
            return op1 - op2;
        case '*':
            return op1 * op2;
        case '/':
            if (op2 != 0) {
                return op1 / op2;
            } else {
                printf("Erreur: Division par zéro.\n");
                return 0;
            }
        default:
            printf("Erreur: Opération inconnue '%c'.\n", expr->operation);
            return 0;
    }
}

int eval_input(char* input) {
    Expression expr;
    int nb_expr = 0;
    parse(input, &expr, &nb_expr);
    if (nb_expr == 1) {
        int result = evaluer_expression(&expr);
        printf("Résultat de l'expression %s %c %s = %d\n",
               expr.operand1, expr.operation, expr.operand2, result);
        return result;
    } else {
        printf("Erreur: Nombre d'expressions évaluées incorrect (%d).\n", nb_expr);
        return 0;
    }
}

int main() {
    char input[] = "12+5"; 

    eval_input(input);

    return 0;
}