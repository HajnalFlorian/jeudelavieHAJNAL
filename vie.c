#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "vie.h"

//**********************************************
//BUT : Initialisation du tableau de caracteres
//ENTREES : Tableau
//SORTIES : Tableau initialiser de "-"
//**********************************************
void initTab(char cTab[TAILLE][TAILLE])
{
    int i = 0;
    int j = 0;

    for(i = 0; i < TAILLE; i++)
    {
        for(j = 0; j < TAILLE; j++)
        {
            cTab[i][j] = VIDE;
        }
    }
}

//*****************************************
//BUT : Affichage du tableau
//ENTREES : Tableau
//SORTIES : Tableau affiché
//*****************************************
void afficherTab(char cTab[TAILLE][TAILLE])
{
    int i = 0;
    int j = 0;

    for(i = 0; i < TAILLE; i++)
    {
        for(j = 0; j < TAILLE; j++)
        {
            printf("%c ", cTab[i][j]);
        }
        printf("\n");
    }
}


//**********************************************************************************
//BUT : random qui affecteles cellule en vie.
//ENTREES : Tableau
//SORTIES : cellule vie affecter
//**********************************************************************************
void affectationCellule(char cTab[TAILLE][TAILLE])
{
    int nRand1 = 0;
    int nRand2 = 0;
    int nCpt = 0;

    for(nCpt = 0; nCpt<CELLULE; nCpt++)//Génération de CELL (= 30 au départ) cellules
    {
        nRand1 = (rand() % (TAILLE));
        nRand2 = (rand() % (TAILLE));
        cTab[nRand1][nRand2] = VIE;
    }
}



//****************************************************
//BUT : Verification des cellules en etat MORT ou VIE
//ENTREES : Tableau + coordonnées
//SORTIES : Cellules MORT et VIE autour de la case
//****************************************************
int casepleine (char cTab[TAILLE][TAILLE], ptPosition ptEmplacement)
{
	int nCellVie = 0;

    if(((cTab[(*ptEmplacement).nX-1][(*ptEmplacement).nY-1]) == VIE) || ((cTab[(*ptEmplacement).nX-1][(*ptEmplacement).nY-1]) == MORT))
	    {
	        nCellVie += 1;
	    }

    if(((cTab[(*ptEmplacement).nX-1][(*ptEmplacement).nY]) == VIE) || ((cTab[(*ptEmplacement).nX-1][(*ptEmplacement).nY]) == MORT))
	    {
	        nCellVie += 1;
	    }

    if(((cTab[(*ptEmplacement).nX-1][(*ptEmplacement).nY+1]) == VIE) || ((cTab[(*ptEmplacement).nX-1][(*ptEmplacement).nY+1]) == MORT))
	    {
	        nCellVie += 1;
	    }

    if(((cTab[(*ptEmplacement).nX][(*ptEmplacement).nY-1]) == VIE) || ((cTab[(*ptEmplacement).nX][(*ptEmplacement).nY-1]) == MORT))
	    {
	        nCellVie += 1;
	    }

    if(((cTab[(*ptEmplacement).nX][(*ptEmplacement).nY+1]) == VIE) || ((cTab[(*ptEmplacement).nX][(*ptEmplacement).nY+1]) == MORT))
	    {
	        nCellVie += 1;
	    }

    if(((cTab[(*ptEmplacement).nX+1][(*ptEmplacement).nY-1]) == VIE) || ((cTab[(*ptEmplacement).nX+1][(*ptEmplacement).nY-1]) == MORT))
	    {
	        nCellVie += 1;
	    }

    if(((cTab[(*ptEmplacement).nX+1][(*ptEmplacement).nY]) == VIE) || ((cTab[(*ptEmplacement).nX+1][(*ptEmplacement).nY]) == MORT))
	    {
	        nCellVie += 1;
	    }

    if(((cTab[(*ptEmplacement).nX+1][(*ptEmplacement).nY+1]) == VIE) || ((cTab[(*ptEmplacement).nX+1][(*ptEmplacement).nY+1]) == MORT))
    	{
    	    nCellVie += 1;
    	}

    return nCellVie;
}

void compte(char cTab[TAILLE][TAILLE])
{
    //*****************************************************************************
    //  BUT : Affiche le nombre de cellules mortes et vivante pendant le programme
    //  ENTREES : Tableau
    //  SORTIES : Tombre de cellules mortes et vivantes
    //*****************************************************************************
    int i = 0;
    int j = 0;
    int nVie = 0;
    int nMort = 0;

    for(i = 0; i < TAILLE; i++)
    {
        for(j = 0; j < TAILLE; j++)
        {
            if(cTab[i][j]==VIE)
            {
                nVie += 1;
            }

            if(cTab[i][j]==VIDE)
            {
                nMort += 1;
            }

        }
    }
    printf("Nombre de cellules mortes : %d\nNombre de cellules vivantes : %d\n\n", nMort, nVie);
}

void fichierTexte(char cTab[TAILLE][TAILLE])
{
	FILE* fichierTexte = NULL;

	int i = 0;
    int j = 0;
    int nVie = 0;
    int nMort = 0;

    for(i = 0; i < TAILLE; i++)
    {
        for(j = 0; j < TAILLE; j++)
        {
            if(cTab[i][j]==VIE)
            {
                nVie += 1;
            }

            if(cTab[i][j]==VIDE)
            {
                nMort += 1;
            }
        }
    }

    fichierTexte = fopen("Cellules vivantes-mortes.txt", "a");
    fprintf(fichierTexte, "Nombre de cellules mortes : %d\nNombre de cellules vivantes : %d\n\n", nMort, nVie);
    fclose(fichierTexte);

}
