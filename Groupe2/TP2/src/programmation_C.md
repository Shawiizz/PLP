# Synthèse TP2

## GDB (débogage)

- Compiler avec les infos de debug : `gcc -g fichier.c -o prog`.
- Lancer : `gdb ./prog` puis `run`.
- Commandes utiles : `break fichier.c:ligne`, `run`, `n` / `step`, `p maVar`, `bt`.

## Chaîne de compilation (gcc)

- Étapes : préprocesseur -> compilation -> assemblage -> édition des liens.
- Commandes rapides :
	- `gcc -E main.c -o main.i`
	- `gcc -S main.i -o main.s`
	- `gcc -c main.s -o main.o`
	- `gcc main.o -o main -lm`
- Compiler avec `-Wall -Wextra` pour voir les warnings.


## Chaînes en C

- Une chaîne = `char[]` qui se termine par `\0`.
- Fonctions qu'on utilise souvent : `strlen`, `strcmp`, `strcpy`, `strncpy`, `strcat`, `strstr`, `strcspn`.
- Toujours vérifier la taille des buffers avant de copier/concaténer.

## Structures et fichiers

- Exemple de `struct` :

```
struct Etudiant { char nom[50]; char prenom[50]; int notes[5]; };
```

- Lire un fichier ligne par ligne : `fopen`, `fgets`, `fclose`.
- Pour chercher une phrase dans une ligne on peut utiliser `strstr` et afficher la ligne quand on la trouve.