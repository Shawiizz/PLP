#ifndef EVALUATION_H
#define EVALUATION_H
#include "parseur.h"
// Évalue une expression binaire simple (A op B) et retourne
// le résultat en entier. Supporte les opérations +, -, *, /
int evaluer_expression(Expression* expr);
int eval_input(char* input);
#endif // EVALUATION_H
