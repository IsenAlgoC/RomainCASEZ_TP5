#include<stdio.h>
#include<stdlib.h>

#include"tab.h" // fichier d'entete déclaré avec " " 

#define TAB2SIZE 100 // on 

main() {
	int* myTab2 = (int*)malloc(TAB2SIZE * sizeof(int));

	// Remplissage du tableau avec des 0
	initTab(myTab2, TAB2SIZE);

	// Remplissage des 20 premières valeures du tableau avec les nombres de 1 à 20
	if (myTab2 != NULL) {
		for (int i = 0; i < 20; i++) {
			*(myTab2 + i) = i + 1;
		}
	}

	// Affichage tu tableau
	afficheTab(myTab2, TAB2SIZE, 20);
	printf("\n\n");

	// Ici, on ajoute l'élement 101 à la place  101 du tableau. Réallocation de mémoire nécéssaire.
	int size = TAB2SIZE;
	int nbElmts = 100;
	ajoutElementDansTableau(myTab2, &size, &nbElmts, 101);
	afficheTab(myTab2, size,101);

	// Destruction du tableau
	free(myTab2);
}
