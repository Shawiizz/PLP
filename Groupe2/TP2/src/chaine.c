/*
 * chaine.c
 * Objectif : Manipuler des chaînes (longueur, copie, concaténation)
 * Auteurs : Maël Feri et Aloïs Lienard
 */
#include <stdio.h>
#include <string.h>

int main () {

    char chaine1[100];
    char chaine2[100];
    char resultat[200];

    printf("Ecrire une chaine n°1 : ");
    fgets(chaine1, sizeof(chaine1), stdin);
    chaine1[strcspn(chaine1, "\n")] = '\0';  // Supprime le retour à la ligne
    printf("Vous avez ecrit : %s", chaine1);

    printf("\nEcrire une autre chaine n°2 : ");
    fgets(chaine2, sizeof(chaine2), stdin);
    chaine2[strcspn(chaine2, "\n")] = '\0';  // Supprime le retour à la ligne
    printf("Vous avez ecrit : %s", chaine2);   
    

    // 1. Longueur des chaînes
    printf("\nLongueur : \n");
    printf("Longueur de chaine n°1 = %lu\n", strlen(chaine1)); // mesure
    printf("Longueur de chaine n°2 = %lu\n", strlen(chaine2));

    // 2. Copier une chaîne dans une autre
    strcpy(resultat, chaine1); // copie chaine1 dans resultat
    printf("\nCopie de chaine n°1 dans resultat : \n");
    printf("Resultat = %s\n", resultat);

    // 3. Concaténer deux chaînes
    strcpy(resultat, chaine1); // recommence avec chaine1
    strcat(resultat, chaine2); // concatène chaine2 à la suite
    printf("\nConcatenation de chaine n°1 et chaine n°2 dans resultat : \n");
    printf("Resultat : %s\n", resultat); // affichage concaténation


    return 0;
}