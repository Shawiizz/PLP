/*
 * variables.c
 * Objectif : Afficher et manipuler différents types de variables en C
 * Auteurs : Maël Feri et Aloïs Lienard
 */
#include <stdio.h>

int main() {
    
    signed char c = -100; // variable signée (char)
    unsigned char uc = 200; // variable non signée (char)

    signed short s = -12345; // short signé
    unsigned short us = 54321; // short non signé

    signed int i = -100000; // int signé
    unsigned int ui = 100000; // int non signé

    signed long int l = -1000000L; // long signé
    unsigned long int ul = 1000000UL; // long non signé

    signed long long int ll = -1000000000LL; // long long signé
    unsigned long long int ull = 1000000000ULL; // long long non signé

    float f = 3.14f; // flottant
    double d = 2.71828; // double précision
    long double ld = 1.6180339887L; // long double
    printf("Affichage des variablesde types base : \n \n");

    printf("i. char : ");
    printf("\n  Signed char : %lu", sizeof(c)); // taille d'un char signé
    printf("\n  Unsigned char : %lu", sizeof(uc)); // taille d'un char non signé
    
    printf("\nii. short : ");
    printf("\n  Signed short : %lu", sizeof(s)); // taille d'un short signé
    printf("\n  Unsigned short : %lu", sizeof(us)); // taille d'un short non signé

    printf("\niii. int : ");
    printf("\n  Signed int : %lu", sizeof(i)); // taille d'un int signé
    printf("\n  Unsigned int : %lu", sizeof(ui)); // taille d'un int non signé

    printf("\niv. long int : ");
    printf("\n  Signed long int : %lu", sizeof(l)); // taille d'un long signé
    printf("\n  Unsigned long int : %lu", sizeof(ul)); // taille d'un long non signé

    printf("\nv. long long int : ");;
    printf("\n  Signed long long int : %lu", sizeof(ll)); // taille d'un long long signé
    printf("\n  Unsigned long long int : %lu", sizeof(ull)); // taille d'un long long non signé


    printf("\nvi. float : ");
    printf("\n  float : %lu", sizeof(f)); // taille d'un float
    
    printf("\nvii. double : ");
    printf("\n  double : %lu", sizeof(d)); // taille d'un double
    
    printf("\nviii. long double : ");
    printf("\n  long double : %lu", sizeof(ld)); // taille d'un long double

    printf("\n");
    return 0;
}
