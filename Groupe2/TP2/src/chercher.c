#include <stdio.h>

#define NB_PHRASES 10
#define TAILLE_PHRASE 100

// Fonction pour comparer deux chaînes de caractères
int chaines_egales(char *s1, char *s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i])
            return 0;
        i++;
    }
    // Si les deux chaînes se terminent en même temps, elles sont égales
    return (s1[i] == '\0' && s2[i] == '\0');
}

int main() {
    char phrases[NB_PHRASES][TAILLE_PHRASE] = {
        "Bonjour, comment ça va ?",
        "Le temps est magnifique aujourd'hui.",
        "C'est une belle journée.",
        "La programmation en C est amusante.",
        "Les tableaux en C sont puissants.",
        "Les pointeurs en C peuvent être déroutants.",
        "Il fait beau dehors.",
        "La recherche dans un tableau est intéressante.",
        "Les structures de données sont importantes.",
        "Programmer en C, c'est génial."
    };
    char recherche[TAILLE_PHRASE];
    int trouve = 0;

    printf("Entrez la phrase à rechercher : ");
    fgets(recherche, TAILLE_PHRASE, stdin);

    // Enlever le retour à la ligne éventuel (équivalent à strcspn)
    int i = 0;
    while (recherche[i] != '\0') {
        if (recherche[i] == '\n') {
            recherche[i] = '\0';
            break;
        }
        i++;
    }

    for (i = 0; i < NB_PHRASES; i++) {
        if (chaines_egales(phrases[i], recherche)) {
            trouve = 1;
            break;
        }
    }

    if (trouve) {
        printf("Phrase trouvée\n");
    } else {
        printf("Phrase non trouvée\n");
    }

    return 0;
}
