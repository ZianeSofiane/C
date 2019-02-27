
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Q1
// NB: On a ajouté un paramètre n pour utiliser cette fonction dans la question 3 (pour conserver la valeur de n)
float *InitialiseTabReels(int *n) {
    int i;
    float *tab;

    printf("Saisissez le nombre de reel que vous voulez stocker dans le tableau.\n");
    scanf("%d", n);

    tab = (float *) calloc(/*(size_t)*/ *n, sizeof(float));

    for (i = 0; i < *n; i++) {
        printf("Saisissez le reel n°%d.\n", i + 1);
        scanf("%f", (tab + i));
    }

    return tab;
}

// Q2
void afficherRecursive(float *tab, int n) {
    if (n > 1) {
        afficherRecursive(tab, n - 1);
    }

    printf("%f\n", *(tab + n - 1));
}

// Q3
void testexo1() {
    float *tab;
    int n = 0;

    tab = InitialiseTabReels(&n);
    afficherRecursive(tab, n);

    // On libère le tableau de réels
    free(tab);
    tab = NULL;
}

/**
 * Exercice 2
 */

// Q1
typedef struct {
    char identifier[8]; // 8 car 7 caractères + 1 caractère de fin de chaîne = 8
    int altitude,
            longitude,
            latitude;
    float vitesse;
} Vol;

Vol *saisirVol() {
    Vol *vol;
    vol = (Vol *) calloc(1, sizeof(Vol));

    // Saisie
    printf("Saisissez l'identifiant du vol.\n");
    scanf("%s", vol->identifier);

    printf("Saisissez l'altitude du vol.\n");
    scanf("%d", &vol->altitude);

    printf("Saisissez la longitude du vol.\n");
    scanf("%d", &vol->longitude);

    printf("Saisissez la latitude du vol.\n");
    scanf("%d", &vol->latitude);

    printf("Saisissez la vitesse du vol.\n");
    scanf("%f", &vol->vitesse);

    return vol;
}

// Q2
void afficheVol() {
    Vol *vol;
    vol = saisirVol();

    printf("Le vol %s s'effectue à une altitude de %d, une longitude de %d, une latitude de %d, et à une vitesse de %f",
           vol->identifier, vol->altitude, vol->longitude, vol->latitude, vol->vitesse);

    free(vol);
    vol = NULL;
}

// Q3
Vol *saisirNvols(int n) {
    Vol *Nvols;
    int i;

    Nvols = (Vol *) calloc((size_t) n, sizeof(Vol));

    for (i = 0; i < n; i++) {
        printf("--- Saisie du vol n°%d de la liste des vols ---\n", i + 1);

        Nvols[i] = *saisirVol();


    }

    return Nvols;
}

// Q4
int TrouverVolParId(Vol *vols, char *identifier, int n) {
    if (0 == strcmp((vols + n - 1)->identifier, identifier))
    // strcmp est une fonction qui permet de comparer deux chaines de caracteres
    {
        return 1;
    }

    if (n > 0) {

        return TrouverVolParId(vols, identifier, n - 1);
    }

    return 0;
}

// Q5
void exo2() {
    Vol *Nvols;
    char identifierRechercher[8];
    int n = 2;

    Nvols = saisirNvols(n);

    printf("Saisissez l'identifiant du vol pour savoir si celui-ci existe.\n");
    scanf("%s", identifierRechercher);

    if (1 == TrouverVolParId(Nvols, identifierRechercher, n)) {
        printf("Le vol d'identifiant %s a bien ete trouve.", identifierRechercher);
    } else {
        printf("Aucun vol portant l'identiant %s n'a été trouvé.", identifierRechercher);
    }

    free(Nvols);
    Nvols = NULL;
}

/**
 * Tests de l'exercice 1
 */
void MainExo1() {
    testexo1();
}

/**
 * Tests de l'exercice 2
 */
void MainExo2() {
    // Q2
    int choix;
    printf("\n--- Test de saisie et d'affichage d'un vol ---\n");
    afficheVol();

    printf("\n Voulez vous afficher plusieurs vols?");
    scanf("%d", &choix);
    if (choix == 1){
    // Q5 (teste les fonctions des questions précédentes de l'exercice)
    printf("\n--- Test de saisie de plusieurs vols ---\n");
    exo2();
    }
    else if (choix!=1)
    {
        printf("\n Vous ne voulez pas saisir plusieurs vols!\n");
    }


}

/**
 * Main - Test des exercices
 */

int main() {
    int input = 1;
    const char* MESSAGE_ERREUR_SAISIE = "Votre saisie n'a pas été reconnue, merci de recommencer.";

    do {
        printf("Sélectionnez un exercice à tester.\n"
                       "<1> Exercice 1\n"
                       "<2> Exercice 2\n"
                       "<3> Exercice 3\n"
                       "<0> Terminer le programme\n");

        if (1 == scanf("%d", &input)) {
            switch (input) {
                case 1:
                    printf("\n EXERCICE 1\n\n");
                    MainExo1();
                    break;
                case 2:
                    printf("\n EXERCICE 2\n\n");
                    MainExo2();
                    break;
               /* case 3:
                    printf("\n----- Test de l'exercice 3 -----\n\n");
                    reviewExercise3();
                    break; */
                case 0:
                    printf("Au revoir !");
                    break;
                default:
                    puts(MESSAGE_ERREUR_SAISIE);
            }
        } else {
            puts(MESSAGE_ERREUR_SAISIE);

            // On vide le buffer pour éviter certains problèmes qui pourraient intervenir après la mauvaise saisie
            scanf("%*[^\n]");
        }
    } while (0 != input);

    return EXIT_SUCCESS;
}
