#include<stdio.h>
#include<stdlib.h>

#define TAILLEAJOUT 50


int initTab(int * tab, int size) {

	if ((tab == NULL) || (size < 0)) {
		return -1;
	}
	else {
		for (int i = 0; i < size; i++) {
			tab[i] = 0;  // Le tableau est compl�t� avec uniquement des 0
		}
		return size;
	}
}


int afficheTab(int* tab, int size, int nbElts) {
	if ((tab == NULL) || (size < 0) || (size < nbElts)) {
		return -1;
	}
	else {
		for (int j = 0; j < nbElts; j++) {
			printf("%d", tab[j]);
		}
		return 0;
	}
}
	
int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element) {
	if (tab == NULL || size == NULL || nbElts == NULL || *size < 0 || *nbElts < 0) return NULL; //Valeurs entr�es non valides alors on return NULL
	if (*nbElts + 1 > * size) { //Test si d�passement de capacit�
		int* tmp = tab; //Sauvegarde de l'ancien pointeur si
		tab = (int*)realloc(tab, (*size + TAILLEAJOUT) * sizeof(int));  //Allocation de la m�moire
		if (tab == NULL) { //V�rification que la m�moire a bien �t� allou�e
			tab = tmp;
			return NULL;
		}
		*size += TAILLEAJOUT;
	}
	*(tab + *nbElts) = element;
	*nbElts += 1;
	return tab;
}

