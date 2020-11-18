#include<stdio.h>
#include<stdlib.h>

#define TAILLEINITIALE 100

typedef struct Tableau {
	int* elt;                // le tableau d’entiers
	int size;                // la taille de ce tableau d’entiers
	int eltsCount;           // le nombre d’éléments dans le tableau
} TABLEAU;


TABLEAU newArray() {
	
	int elt[TAILLEINITIALE] = { 0 };
	int eltsCount = 0;
	int size = TAILLEINITIALE;
}