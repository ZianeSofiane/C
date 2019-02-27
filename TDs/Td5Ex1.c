#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
    int v;
    struct cell *suivant;
} ListeInt;


ListeInt* creation(){
    ListeInt *L;
    L = (ListeInt*)malloc(sizeof(ListeInt));

    scanf("%d",&(L->v));
    L->suivant = NULL;

    return L;
}

ListeInt* ajoutTete(ListeInt *L, int v){
    if(L==NULL){
        L = (ListeInt*)malloc(sizeof(ListeInt));
        L->v = v;
        L->suivant = NULL;

        return L;
    }
    if(L!=NULL){
        ListeInt *L2;
        L2 = (ListeInt*)malloc(sizeof(ListeInt));

        L2->v = v;
        L2->suivant = L;

        return L2;
    }
}

ListeInt* ajoutQueue(ListeInt *L, int v){
    ListeInt *L2 = L;
    if(L==NULL){
        L = (ListeInt*)malloc(sizeof(ListeInt));
        L->v = v;
        L->suivant = NULL;

        return L;
    }
    if(L->suivant!=NULL){
        L->suivant = ajoutQueue(L->suivant,v);
        return L;
    }
    else{
        (L->suivant) = (ListeInt*)malloc(sizeof(ListeInt));

        (L->suivant)->v = v;

        (L->suivant)->suivant = NULL;
    }

    return L;
}

ListeInt* ajoutQueue2(ListeInt *L, int v){
    ListeInt *L2 = L;
    if(L==NULL){
        L = (ListeInt*)malloc(sizeof(ListeInt));
        L->v = v;
        L->suivant = NULL;
    }
    else if(L->suivant!=NULL){
        ajoutQueue(L->suivant,v);
    }
    else{
        (L->suivant) = (ListeInt*)malloc(sizeof(ListeInt));

        (L->suivant)->v = v;

        (L->suivant)->suivant = NULL;
    }

    return L;
}

void affichage(ListeInt* L){
    if(L==NULL)   return;

    printf("%d",L->v);
    affichage(L->suivant);
}

ListeInt* lib(ListeInt *L){
    if(L!=NULL) free(L);

    return NULL;
}


ListeInt* ajoutOrdre(ListeInt *L, int v){
    ListeInt *ap = L;
    ListeInt *av = L;

    if(ap->v > v)   return ajoutTete(L,v);
    else    ap = ap->suivant;

    while(ap->v <= v){
        if(ap->suivant==NULL){
            return ajoutQueue(L,v);
        }
        else{
            ap = ap->suivant;
            av = av->suivant;
        }
    }

    ListeInt *nouv;
    nouv = (ListeInt*)malloc(sizeof(ListeInt));
    nouv->v = v;
    av->suivant = nouv;
    nouv->suivant = ap;

    return L;
}


int main(){
    ListeInt *L;
    /*L = NULL;*/
    L = creation();

    printf("%d\n",L->v);

    L = ajoutTete(L,4);
    printf("%d",L->v);

    printf("%d\n",(L->suivant)->v);

    L = ajoutQueue(L,9);

    printf("%d",L->v);

    printf("%d",(L->suivant)->v);

    printf("%d\n",(L->suivant->suivant)->v);


    affichage(L);
/*
    L = lib(L);

    affichage(L);

    L = ajoutTete(L,7);

    L = ajoutQueue(L,4);

    affichage(L);*/

    L = ajoutOrdre(L,8);

    printf("\n\n");
    affichage(L);


    return 0;
}
