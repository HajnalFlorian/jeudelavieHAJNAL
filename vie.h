#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
#define TAILLE 20 // taille du tabcTab
#define CELLULE 30 //Nombre de cellules au depart
#define VIDE '-' //Cellule vide
#define VIE 'X' //Cellule vivante
#define NAISSANTE 'N' //Cellule qui va naitre
#define MORT 'M' //Cellule qui va mourir

typedef struct tPosition
{
	int nX;
	int nY;
}tPosition, *ptPosition;

extern void initTab(char cTab[TAILLE][TAILLE]);
extern void afficherTab(char cTab[TAILLE][TAILLE]);
extern void affectationCellule (char cTab[TAILLE][TAILLE]);
extern int caseplein (char cTab[TAILLE][TAILLE], ptPosition ptPos);
extern void compte(char [TAILLE][TAILLE]);
extern void fichierTexte(char cTab[TAILLE][TAILLE]);

#endif //FONCTIONS_H_INCLUDED
