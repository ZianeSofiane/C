typedef int tab[100][100] ;

void init(int n, int m, tab T )
{
int i;
int j;
for (i=0; i<n; i++){
		for (j=0; j<m; j++)
{
			T[i][j] =0 ;
		}
	}
}


void calculs (tab T, int n, int m)
{
int i;
int nbr=0;
int S=0;

for (i=0; i<n; i++)
	{
		if (T[i][m] !=  0)
			{
                nbr=nbr+1 ;
                S= S + T[i][m] ;
			}
	}
}



typedef int tab2[10];

void tab1 (tab T; int colonne; int ligne)
{
int cpt, int i, int j ;

for (j=0, j< ligne, j++)
    {
        cpt=0 ;
        for (i=0, i<colonne, i++)
            {
                if (T[i][j] !=0)
                    {
                        cpt++ ;
                    }
            }

        Tab2[i]=cpt ;
	}
}
