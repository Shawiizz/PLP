/*
 * erreurs.c
 * Objectif : Montrer une erreur de tableau
 * Auteurs : Maël Feri et Aloïs Lienard
 */
#include <stdio.h>

int main() {

   int tableau[100];

   for (int compteur = 0; compteur < sizeof(tableau); compteur++) { //Erreur
       tableau[compteur] = tableau[compteur] * 2;
   }

   return (0);

}

