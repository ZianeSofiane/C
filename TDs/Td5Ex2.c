#include <stdio.h>
#include <stdlib.h>

typedef char Chaine[25];

typedef struct Voiture{
    int id;
    Chaine mm;
    float cout;
    int km;
}Voiture;


typedef struct LVoiture{
    Voiture v;
    struct LVoiture *suivant;
}LVoiture;

Voiture saisie(Voiture v){
    scanf("%d",&v.id);
    scanf("%s",&v.mm);
    scanf("%f",&v.cout);
    scanf("%d",&v.km);

    return v;
}

void affichage(Voiture v){
    printf("\n%d\n",v.id);
    printf("%s\n",v.mm);
    printf("%f\n",v.cout);
    printf("%d\n",v.km);
}

LVoiture* saisieL(LVoiture *l, Voiture v){
    l = (LVoiture*)malloc(sizeof(LVoiture));
    l->v = v;
    l->suivant = NULL;

    return l;
}

void aff(LVoiture *l){
    if(l==NULL) return;
    else{
        affichage(l->v);
        aff(l->suivant);
    }
}

void recherche(LVoiture *l, int id){
    if(l==NULL) printf("aucun id sup");
    else if((l->v).id > id){
        printf("\n premier id trouve : %d \n",(l->v).id);
    }
    else    return recherche(l->suivant,id);
}

LVoiture* ajout(LVoiture *l, Voiture v, int id) {
    LVoiture *courant = l, *pred = NULL, *nouveau;

    while(courant!=NULL && (courant->v).id != id){
        pred = courant;
        courant = courant->suivant;
    }

    if(courant==NULL){
        printf("\n id non trouvee \n");
        return l;
    }

    nouveau = (LVoiture*)malloc(sizeof(LVoiture));
    nouveau->v = v;
    nouveau->suivant = NULL;

    if(courant->suivant == NULL)    courant->suivant = nouveau;
    else{
        if(pred==NULL) {
            pred = courant;
            courant = courant->suivant;
        }
        else{
            pred = pred->suivant;
            courant = courant->suivant;
        }

        pred->suivant = nouveau;
        nouveau->suivant = courant;
    }

    return l;
}


LVoiture* lib(LVoiture *L){
    if(L!=NULL) free(L);

    return NULL;
}

int main(){
    Voiture v;
    v = saisie(v);

    LVoiture *L;

    L = saisieL(L,v);

    aff(L);

    recherche(L,7);

    /*
    L = lib(L);

    aff(L);
    */

    Voiture v2,v3;
    v2 = saisie(v2);
    printf("\n\n");
    v3 = saisie(v3);
    printf("\n\n");

    L = ajout(L,v2,v.id);
    L = ajout(L,v3,v2.id);

    aff(L);

    return 0;
}
