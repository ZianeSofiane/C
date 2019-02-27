#include <stdio.h>
#include <stdlib.h>

typedef struct _produit {
    int idP;
    int nbP;
    float PU;
    struct _produit *suiv, *prec;
}Produit, *Liste;


typedef struct{
    Liste debut, fin;
}Stock;


Liste creation(int id, int nb, float pu){
    Liste l;

    l = (Liste)malloc(sizeof(Produit));
    l->idP = id;
    l->nbP = nb;
    l->PU = pu;
    l->suiv = NULL;
    l->prec = NULL;

    return l;
}

int estVide(Stock s){
    if (s.debut==NULL && s.fin==NULL)
        return 1;
    else
        return 0;
}

Liste trie(Stock s){
    Liste sTrie = NULL, temp = NULL;
    if(!(s.debut)&& !(s.fin))
        return NULL;
    else{
        while (s.debut && s.fin){
            if(s.debut->idP > (s.debut->suiv)->idP){
                temp = s.debut;
                s.debut = s.debut->suiv;
                temp->suiv = NULL;
            }
            s.debut->suiv;
            // sTrie = insererTrie(sTrie,temp);
        }
    }
    return s.debut;
}

Stock insererFin(Stock s, Liste nouveau){
    if(estVide(s))
        s.debut = s.debut = nouveau;
    else{
        (s.fin)->suiv = nouveau;
        nouveau->prec = s.debut;
        s.fin = nouveau;
    }
    return s;
}


Stock existe(Stock s, Produit nouv){
    while(s.debut->suiv != NULL){
        if(s.debut->idP == nouv.idP){
            s.debut->nbP = nouv.nbP;
            s.debut->PU = nouv.PU;
            return s;
        }
        s.debut->suiv;
    }

}

void affichageProd (Produit p){
    printf("%d",p.idP);
    printf("%d",p.nbP);
    printf("%f",p.PU);
}

void affStock (Stock s){
    while(s.debut->suiv != NULL){
        printf("%d",s.debut->idP);
        printf("%d",s.debut->nbP);
        printf("%f",s.debut->PU);
        s.debut->suiv;
    }
}

Produit *recherche(Stock s, int unIdP){
    while(s.debut->suiv != NULL){
        if(s.debut->idP == unIdP){
            return (s.debut);
        }
        s.debut->suiv;
    }
    return NULL;
}


Stock decremente(Stock s, int unIdP){
    Liste *l;
    *l = recherche(s,unIdP);
    (*l)->nbP = ((*l)->nbP) -1;

    return s;
}

void Q8(Stock s, int qteMin){
    while(s.debut->suiv != NULL){
        if(s.debut->nbP<qteMin){
            printf("%d",s.debut->idP);
            printf("%d",s.debut->nbP);
            printf("%f",s.debut->PU);
            s.debut->suiv;
        }
    }
}

Stock supprime (Stock s, int unIdP){
    Liste *l;
    *l = recherche(s,unIdP);
    free(*l);
}

int main()
{
    Stock monMagasin;

        Liste l1 = creation(1203,4,60.0);
        Liste l2 = creation(1074,52,35.5);
        Liste l3 = creation(1156,74,12.9);
        Liste l4 = creation(1400,12,21.3);
        Liste l5 = creation(1203,2,61.0);

    monMagasin.debut = trie(monMagasin);
}

