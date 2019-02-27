#include <stdio.h>
#include <stdlib.h>

#define MAX40

typedef struct {
    int i;
    Chaine mm;
    int an;
    double cout;
    int km;
} Voiture;

typedef struct Cell {
Voiture v;
struct cell *s;
}LVoiture;

Voiture saisie_v ()
{
    voiture v;
    scanf("%d%s%d%lf%d", &v.id, &v.mm, &v.an, & v.cout, &v.km);
    return v;
}

void saise_v2(Voiture *v)
{
    scanf("%d%s%d%lf%d", &v->id, &v->mm, &v->an, &->v.cout, &v->km)
}
// creation d'une Lvoiture avec 1 elements

Lvoiture *creation()
{
    LVoiture*L=NULL;
    L=(LVoiture*)malloc(sizeof(LVoiture));
    if (L!=NULL)
    {
        L->v=saisie_v();
        L->s=NULL;
    }
    return L;
}

void affiche_v(Voiture v)
{
    printf ("%d%s%d%lf%d\n"v.id, v.mm, v.an, v.cout, v.km);
}

void affiche(LVoiture L)
{

    if (L!NULL){
        affiche_v(L->v);
        affiche(L->s);
    }
}

Voiture recherche (LVoiture *L, int id)
{
    Voiture voituredefaut;
    voituredefaut.id=-1;

    while(L!=NULL){
        if (L->v.id>valeur)
            return L->v;
    else L=L->s;
    }
    return voituredefaut;
}
