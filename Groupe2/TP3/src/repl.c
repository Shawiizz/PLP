#include <stdio.h>
#include <string.h>
#include <time.h>
#include "../../TP4/ex4_3.h"

/**
 * Programme qui simule un interpréteur de commandes simple.
 * Il lit les commandes utilisateur et les traite en fonction de leur contenu.
 */

void afficher_version(const char *args, int *continuer);
void afficher_aide(const char *args, int *continuer);
void traiter_echo(const char *args, int *continuer);
void traiter_quit(const char *args, int *continuer);
void afficher_date(const char *args, int *continuer);

// Structure pour stocker les commandes et leurs fonctions associées
typedef void (*cmd_fn_t)(const char *args, int *continuer);

struct Command
{
    const char *name;   // Nom de la commande
    const char* aliases[10]; // Aliases de la commande
    cmd_fn_t function;   // Fonction associée
    const char *help;   // Description pour l'aide
};

// Déclaration du tableau des commandes
static struct Command commands[] =
{
    {"version", {"version", NULL}, afficher_version, "Affiche la version de l'interpréteur"},
    {"help", {"aide", NULL}, afficher_aide, "Affiche les commandes disponibles"},
    {"echo", {"afficher", NULL}, traiter_echo, "Affiche le texte fourni en argument (echo <texte>)"},
    {"quit", {"quitter", "exit", NULL}, traiter_quit, "Quitte l'interpréteur"},
    {"date", {"time", NULL}, afficher_date, "Affiche la date actuelle"},
};

// Nombre de commandes
static const int command_count = sizeof(commands) / sizeof(commands[0]);

void afficher_version(const char *args, int *continuer)
{
    printf("Version: 1.0.0\n");
}

// Date actuelle 
void afficher_date(const char *args, int *continuer){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Date actuelle : ");
    printf("%02d/%02d/%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}

void afficher_aide(const char *args, int *contnuer)
{
    printf("Commandes disponibles:\n");
    for (int i = 0; i < command_count; i++)
    {
        printf("  %s\t- %s\n", commands[i].name, commands[i].help);
    }
}

void traiter_echo(const char *args, int *continuer)
{
    printf("Echo: ");
    if (args == NULL || args[0] == '\0')
    {
        printf("\n");
        return;
    }
    printf("%s\n", args);
}

void traiter_quit(const char *args, int *continuer)
{
    printf("Arrêt...\n");
    if (continuer != NULL)
    {
        *continuer = 0;
    }
}

int main()
{
    int continuer = 1; // Variable pour contrôler la boucle principale

    // Boucle principale qui lit et traite les commandes utilisateur
    while (continuer)
    {
        printf("> "); // Affiche le prompt de commande

        // Buffer pour stocker la commande utilisateur
        char ligne[1024];

        // Lit la commande utilisateur et la stocke dans le buffer
        if (fgets(ligne, sizeof(ligne), stdin) == NULL)
        {
            // Fin de fichier / erreur de lecture
            printf("\nArrêt (EOF)...\n");
            break;
        }

        // Enlève le caractère de fin de ligne ajouté par fgets
        ligne[strcspn(ligne, "\n")] = 0;

        // Ignore les lignes vides
        if (ligne[0] == '\0')
        {
            printf("\n");
            continue;
        }

        // Regarde si ça commence par un chiffre
        if ((ligne[0] >= '0' && ligne[0] <= '9') || ligne[0] == '(')
        {
            char postfix[100];
            infix_to_postfix(ligne, postfix);

            int result = 0;
            evaluate_postfix(postfix, &result);
            printf("%d\n", result);
            continue;
        }

        // Recherche la commande dans le tableau des commandes
        int trouve = 0;
        for (int i = 0; i < command_count; i++)
        {
            // Vérifie le nom principal de la commande
            int len_name = strlen(commands[i].name);
            if (strcmp(ligne, commands[i].name) == 0)
            {
                commands[i].function(NULL, &continuer);
                trouve = 1;
                break;
            }
            if (strncmp(ligne, commands[i].name, len_name) == 0 && ligne[len_name] == ' ')
            {
                const char *args = ligne + len_name + 1;
                commands[i].function(args, &continuer);
                trouve = 1;
                break;
            }

            // Vérifie chaque alias enregistré
            for (int j = 0; commands[i].aliases[j] != NULL; j++)
            {
                const char *alias = commands[i].aliases[j];
                int len_alias = strlen(alias);

                // Correspondance exacte
                if (strcmp(ligne, alias) == 0)
                {
                    commands[i].function(NULL, &continuer);
                    trouve = 1;
                    break;
                }

                // Correspondance avec arguments (alias + espace)
                if (strncmp(ligne, alias, len_alias) == 0 && ligne[len_alias] == ' ')
                {
                    const char *args = ligne + len_alias + 1;
                    commands[i].function(args, &continuer);
                    trouve = 1;
                    break;
                }
            }

            if (trouve)
            {
                break;
            }
        }

        if (!trouve)
        {
            // Affiche un message d'erreur si la commande est inconnue
            printf("Commande non reconnue. Essayez 'help' pour la liste des commandes.\n");
        }

        printf("\n"); // Saut de ligne après la sortie
    }

    return 0;
}
