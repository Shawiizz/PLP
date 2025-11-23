/*
 * couleurs.c
 * Objectif : Compter les couleurs distinctes dans un tableau de couleurs
 * Auteurs : Maël Feri et Aloïs Lienard
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	unsigned char r, g, b, a;
} Couleur;

// Compare deux couleurs (1 si égales, 0 sinon)
int couleurs_egales(Couleur c1, Couleur c2) {
	return c1.r == c2.r && c1.g == c2.g && c1.b == c2.b && c1.a == c2.a; // test d'égalité
}

int main() {
	// Table couleurs initialisée statiquement ci-dessous
	int i, j, nb_distinctes = 0;
	Couleur distinctes[100];
	int occurrences[100] = {0};

	Couleur couleurs[100] = {
		// Rouge (10)
		{255,0,0,255},{200,0,0,255},{150,0,0,255},{255,50,50,255},{255,100,100,255},
		{128,0,0,255},{64,0,0,255},{255,0,0,128},{255,0,0,64},{180,20,20,255},

		// Vert (10)
		{0,255,0,255},{0,200,0,255},{0,150,0,255},{50,255,50,255},{100,255,100,255},
		{0,128,0,255},{0,64,0,255},{0,255,0,128},{0,255,0,64},{20,180,20,255},

		// Bleu (10)
		{0,0,255,255},{0,0,200,255},{0,0,150,255},{50,50,255,255},{100,100,255,255},
		{0,0,128,255},{0,0,64,255},{0,0,255,128},{0,0,255,64},{20,20,180,255},

		// Jaune / Orange (10)
		{255,255,0,255},{255,200,0,255},{255,150,0,255},{255,230,100,255},{255,190,70,255},
		{255,165,0,255},{255,140,0,255},{255,215,0,255},{255,255,102,255},{200,150,50,255},

		// Violet / Magenta (10)
		{128,0,128,255},{150,0,150,255},{200,50,200,255},{255,0,255,255},{220,110,220,255},
		{180,60,180,255},{128,0,128,128},{100,0,100,255},{140,40,140,255},{170,20,170,255},

		// Cyan / Teal (10)
		{0,255,255,255},{0,200,200,255},{0,150,150,255},{0,230,230,255},{50,200,200,255},
		{0,128,128,255},{0,64,64,255},{0,255,255,128},{0,255,255,64},{20,180,180,255},

		// Gris / Neutres (10)
		{128,128,128,255},{160,160,160,255},{96,96,96,255},{200,200,200,255},{80,80,80,255},
		{40,40,40,255},{220,220,220,255},{180,180,180,255},{140,140,140,255},{100,100,100,255},

		// Noir / Blanc (10)
		{0,0,0,255},{10,10,10,255},{20,20,20,255},{255,255,255,255},{245,245,245,255},
		{230,230,230,255},{15,15,15,255},{25,25,25,255},{240,240,240,255},{200,200,200,255},

		// Mélanges divers (10)
		{123,45,67,255},{34,139,34,255},{255,20,147,255},{255,140,0,255},{75,0,130,255},
		{60,179,113,255},{106,90,205,255},{173,216,230,255},{255,105,180,255},{255,69,0,255},

		// Duplicates pour compter (10) — certains répètent des couleurs ci-dessus
		{255,0,0,255},{0,255,0,255},{0,0,255,255},{255,255,0,255},{128,128,128,255},
		{0,0,0,255},{255,255,255,255},{128,0,128,255},{0,255,255,255},{255,165,0,255}
	};

	// Recherche des couleurs distinctes et comptage des occurrences
	for (i = 0; i < sizeof(couleurs)/sizeof(Couleur); i++) {
		int trouve = 0;
		for (j = 0; j < nb_distinctes; j++) {
			if (couleurs_egales(couleurs[i], distinctes[j])) { // si déjà vue
				occurrences[j]++;
				trouve = 1;
				break; // on arrête dès qu'on trouve
			}
		}
		if (!trouve) {
			distinctes[nb_distinctes] = couleurs[i]; // nouvelle couleur
			occurrences[nb_distinctes] = 1;
			nb_distinctes++;
		}
	}

	printf("\nCouleurs distinctes et leur nombre d'occurrences :\n");
	for (i = 0; i < nb_distinctes; i++) {
		printf("Couleur %d : (R=%d, G=%d, B=%d, A=%d) -> %d fois\n", i+1, distinctes[i].r, distinctes[i].g, distinctes[i].b, distinctes[i].a, occurrences[i]);
	}

	return 0;
}
