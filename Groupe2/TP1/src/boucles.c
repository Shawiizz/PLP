/*
 * boucles.c
 * Objectif : Afficher des triangles avec différentes boucles (for, while, do while)
 * Auteurs : Maël Feri et Aloïs Lienard
 */
#include <stdio.h>

int main () {
    int compteur;
    printf("\nVeuillez entrez une valeur entiere : ");
    scanf("%d", &compteur); // saisie utilisateur
    
    if (compteur >= 10) { // on limite la taille
        printf("\n error : entrez une valeur < 10");
        return 1;
    }

    printf("\n");

    // triangle rectangle 1 :
    for (int i = 1; i <= compteur; i++ ) {
        for (int j = 1; j <= i ; j++) {
            if (i != compteur ) { // Pour que la derniere ligne ne soit que des "*"
                if (j == 1 || j == i) {
                    printf("* "); // bords
                } else {
                    printf("# "); // intérieur
                }
            } else { 
                printf("* "); // faire la dernière ligne
            }
        }
        printf("\n");
    }

    printf("\nTriangle rectangle 2 :\n\n");
   

    // triangle rectangle 2 : (version while)
    int i = 1;
    int j;
    while (i <=compteur) {
        j=1;
        while (j <= i)
        {
            if (i != compteur ) { // Pour que la derniere ligne ne soit que des "*"
                if (j == 1 || j == i) {
                    printf("* "); // bords
                } 
                else {
                    printf("# "); // intérieur
                }
            } 
            else { 
                printf("* "); // faire la dernière ligne
            }
            j++;
        }
        printf("\n");
        i++;
    }

    printf("\nTriangle rectangle 3 :\n\n");
    // triangle 3 : (version do while)
    i = 1;
    do {
        j=1;
        do {
            if (i != compteur ) { // Pour que la derniere ligne ne soit que des "*"
                if (j == 1 || j == i) {
                    printf("* "); // bords
                } else {
                    printf("# "); // intérieur
                }
            } else { 
                printf("* "); // faire la dernière ligne
            }
            j++;
        } while (j <= i);
        printf("\n");
        i++;
    } while (i <= compteur);


    return 0;
}