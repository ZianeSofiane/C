#include <stdio.h>
#include <stdlib.h>

typedef char Chaine[25];

typedef struct
{
Chaine plat;
Chaine entree;
Chaine dessert;
float prix;
} Menu;

Menu saisieMenu()
 {
     Menu m1;
     printf("Entrez le plat : \n");

     scanf("%s", m1.plat);

     printf("Entrez l'entree : \n");

     scanf("%s", m1.entree);

     printf("Entrez le dessert : \n");

     scanf("%s", m1.dessert);

//     printf("Entrez le prix : \n");

  //   scanf("%s", &m1.prix);

    return m1;
 }


 typedef struct {
 Menu m1;
 struct Liste *suiv;
 }Liste, *ListeMenus;


 ListeMenus initListeMenus(Menu menuEntree)
 {
     ListeMenus LM;
     LM = (ListeMenus )malloc(sizeof(Menu));
     LM->m1=menuEntree;
     LM->suiv=0;

     return LM;

 }

 ListeMenus ajoutTete(ListeMenus liste, ListeMenus news)
 {
    news->suiv = liste;
    liste = news;

    return liste;


 }

 void afficher(ListeMenus LM1)
 {
     ListeMenus courant = 1;

    while (courant!=0){
         printf("%s", courant->m1);
         courant = courant->suiv;
    }
 }

/*
 void affichageRecursif(ListeMenus courant)
 {
    printf("%s", courant->m1);
    if (courant->suiv !=0)
      {
        affichageRecursif(courant->suiv);
      }
 }



 float prixTotale(ListeMenus LM)
  {
      float prixe;
      ListeMenus courant;


      while(courant!=0)
      {
            prixe = prixe + (m1.prix);
            courant=courant->suiv;
      }
      return prixe;
  }
*/
  int main()
  {
      Menu M;
      ListeMenus LM;
      ListeMenus news;
      int n;
      M=saisieMenu();

      news =initListeMenus(M);

      LM = ajoutTete(LM, news);

      printf("affichage");
      afficher(LM);




      return 0;
  }
