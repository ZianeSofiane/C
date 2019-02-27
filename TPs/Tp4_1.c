#include <stdio.h>
#include <stdlib.h>

// EXO 1 QUESTION 1
typedef struct cell {
    int valeur;
    struct cell *suivant;
} Cellule;

typedef *ListInt;
Cellule *L;
// ou ListeInt L;

//QUESTION 2

.Cellule *creation(){
    Cellule *L;
    L=(Cellule *)malloc(sizeof(Cellule));
    if (L != NULL){
        printf("Entrez un entier:\n");
        scanf("%d", &L->valeur);
        L->suivant=NULL;
        }
return L;
}

// QUESTION 3
Cellule *insertion_tete(Cellule *L, int v)
{
   Cellule *nouveau;
   nouveau=(Cellule *)malloc(sizeof(Cellule));
   nouveau->valeur=v;
   nouveau->suivant=L;
   return nouveau;

}

// QUESTION 4

Cellule *insertion_queue(Cellule *L, int v)
{
    Cellule *nouveau;
    *courant= L;
    nouveau=(Cellule *)malloc(sizeof(Cellule));
        if (L != NULL){
            nouveau->valeur=v;
            nouveau->suivant=NULL;

            if (L != NULL){
                while(courant->suivant!=NULL){
                    courant=courant->suivant;
                    }
                    courant->suivant=nouveau;
                }
            else return nouveau;
        }
      return L;
}

// QUESTION 5

void affichage (Cellule *L)
{
    Cellule *courant=L;
        while(courant != NULL)
        {
            printf("%d", courant->valeur);
            courant=courant->suivant;
        }
}

//QUESTION 6

Cellule *liberation (Cellule *L)
    {
        Cellule *courant=L;
        while (L!= NULL)
        {
            L=L->suivant;
            free(courant);
            courant=L;
        }
        L=NULL;
        return L;
    }
//QUESTION 7

Cellule *insertion (Cellule *L)
{
    Cellule *courant=L;
    Cellule *nouveau;
    Cellule *precedent=NULL;
    nouveau=(Cellule*)malloc(sizeof(Cellule));
    if (nouveau != NULL)
    {

        nouveau->valeur=v;
        while (courant != null && courant->valeur<v)
        {
            precedent=courant;
            courant=courant->suivant;
        }
        if (courant == NULL)
        {
            if (precedent = NULL)
            {

                nouveau->suivant=NULL;
                return nouveau;
            }
            else {
                nouveau->suivant= NULL;
                precendent->suivant=nouveau;
                return L;
            }
            else {
                nouveau=suivant-courant;
                if (precendent != NULL){
                    prec->suivant=nouveau;
                    return L;
                }
            }
        }
    }

    else return L;
}
