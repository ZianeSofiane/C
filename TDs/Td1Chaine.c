#include <stdio.h>
#include <stdlib.h>

#define MAX 3
#define max 100
#define mChaine 20

typedef char Chaine[mChaine];

int length(Chaine c){
    int i = 0;
    while (i<mChaine && c[i]!='\0'){
        i++;
    }
    return i;
}

int egal(Chaine ch1, Chaine ch2){
    if(length(ch1)>length(ch2)) return 1;
    else if (length(ch1)==length(ch2))  return 0;
    else    return -1;
}

void concat(Chaine ch, Chaine ch1, Chaine ch2){
    if (length(ch1)+length(ch2) <= 20){
        ch = ch1;
        for(int i=0 ; i<length(ch2); i++){
            ch[length(ch)] = ch2[i];
        }
    }
}

typedef float tab[MAX];

typedef struct Etudiant{
    int id;
    tab notes;
}Etudiant;

void saisie(Etudiant *e){
    printf("id :");
    scanf("%d",&e->id);
    for (int i=0 ; i<MAX ; i++){
        printf("Note %d", i);
        scanf("%f",&e->notes[i]);
    }
}

void moy(Etudiant *e){
    e->notes[2] = (e->notes[0] + e->notes[1])/2;
}

void afficher(Etudiant *e){
    printf("\n id %d", e->id);
    for (int i=0 ; i<MAX ; i++){
        printf("\n note %d : %f", i+1,e->notes[i]);
    }
}


typedef float Tab[max];

int search(int n, Tab t, int r){
    for ( int i=0 ; i<n ; i++){
        if (*(t+i)==r)    return 1;
    }
    return 0;
}

int search2(int n, float *t, int r){
    for ( int i=0 ; i<n ; i++){
        if (*(t+i)==r)    return 1;
    }
    return 0;
}

int palyn(int n, Tab t){
    int i=0,j=n-1;
    while (i!=(n/2) && j!=(n/2)){
        if(t[i]!=t[j]){
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

void max_min(float *maxi, float *min, int n, Tab t){
    *maxi = *t, *min = *t;
    for (int i=1 ; i<n ; i++){
        if(*maxi < *(t+i))   *maxi = *(t+i);
        if(*min > *(t+i))   *min = *(t+i);
    }
}

void echange(float *a, float *b){
    float temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void echangeFau(float a, float b){
    float temp;
    temp = a;
    a = b;
    b = temp;
}

void calcul(int *somme, int* diff, int *mult,int a, int b){
    *somme = a + b;
    *diff = a - b;
    *mult = a * b;
}



int main(){
    int *adresse;
    float *temp;
    float r = 5;
    temp = &r;
    char *lettre;
    char l = 'e';
    lettre = &l;
    *lettre = 'I';

    printf("%f %c", r,l);

    float b = 10;

    printf("\n %f %f", r,b);
    echange(&r,&b);
    printf("\n %f %f", r,b);
    echangeFau(r,b);
    printf("\n %f %f", r,b);

    int s,d,m;
    int a = 2, c = 3;
    calcul(&s,&d,&m,a,c);
    printf("\n %d %d %d", s,d,m);


    Etudiant e;

    saisie(&e);

    afficher(&e);

    moy(&e);

    afficher(&e);

    Tab t;
    t[0] = 2;
    t[1] = 3;
    t[2] = 2;

    printf("\n %d", search2(3,t,3));
    printf("\n %d", palyn(3,t));

    float ma,min;
    max_min(&ma,&min,3,t);
    printf("\n %f  %f", ma,min);

    Chaine ch = "l";
    Chaine ch1;
    Chaine ch2 = "Skurt";

    printf("\n Entrer une chaine");
    scanf("%s",&ch);
    printf("\n taille : %d", length(ch));

    concat(ch1,ch,ch2);

    printf("\n%s",ch);

    return 0;
}
