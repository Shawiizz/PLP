/*
 * main.c
 * Objectif : Calculer et afficher le volume et la surface d'une sphère (utilise sphere.h)
 * Auteurs : Maël Feri et Aloïs Lienard
 */
#include <stdio.h>
#include "sphere.h"

int main() {
    float rayon = 5.0;
    float volume = calculer_volume(rayon);
    float surface = calculer_surface(rayon);

    printf("Le volume de la sphère de rayon %.2f est %.2f\n", rayon, volume);
    printf("La surface de la sphère de rayon %.2f est %.2f\n", rayon, surface);

    return 0;
}
