#include <stdio.h>
#include <stdlib.h>

typedef char Chaine[15];

typedef struct _produit{
    Chaine idP;
    int nbP;
    float PU;
    struct _produit *suiv, *prec;
    }Produit, *Liste;

typedef struct {Liste debut, fin; } Stock;

/////
Liste creationProduit(Chaine id, int nb, float pu){
    Liste L=(Liste)malloc(sizeof(Produit));
    strcpy(L->idP, id);
    L->suiv=NULL;
    L->nbP=nb;
    L->prec=NULL;
    L->PU=pu;
    return L;}

//////
void insertion(Stock *s, Liste nouveau)
{
    if (s->debut!=NULL) //si liste non vide
        s->fin->suiv = nouveau;
    else {
        s->debut= nouveau;
        s->fin = nouveau ;
    }
return s;
}

//////
void affichage(Stock *s){
    Liste L=s->debut;
    while(L !=NULL){
        printf("%s %d %f", L->idP, L->nbP, L->PU);
        L=L->suiv;
    }
}

//////
void afficheRecursif(Liste L){
    if(L !=NULL){
        printf("%s %d %f", L->idP, L->nbP, L->PU);
        afficheRecursif(L->suiv);}
}
//////
void main(){
    Liste p=creationProduit("CORDE", 4, 60.0);
    Liste p2=creationProduit("CHAUSSONS", 52, 35.5);
    Liste p3=creationProduit("MOUSQUETONS", 74, 12.9);
    Liste p4=creationProduit("CASQUE", 12, 21.3);
    Stock monMagasin;
    monMagasin.debut=monMagasin.fin=NULL;
    insertion(&monMagasin, p);
    insertion(&monMagasin, p2);
    insertion(&monMagasin, p3);
    insertion(&monMagasin, p4);
    affichage(&monMagasin);
}

//////
Liste recherche(Chaine nomP, Stock *s){
    Liste L=s->debut;
    while((L!=NULL) && (strcmp(nomP, L->idP)!=0)){
        L=L->suiv;
    }
    if(L==NULL) return NULL;
    else return L;
}

//////
Liste decremente(Stock *s, int n){
    Liste L=s->debut;
    L=recherche(nomP, s);
    if(L!=NULL) L->nbP -=n;
    else printf("Produit %s non trouvé", nomP);
}

//////

void rechercheaffichage(Liste debut, int n)
    Liste courant=debut;
    if (courant == null)
    {
        printf ("Aucun produits");
    }
    else {
        while (courant!null)
        {
            if (courant->nbP<n)
            {
                printf("Produit %s qté = %d %2.2f euros", courant->idP, courant->nbP, courant->PU);
                courant = courant->suiv
            }
        }
    }

//////

Liste detacheStock(Liste aEnlever, Stock *s)
    Liste courant= aEnlever;

        if (courant !=null)
        {
           if( (s->debut!= courant) &&  (s->fin!=courant));
           {
               courant->prec->suiv=courant->suiv;
               courant->suiv->prec=courant->prec;

           }
           if (courant == s->debut)
           {
               s->debut=courant->suiv;
               courant->suiv->prec=null;
           }

           if (courant == s->fin)
           {
               s->fin =courant->prec;
           }

           courant->prec->suiv=null;
           courant->prec=null;
           courant->suiv=null;
        }

//////
void supprimer (Stock *s, Chaine nomP)
    {
        Liste courant=s->debut;
        courant=recherche(nomP, s)
        if (courant!=NULL)
        {
            detacheStock(courant, S);
            free(courant);
            courant != null;
        }
    }

//////

///renvoie 1 si idP avant celui de son successeur dans la liste
///(1 aussi si
/// son successeur est null, 0 sinon


int estAvant(Liste p)
{
    if ((p!=null) && (p->suiv!=null))
    {
        if (strcmp(p->idP, p->suiv->idP) <0)
        {
            return 1;
        }
        else return 0;

    }
    else return 0;
}
