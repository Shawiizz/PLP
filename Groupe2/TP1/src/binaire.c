/*
 * binaire.c
 * Objectif : Convertir un nombre entier en binaire et l'afficher
 * Auteurs : Maël Feri et Aloïs Lienard
 */
#include <stdio.h>

int main () {
    int nbr, 
        bits[50] = {};
    printf("Entrez un nombre entier : ");
    scanf("%d", &nbr);

    // Conversion en binaire
    int count = 0;
    while (nbr > 0) {
        bits[count] = nbr % 2;
        nbr = nbr / 2;
        count++;
    }
    printf("Le nombre binaire est : ");
    for (int i = count - 1; i >= 0; i--) {
        printf("%d", bits[i]);
    }
    printf("\n");
    return 0;
}