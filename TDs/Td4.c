#include <stdio.h>
#include <stdlib.h>
//#include <assert.h>

/// Exercice n°1 ///

int *AllocMalloc (int* n){
		int *t;
		scanf("%d", n);
		t= (int*)malloc((*n)*sizeof(int));
		if(t!=NULL){
			for(int i=0; i<*n; i++){
				//printf("Case %d:", i);
				t[i]=0;
			}
		}
		return t;
	}

int* allocation(int *t, int *n){
		t= (int*)malloc((*n)*sizeof(int));
		if(t!=NULL){
			for(int i=0; i<*n; i++){
				//printf("Case %d:", i);
				t[i]=0;
			}
		}
		return t;
}

int* allocation1(int *t, int n){
		t= (int*)malloc(n*sizeof(int));
		if(t!=NULL){
			for(int i=0; i<n; i++){
				//printf("Case %d:", i);
				t[i]=0;
			}
		}
		return t;
}

int* allocation2(){
        int *t;
        int n; scanf("%d",&n);
		t= (int*)malloc(n*sizeof(int));
		if(t!=NULL){
			for(int i=0; i<n; i++){
				//printf("Case %d:", i);
				t[i]=0;
			}
		}
		return t;
}

int* callocation(){
        int *t;
        int n; scanf("%d",&n);
		t= (int*)calloc(n,sizeof(int));

		return t;
}

typedef char Chaine[20];

Chaine* alloChaine(){
    Chaine *c; Chaine p;
    int n; scanf("%d",&n);
    c= (Chaine*)malloc(n*sizeof(Chaine));
    if(c!=NULL){
			for(int i=0; i<n; i++){
				scanf("%s",&c[i]);
			}
		}

    return c;
}

char ** alloChaine2(int n, int m){
    char **c;
//    int n; scanf("%d",&n);
    c = (char**)malloc(n*sizeof(char*));
        for(int i=0; i<n; i++){
            c[i] = (char*)malloc(m*sizeof(char));
        }
    return c;
}

/// Exercice n°2 ///

float* alloEx2(){
    float *f;
    int n;
    scanf("%d",&n);

    f = (float*)malloc(n*sizeof(float));

    if(f!=NULL){
        for(int i; i<n; i++){
            f[i]=0;
        }
    }
    return f;
}

float* calloEx2(){
    float *f;
    int n;
    scanf("%d",&n);

    f = (float*)calloc(n,sizeof(float));

    if(f!=NULL) return f;
}

float* lib(float *f){
    if(f!=NULL) free(f);
}

int** alloMatrice(int nl, int nc){
    int **m;
    m = (int**)calloc(nl,sizeof(int*));
    for(int i=0 ; i<nl ; i++){
        m[i] = (int*)calloc(nc,sizeof(int));
    }
    return m;
}

int** alloMatrice2(int nl, int nc){
    int **m;
    m = (int**)malloc(nl*sizeof(int*));
    for(int i=0 ; i<nl ; i++){
        m[i] = (int*)malloc(nc*sizeof(int));
        for(int j=0 ; j<nc ; j++){
            m[i][j]=(i+1)*(j+1);
        }
    }
    return m;
}

int** libMatrice(int** m){
    if(m!=NULL) free(m);

    return m;
}

/// Exercice n°3 ///

typedef char Ch[7];

typedef struct Vol{
    Ch id;
    int alti;
    int longi;
    int lati;
    float vitesse;
}Vol;

Vol init(){
    Vol v;

    printf("\n id : \n");
    scanf("%s",&(v.id));
    printf("\n alti : \n");
    scanf("%d",&(v.alti));
    printf("\n longi : \n");
    scanf("%d",&(v.longi));
    printf("\n lati : \n");
    scanf("%d",&(v.lati));
    printf("\n vitesse : \n");
    scanf("%f",&(v.vitesse));

    return v;
}

void affVol(Vol v){
    printf("\n id : \n");
    printf("%s",(v.id));
    printf("\n alti : \n");
    printf("%d",(v.alti));
    printf("\n longi : \n");
    printf("%d",(v.longi));
    printf("\n lati : \n");
    printf("%d",(v.lati));
    printf("\n vitesse : \n");
    printf("%f",(v.vitesse));
}

Vol* alloVol(){
    Vol *v;
    int n; scanf("%d",&n);

    v = (Vol*)malloc(n*sizeof(Vol));

    for(int i=0 ; i<n ; i++){
        printf("\n id : \n");
        scanf("%s",&(v[i].id));
        printf("\n alti : \n");
        scanf("%d",&(v[i].alti));
        printf("\n longi : \n");
        scanf("%d",&(v[i].longi));
        printf("\n lati : \n");
        scanf("%d",&(v[i].lati));
        printf("\n vitesse : \n");
        scanf("%f",&(v[i].vitesse));
    }

    return v;
}

int comparaison(Chaine a, Chaine b, int i){
    if(a[i]!=b[i])  return 0;
    if(b[i]=='\0' && a[i]=='\0'){
        return 1;
    }
    if(a[i]==b[i]){
        return comparaison(a,b,i+1);
    }
}

int recherche(Vol *v, Chaine id,int i){
    if(comparaison(v[i].id,id,0)){
        return 1;
    }
    else if(!comparaison(v[i].id,id,0)){
        return recherche(v,id,i+1);
    }
    else return 0;
}

int main(){

    /// Exercice n°1 ///

    int *t; int n; n=4;

 /*   //t = AllocMalloc(&n);
    //t = allocation(&t,&n);
    //t = allocation1(&t,3);
    t = callocation();

    for(int i=0; i<n ; i++){
        printf("\n %d\n", t[i]);
    }

    Chaine *c;
    c = alloChaine();

    for(int i=0; i<n ; i++){
        printf("\n %s\n", c[i]);
    }

    Chaine p;
    char **c1;
    c1 = alloChaine2(3,1);

    for(int i=0; i<3 ; i++){
        scanf("%s",&p);
        for(int j=0; j<3 ; j++){
            c1[i][j]=p[j];
        }
    }
    for(int i=0; i<3 ; i++){
        for(int j=0; j<3 ; j++){
            printf("%c",c1[i][j]);
        }
    }*/

    /// Exercice n°2 ///

   /* float *f;
    f = calloEx2();

    for(int i=0; i<n ; i++){
            printf("\n %f\n", f[i]);
    }

    f = lib(f);

    if(f!=NULL) printf("tableau vide");*/
/*
    int **m;
    m = alloMatrice2(3,3);

    for(int j=0 ; j<3 ; j++){
        printf("\n");
        for(int i=0 ; i<3 ; i++){
            printf(" %d ", m[i][j]);
        }
    }

    m = libMatrice(m);

    if(m!=NULL) printf("\n matrice vide \n");

    /// Exercice n°3 ///

    Vol v;

    v = init();
    affVol(v);*/

    Vol *v2;
    v2 = alloVol();
    /*char a[7] = "Skuurrt";
    char b[7] = "Skuurrt";*/


    printf("%d",comparaison(v2[0].id,v2[1].id,0));
    printf("%d",recherche(v2,"lol",0));

    //printf("%d",recherche(v2,"sku",0));

    return 0;
}
