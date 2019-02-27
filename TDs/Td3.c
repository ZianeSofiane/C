#include <stdio.h>
#include <stdlib.h>

/// Exercice n°1 ///

void entierDecr(int n){
    if(n>=1){
        printf("\n%d\n",n);
        entierDecr(n-1);
    }
}

void entierCroi(int n, int i){
    if(i<=n){
        printf("\n%d\n",i);
        entierCroi(n,i+1);
    }
}
///     |     ///
///     V     ///
/// Plus opti ///
void entierCroi2(int n){
    if(n>1){
        entierCroi2(n-1);
    }
    printf("\n%d\n",n);
}

void entierS(int n){
    if(n>=1){
        printf("\n%d\n",n);
        entierS(n-1);
    }
    printf("\n%d\n",n);
}

/// Exercice n°2 ///

float puissance(float a, int n){
    float res;
    if(n==0) res=1;
        else res = a*puissance(a,n-1);
    return res;
}
/// == ///
float puissance2(float a, int n){
    if(n==0)    return 1;
    if(n>1) a = a*puissance(a,n-1);
    return a;
}

float puissNeg(float a, int n){
    if(n==0)    return 1;
    if(n<-1) {
        a = a*puissNeg(a,n+1);
    }
    return a;
}

float puiss(float a, int n){                /// deux programmes de calculs
    if(n>=0)    return puissance2(a,n);     /// un pour val neg et un pour pos
    if(n<0)     return 1/puissNeg(a,n);;    /// on  applique selon le cas
}

/// Solution plus optimal ///
float puissance3(float a, int n){           /// Plus opti
    if (n>=0)   return puissance2(a,n);     /// vu que 2^-2 = 1/2^2,
    if(n<0) return (1/puissance2(a,-n));    /// quand n<0 on fait 1/2^(-n)
}

/// Exercice n°3 ///
#define max 50

typedef int Tab[max];

void saisie(Tab t, int n){  /// Saisie tableau récursif
    if (n==0)   printf("Erreur"); /* Affiche mess erreur */
    if (n-1>0){              /// on rappel saisie tant que n n'est pas au premier indice
        saisie(t,n-1);      /// donc dès que n-1 > 0, on lit t[n-1]
    }                       /// soit t[0] jusqu'à arriver à t[n]
    scanf("%d",&t[n-1]);
}

/// Déroulement du programme avec n = 3 par exemple:

///     2 > 0
///         saisie(t,2)
///         1 > 0
///              saisie(t,1)
///              ! 0 > 0
///              lecture t[0]
///         lecture t[1]
///     lecture t[2]


int somme(Tab t, int n){
    if(n-1>0){
        return t[n-1] + somme(t,n-1);
    }
    if(n-1==0) return t[n-1];
}

/// Déroulement: Ex avec n = 3

///     2 > 0
///     retourne t[2] + somme(t,2)
///         1 > 0
///         retourne t[1] + saisie(t,1)
///              ! 0 > 0
///              0 == 0
///              retourne t[0]
///         * t[1] + t[0]
///     * t[2] + t[1] + t[0]

void remplacer(Tab t, int n, int e){
    if(n-1>0){
        if(t[n-1]==e)   t[n-1]=0;
        remplacer(t,n-1,e);
    }
}

/// == ///

void remplacer2(Tab t, int n, int e){
    if(n-1>0){
        remplacer(t,n-1,e);
    }
    if(t[n-1]==e)   t[n-1]=0;
}

int tri(Tab t, int n){
    if (n-1>0){
        if (t[n-2] > t[n-1]) return 0;
        return tri(t,n-1);              /// Récursivité fonction(n)
    }                                   /// void => fonction(n)
    return 1;                           /// objet => return fonction(n)
}

int min(Tab t, int n, int i){
    if(n-1>0){
        if(t[i] > t[n-1])     i = n-1;
        return min(t,n-1,i);
    }
    return i;
}

/// t = {5,4,6}

/// min(t,3,0)
///     2>0
///        !(t[0] > t[2])
///         min(t,2,0)
///             1>0
///             t[0] > t[1]
///             i = 1
///             min(t,1,1)
///                 !(0>0)
///                 return 1

/*
    if i > n-2  recursif;
    if j!= i    permuter t[i] et t[j];
*/

/// Exercice n°4 ///

typedef char Chaine[20];

int longueur(Chaine c, int l){
    while(c[l]!='\0'){
        return longueur(c,l+1);
    }
    return l;
}

void afficher(Chaine c, int l){
    if(c[l]!='\0'){
        afficher(c,l+1);
    }
    printf("%c",c[l]);
}

/// == ///

void afficher2(Chaine c, int l){
    if(l>=0){
        printf("%c",c[l]);
        afficher2(c,l-1);
    }
}

int egal(Chaine c1, Chaine c2, int l){
    if(longueur(c1,0) != longueur(c2,0))  return 0;
    else if(l!= longueur(c1,0)){
        if(c1[l]!=c2[l])    return 0;
        return egal(c1,c2,l+1);
    }
    return 1;
}

int appart(Chaine c, char l, int n){
    if(n>0){
        if(c[n-1]==l)   return 1;
        return appart(c,l,n-1);
    }
    return 0;
}

/// Exercice n°5 ///

int fact(int n){
    if(n>1) return n*fact(n-1);
    return 1;
}

int sommeFactI(int n){
    int somme = 0;
    for(int i=1 ; i<=n ;i++){
        somme = somme + fact(i);
    }
    return somme;
}

int sommeFactR(int n){
    if(n>1) return (fact(n)+ sommeFactR(n-1));
    return 1;
}

/// Exercice n°6 ///

#define max6 100

typedef int tab[max6];

void saisir(tab t, int n){
    if(n==0)    printf("Aucune valeur a rentrer");
    if(n-1>0) saisir(t,n-1);
    scanf("%d", &t[n-1]);
}

int dicho(tab t, int n, int r){
    if(!tri(t,n))   return -1;
    else if(n==0)    return 0;
    else if(n-1>0){
        if(t[n-1]>r) return dicho(t,n-1,r);
        else if(t[n-1]==r)  return 1;
        else return 0;
    }
}

int dicho2(tab t, int n, int r){
    if(!tri(t,n))   return -1;
    else if(n==0)    return 0;
    for(int i=0 ; i<n ; i++){
        if(t[i]==r)  return 1;
        else if(t[i]>r)  return 0;
    }
    return 0;
}

/// Exercice n°7 ///

#define Fib 100

typedef int Fibonacci[Fib];

int Fibo(int n){
    if(n==1) return 0;
    else if(n==2)   return 1;

    return Fibo(n-1)+Fibo(n-2);
}

void recu(Fibonacci f, int n){
    if(n-1>0)   recu(f,n-1);
    if(n-1==0)  f[n-1]=0;
    else if(n-1==1)  f[n-1]=1;
    else f[n-1] = f[n-2] + f[n-3];
}

void iter(Fibonacci f, int n){
    for(int i=0 ; i<n ; i++){
        if(i==0)    f[i]=0;
        else if(i==1)   f[i]=1;
        else    f[i] = f[i-1] + f[i-2];
    }
}

/**
    Programme principal
**/

int main()
{
    int a;
    printf("\n Quel exercice tester ? \n");
    scanf("%d",&a);
    int y;
    y = scanf("%d",&y);
    printf("%d",y);

    switch(a)
    {
        case 1:;
            /// Exercice n°1 ///

            printf("\n Jusqu'a quel entier voulez-vous aller:\n");
            int n; scanf("%d",&n);

            printf("\n 1) Affichage ordre decroissant ");
            printf("\n 2) Affichage ordre croissant ");
            printf("\n 3) Affichage ordre decroissant 0 puis croissant \n");
            int choix; scanf("%d",&choix);

            switch(choix)
            {
                case 1:;
                    printf("\n Affichage ordre decroissant \n");
                    entierDecr(n);
                break;

                case 2:;
                    printf("\n Affichage ordre croissant \n");
                    entierCroi2(n);
                break;

                case 3:;
                    printf("\n Affichage ordre decroissant 0 puis croissant \n");
                    entierS(n);
                break;
            }

        break;

        case 2:;
            /// Exercice n°2 ///

            printf("\nQuelle puissance calculer?\n");

            int z=scanf("%d",&z);
            printf("%d",z);
            printf("\n%.3f \n",puissance3(2,z));       /// %.3f => Affichage float avec 3 chiffres après la virgule

        break;

        case 3:;
            /// Exercice n°3 ///

            Tab t;
            saisie(t,3);

            for(int i = 0; i<3; i++){
                printf("\n %d \n",t[i]);
            }

            printf("\n %d \n",somme(t,3));

            remplacer(t,3,2);

            for(int i = 0; i<3; i++){
                printf("\n %d \n",t[i]);
            }

            printf("\n %d \n", tri(t,3));

            printf("\n %d \n", min(t,3,0));

        break;

        case 4:;
            /// Exercice n°4 ///

            Chaine c = "Skurt";
            Chaine c1 = "Skuurt";

            printf("\n %d \n", longueur(c,0));

            afficher(c,0);
            afficher2(c,longueur(c,0));

            printf("\n %d \n",egal(c,c1,0));

            printf("\n %d \n",appart(c,'u',longueur(c,0)));

        break;

        case 5:;

        /// Exercice n°5 ///

            n = scanf("%d",&n);

            printf("\n %d \n", fact(n));

            printf("\n %d \n", sommeFactI(n));

            printf("\n %d \n", sommeFactR(n));

        break;

        case 6:;
            /// Exercice n°6 ///

            tab T;

            printf("Combien de valeur voulez vous saisir dans le tableau");
            //int n6; n6 = scanf("%d",&n6);
            saisir(T,3);

            printf("\nAffichage du tableau:\n");

            for(int i = 0; i<3; i++){
                printf("\n %d \n",T[i]);
            }

            printf("\n Quelle valeur chercher: \n");
            int r = scanf("%d",&r);
            printf("\n %d \n",dicho(T,n,r));

        break;

        case 7:;
            /// Exercice n°7 ///

            Fibonacci f;
            printf("Jusqu'ou calculer la suite:");

            int q = scanf("%d",&q);

            recu(f,5);
            for(int i = 0; i<5; i++){
                printf("\n %d \n",f[i]);
            }

        break;


        default:
            return 0;
        break;
    }

    return 0;
}
