/*
 * surface.c
 * Objectif : Calculer la surface d'une sphère (fonction)
 * Auteurs : Maël Feri et Aloïs Lienard
 */
#include <math.h>
#include "sphere.h"

// Fonction pour calculer la surface d'une sphère
float calculer_surface(float rayon) {
    return 4 * M_PI * pow(rayon, 2);
}
