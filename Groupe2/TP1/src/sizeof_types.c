/*
 * sizeof_types.c
 * Objectif : Afficher la taille des types de base en C
 * Auteurs : Maël Feri et Aloïs Lienard
 */
#include <stdio.h>

int main() {
    printf("Taille des types en octets :\n\n"); // affichage principal

    printf("i. char : ");
    printf("\n  char : %lu", sizeof(char)); // taille d'un char
    printf("\n  Signed char : %lu", sizeof(signed char)); // taille d'un char signé
    printf("\n  Unsigned char : %lu", sizeof(unsigned char)); // taille d'un char non signé
    
    printf("\nii. short : ");
    printf("\n  short : %lu", sizeof(short)); // taille d'un short
    printf("\n  Signed short : %lu", sizeof(signed short)); // short signé
    printf("\n  Unsigned short : %lu", sizeof(unsigned short)); // short non signé

    printf("\niii. int : ");
    printf("\n  int : %lu", sizeof(int)); // taille d'un int
    printf("\n  Signed int : %lu", sizeof(signed int)); // int signé
    printf("\n  Unsigned int : %lu", sizeof(unsigned int)); // int non signé

    printf("\niv. long int : ");
    printf("\n  long int : %lu", sizeof(long int)); // taille d'un long
    printf("\n  Signed long int : %lu", sizeof(signed long int)); // long signé
    printf("\n  Unsigned long int : %lu", sizeof(unsigned long int)); // long non signé

    printf("\nv. long long int : ");
    printf("\n  long long int : %lu", sizeof(long long int)); // taille d'un long long


    printf("\nvi. float : ");
    printf("\n  float : %lu", sizeof(float)); // taille d'un float
    
    printf("\nvii. double : ");
    printf("\n  double : %lu", sizeof(double)); // taille d'un double
    
    printf("\nviii. long double : ");
    printf("\n  long double : %lu", sizeof(long double)); // taille d'un long double

    return 0;
}
