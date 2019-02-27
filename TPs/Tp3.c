#include <stdio.h>
#include <stdlib.h>

typedef struct _noeud {
  int val;                // Valeur
  struct _noeud *fg, *fd; // Pointeurs fils gauche/droit
} Noeud, *Arbre;

Noeud *creerNoeud(int val) {
  Noeud *noeud = (Noeud *)malloc(sizeof(Noeud));

  noeud->val = val;
  noeud->fg  = NULL;
  noeud->fd  = NULL;

  return noeud;
}

Arbre inserer(Arbre arbre, int n) {
  if (arbre == NULL)
    return creerNoeud(n);

  if (arbre->val > n)
    arbre->fg = inserer(arbre->fg, n);
  else
    arbre->fd = inserer(arbre->fd, n);

  return arbre;
}

void affichageCroissant(Arbre arbre) {
  if (arbre == NULL)
    return;

  affichageCroissant(arbre->fg);
  printf("%d\n", arbre->val);
  affichageCroissant(arbre->fd);
}

void affichageDecroissant(Arbre arbre) {
  if (arbre == NULL)
    return;

  affichageDecroissant(arbre->fd);
  printf("%d\n", arbre->val);
  affichageDecroissant(arbre->fg);
}

void affichage(Arbre arbre, int p) {
  int i;

  if (arbre == NULL)
    return;

  affichage(arbre->fd, p+1);

  for (i = 1; i < p; i++)
    printf("--");

  printf("%d\n", arbre->val);

  affichage(arbre->fg, p+1);
}

int recherche(Arbre arbre, int n) {
  if (arbre == NULL)
    return 0;

  if (arbre->val == n)
    return 1;
  else if (arbre->val > n)
    return recherche(arbre->fg, n);
  else
    return recherche(arbre->fd, n);
}

Arbre plusPetiteValeur(Arbre arbre) {
  if (arbre->fg == NULL)
    return arbre;

  return plusPetiteValeur(arbre->fg);
}

void sommeEtNbValeurs(Arbre arbre, int *somme, int *nbValeurs) {
  if (arbre == NULL)
    return;

  *somme = *somme + arbre->val;
  *nbValeurs = *nbValeurs + 1;

  sommeEtNbValeurs(arbre->fg, somme, nbValeurs);
  sommeEtNbValeurs(arbre->fd, somme, nbValeurs);
}

int hauteur(Arbre arbre) {
  if (arbre == NULL)
    return 0;

  int gauche = 1 + hauteur(arbre->fg);
  int droite = 1 + hauteur(arbre->fd);

  if (gauche > droite)
    return gauche;
  else
    return droite;
}

void supprimerMax(Arbre arbre) {
  Noeud *plusGrand = arbre->fd;
  Noeud *precedent = arbre;

  while (plusGrand->fd) {
    precedent = precedent->fd;
    plusGrand = plusGrand->fd;
  }

  precedent->fd = NULL;

  arbre->val = plusGrand->val;
}

void supprimer(Arbre arbre, int n) {
  if (arbre == NULL)
    return;

  if (arbre->val == n)
    Noeud *plusGrand = arbre->fd;
    Noeud *precedent = arbre;

  while (plusGrand->fd) {
    precedent = precedent->fd;
    plusGrand = plusGrand->fd;
  }

  precedent->fd = NULL;

  arbre->val = plusGrand->val;
  else if (arbre->val > n)
    supprimer(arbre->fg, n);
  else
    supprimer(arbre->fd, n);
}

int main() {
  int i, n, somme = 0, nbValeurs = 0;

  // +-----------------+
  // |   Question  1   |
  // +-----------------+
  Arbre arbre   = NULL;
  int tableau[] = {4, 2, 1, 8, 6, 7, 3, 9, 5};

  // +-----------------+
  // |   Question  3   |
  // +-----------------+
  for (i = 0; i < 9; i++)
    arbre = inserer(arbre, tableau[i]);

  // +-----------------+
  // | Question 4 et 5 |
  // +-----------------+
  // affichageCroissant(arbre);
  // affichageDecroissant(arbre);

  // +-----------------+
  // |   Question  6   |
  // +-----------------+
  affichage(arbre, 1);

  // +-----------------+
  // |   Question  7   |
  // +-----------------+
  printf("Rechercher une valeur : ");
  scanf("%d", &n);

  if (recherche(arbre, n) == 1)
    printf("La valeur %d est presente dans l'arbre.\n\n", n);
  else
    printf("La valeur %d n'est pas presente dans l'arbre.\n\n", n);

  // +-----------------+
  // |   Question  8   |
  // +-----------------+
  printf("Plus petite valeur : %d.\n\n", plusPetiteValeur(arbre)->val);

  // +-----------------+
  // |   Question  9   |
  // +-----------------+
  sommeEtNbValeurs(arbre, &somme, &nbValeurs);
  printf("Le tableau contient %d valeurs dont la somme est %d.\n\n", nbValeurs, somme);

  // +-----------------+
  // |   Question 10   |
  // +-----------------+
  printf("Hauteur de l'arbre : %d.\n\n", hauteur(arbre));

  // +-----------------+
  // |   Question 11   |
  // +-----------------+
  supprimer(arbre, 6);
  printf("Affichage de l'arbre une fois la valeur 6 supprime : \n");
  affichage(arbre, 1);

  return 0;
}
