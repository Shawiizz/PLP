/*
 * volume.c
 * Objectif : Calculer le volume d'une sphère (fonction)
 * Auteurs : Maël Feri et Aloïs Lienard
 */
#include <math.h>
#include "sphere.h"

// Fonction pour calculer le volume d'une sphère
float calculer_volume(float rayon) {
    return (4.0 / 3.0) * M_PI * pow(rayon, 3);
}
