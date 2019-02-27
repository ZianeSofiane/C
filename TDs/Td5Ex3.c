#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
    float v;
    struct cell *suiv;
} ListeReel;


float saisirFloat() /// fonction pour rendre plus pratique la suite du TP
{
    float valeur;
    printf("Saisissez un reel: \n");
    scanf("%f", &valeur);
    return valeur;
}


ListeReel *creation() /**premiere case**/
{
    ListeReel *LR;
    LR=(ListeReel*)malloc(sizeof(ListeReel));
    LR->v=saisirFloat();
    LR->suiv=NULL;
    return LR;
}

ListeReel *ajoutTete(ListeReel *LR)
{
    ListeReel *news;
    news=(ListeReel*)malloc(sizeof(ListeReel));
    news->v=saisirFloat();
    news->suiv =LR;
    return news;
}

int longueur(ListeReel *LR)
{
   if(LR == NULL)
       {
           return 0;
       }

        return longueur(LR->suiv)+1;
}


int occurence(ListeReel *LR, float r, int occ)
{

    ListeReel *courantR=LR;

 while(LR!=NULL)
    {
     if(courantR->v ==r)
        {
            occ=occ+1;
        }
        occurence(courantR->suiv, r, occ);
    }
return occ;

}







float elementPos(ListeReel *LR, int pos)
{
    int i;
    ListeReel *courant=LR;

      if (courant==NULL) return;

    while (i<pos)
    {
        i++;
        courant=courant->suiv;
    }

    return courant->v;

}


int main()
{
    ListeReel *LR;
    LR=creation();
    LR=ajoutTete(LR);
    LR=ajoutTete(LR);
    LR=ajoutTete(LR);
    LR=ajoutTete(LR);


    int l=longueur(LR);
    printf("Longueur : %d \n", l);


   /** int occu= occurence(LR, 2, 0);
    printf("Nombre d'occurence de 2: %d \n", occu);**/

    float posi=elementPos(LR, 2);
    printf("l'elemen numero 2 est %f", posi);
}
