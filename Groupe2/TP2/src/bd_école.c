/*
 * bd_école.c
 * Objectif : Gérer les infos de plusieurs étudiants avec une structure
 * Auteurs : Maël Feri et Aloïs Lienard
 */
#include <stdio.h>
#include <string.h>

#define NB_ETUDIANTS 2
#define TAILLE_NOM 50
#define TAILLE_PRENOM 50
#define TAILLE_ADRESSE 100
#define NB_NOTES 3

typedef struct {
	char nom[TAILLE_NOM];
	char prenom[TAILLE_PRENOM];
	char adresse[TAILLE_ADRESSE];
	float notes[NB_NOTES];
} Etudiant;

int main() {
	Etudiant etudiants[NB_ETUDIANTS];
	int i, j;
	char buffer[TAILLE_ADRESSE];

	printf("Saisie des informations des etudiant.e.s\n");
	for (i = 0; i < NB_ETUDIANTS; i++) {
		printf("\nEtudiant %d :\n", i+1);
		printf("Nom : ");
		fgets(buffer, TAILLE_NOM, stdin);
		buffer[strcspn(buffer, "\n")] = '\0';
		strcpy(etudiants[i].nom, buffer); // copie du nom

		printf("Prenom : ");
		fgets(buffer, TAILLE_PRENOM, stdin);
		buffer[strcspn(buffer, "\n")] = '\0';
		strcpy(etudiants[i].prenom, buffer); // copie du prénom

		printf("Adresse : ");
		fgets(buffer, TAILLE_ADRESSE, stdin);
		buffer[strcspn(buffer, "\n")] = '\0';
		strcpy(etudiants[i].adresse, buffer); // copie de l'adresse

		for (j = 0; j < NB_NOTES; j++) {
			printf("Note %d : ", j+1);
			scanf("%f", &etudiants[i].notes[j]); // saisie des notes
		}
		while (getchar() != '\n'); // Vider le buffer
	}

	printf("\n--- Affichage des informations ---\n");
	for (i = 0; i < NB_ETUDIANTS; i++) {
		printf("\nÉtudiant %d :\n", i+1);
		printf("Nom : %s\n", etudiants[i].nom);
		printf("Prénom : %s\n", etudiants[i].prenom);
		printf("Adresse : %s\n", etudiants[i].adresse);
		printf("Notes : ");
		for (j = 0; j < NB_NOTES; j++) {
			printf("%.2f ", etudiants[i].notes[j]); // affichage des notes
		}
		printf("\n");
	}

	return 0;
}
