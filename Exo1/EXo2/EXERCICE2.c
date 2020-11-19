#include<stdio.h>
#include<stdlib.h>

#define TAILLEINITIALE 100

typedef struct Tableau {
	int* elt;                // le tableau d’entiers
	int size;                // la taille de ce tableau d’entiers
	int eltsCount;           // le nombre d’éléments dans le tableau
} TABLEAU;

TABLEAU newArray() {    // initialse un tableau avec une taille initiale pour les données
	TABLEAU tab;
	tab.eltsCount = 0;
	tab.size = TAILLEINITIALE;
	tab.elt = (int*)malloc(tab.size * sizeof(int));
	if (tab.elt == NULL) return tab;
	for (int i = 0; i < tab.size; i++) {
		tab.elt[i] = 0;
	}
	return tab;
}

int incrementArraySize(TABLEAU* tab, int incrementValue) { // modifie la taille du tableau
