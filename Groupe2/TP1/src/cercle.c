/*
 * cercle.c
 * Objectif : Calculer et afficher l'aire et le périmètre d'un cercle à partir du rayon
 * Auteurs : Maël Feri et Aloïs Lienard
 */
#include <stdio.h>

int main () {
    double rayon; //besoin d'une valeur 
    double pi = 3.14159;
    printf("Entrez valeur du rayon : ");
    scanf("%lf", &rayon); // demande de la valeur de rayon
    printf("rayon : %lf \n", rayon);

    // calcul aire et perimetre
    double aire = pi * rayon * rayon;
    double perimetre = 2 * pi * rayon;
    
    // affichage des resultats
    printf("perimetre : %lf \naire : %lf \n", perimetre, aire);
    return 0;
}    