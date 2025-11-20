/*
 * phrases.c
 * Objectif : Chercher et compter une phrase dans un fichier texte
 * Auteurs : Maël Feri et Aloïs Lienard
 */
#include <stdio.h>
#include <string.h>

int main() {
    char phrase[300];
    char nom_fichier[50];
    char ligne[1024];
    int total_occurrences = 0;

    printf("Nom du fichier : ");
    fgets(nom_fichier, sizeof(nom_fichier), stdin);
    nom_fichier[strcspn(nom_fichier, "\n")] = '\0';

    printf("Phrase à rechercher : ");
    fgets(phrase, sizeof(phrase), stdin);
    phrase[strcspn(phrase, "\n")] = '\0';

    // Ouverture du fichier en lecture
    FILE *f = fopen(nom_fichier, "r");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 1;
    }

    // Lecture du fichier ligne par ligne
    while (fgets(ligne, sizeof(ligne), f) != NULL) {
        char *ptr = ligne;
        while ((ptr = strstr(ptr, phrase)) != NULL) {
            total_occurrences++;
            ptr += strlen(phrase);
        }
    }

    fclose(f); // Fermeture du fichier

    printf("La phrase '%s' a été trouvée %d fois dans le fichier '%s'.\n", phrase, total_occurrences, nom_fichier);
    return 0;
}