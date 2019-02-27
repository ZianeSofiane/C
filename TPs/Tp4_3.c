#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
    float valeur;
    struct cell *suivant;
} ListeReel;


int NombreElements(ListeReel *L)
{
    if (L==null)
        return 0;
    else
    return 1+longueur(L->suivant);
}

int nboccurences(ListeReel *L)
    {
        int nb=0;
        if (L==NULL) return 0;

        while (L=NULL)
        {
            if (courant =='r')
            {
                    nb=nb+1;
            }
            L=L->suivant;
        }
    }

