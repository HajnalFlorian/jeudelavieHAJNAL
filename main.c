#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "vie.h"

int main()
{

    srand(time(NULL));//initialisation de l'aléatoire
    char cTab[TAILLE][TAILLE];//le tableau de caracteres
    int nChoix = 0;

    tPosition position;
    ptPosition ptPos = &position;
        position.nX = 0;
        position.nY = 0;
    initTab(cTab);
    affectationCellule(cTab);

    printf("Tableau initialise\n\n");
    afficherTab(cTab);
    printf("Combien de generations ?\n");
    scanf("%d", &nChoix);

    for(int i = 0; i < nChoix; i++)//Debut du traitement en boucle de l'evolution des cellules
    {

        for(position.nX = 0; position.nX < TAILLE; position.nX++) //double boucle pour, afin d'appliquer l'etat NAISSANTE a une cellule
        {
            for(position.nY = 0; position.nY < TAILLE; position.nY++)
            {
                if((casepleine(cTab, ptPos)==3) && (cTab[position.nX][position.nY] == VIDE))
                {
                    cTab[position.nX][position.nY] = NAISSANTE;
                }
            }
        }
        for(position.nX = 0; position.nX < TAILLE; position.nX++)//double boucle pour, afin d'appliquer l'etat MORT a une cellule
        {
            for(position.nY = 0; position.nY < TAILLE; position.nY++)
            {
                if((cTab[position.nX][position.nY]==VIE)&&((casepleine(cTab, ptPos)<2) || (casepleine(cTab, ptPos)>3)))
                {
                    cTab[position.nX][position.nY] = MORT;
                }
            }
        }
        for(position.nX = 0; position.nX < TAILLE; position.nX++)//double boucle pour, afin de convertir les cellules MORTs et NAISSANTE en VIE ou VIDE
        {
            for(position.nY = 0; position.nY < TAILLE; position.nY++)
            {
                if(cTab[position.nX][position.nY]==MORT)
                {
                    cTab[position.nX][position.nY] = VIDE;
                }
                else if(cTab[position.nX][position.nY]==NAISSANTE)
                {
                    cTab[position.nX][position.nY] = VIE;
                }
            }
        }
        afficherTab(cTab);

        compte(cTab);
        fichierTexte(cTab);

        system("pause");
        system("cls");
    }


    return 0;
}
