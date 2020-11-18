#include<stdio.h>
#include<stdlib.h>

#include"tab.h" // fichier d'entete déclaré avec " " 

#define TAB2SIZE 100
#define nbElts 100



main() {
	int myTab1[10];
	initTab(myTab1, 10);
	afficheTab(myTab1, 10, 10);

	int* tabSize = TAB2SIZE;
	int *myTab2 = NULL;

	myTab2 = (int*)malloc(TAB2SIZE * sizeof(int));
	if (myTab2 != NULL) {
		initTab(myTab2, tabSize);
	}
	else {
		printf("mémoire insuffisante"); return(-1);
	}
	for (int i = 0; i < 20; i++) {
		myTab2[i] = i+1;
	}

	afficheTab(myTab2, TAB2SIZE, 20);
	if (myTab2 != NULL) { free(myTab2); }

	ajoutElementDansTableau(myTab2, &tabSize, nbElts, 17);
	afficheTab(myTab2, TAB2SIZE, nbElts + 1);

	return EXIT_SUCCESS;


}
