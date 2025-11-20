/*
 * aire.c
 * Objectif : Calculer l'aire d'un cercle avec une fonction
 * Auteurs : Maël Feri et Aloïs Lienard
 */

#include <math.h>
#include <stdio.h>

float calculer_aire(float rayon) {
    return M_PI * rayon * rayon; // formule de l'aire
}

int main() {
    float rayon = 5.0;
    float aire = calculer_aire(rayon); // appel de la fonction
    printf("L'aire du cercle de rayon %.2f est %.2f\n", rayon, aire); // affichage principal
    return 0;
}

