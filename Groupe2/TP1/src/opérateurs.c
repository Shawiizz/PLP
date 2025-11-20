/*
 * opérateurs.c
 * Objectif : Tester les opérateurs arithmétiques et logiques de base en C
 * Auteurs : Maël Feri et Aloïs Lienard
 */
#include <stdio.h>

int main() {
    int a = 16; // première variable
    int b = 3;  // deuxième variable


    printf("a + b = %d\n", a + b); // addition
    printf("a - b = %d\n", a - b); // soustraction
    printf("a * b = %d\n", a * b); // multiplication
    printf("a / b = %d\n", a / b); // division entière
    printf("a %% b = %d\n", a % b); // modulo

    printf("a == b : %d\n", a == b); // test égalité
    printf("a > b  : %d\n", a > b);  // test supérieur

    return 0;
}
