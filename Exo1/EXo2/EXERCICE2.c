#include<stdio.h>
#include<stdlib.h>

#define TAILLEINITIALE 100

typedef struct Tableau {
	int* elt;                // le tableau d’entiers
	int size;                // la taille de ce tableau d’entiers
	int eltsCount;           // le nombre d’éléments dans le tableau
} TABLEAU;

//************************************************************************************************************//

TABLEAU newArray() {
	TABLEAU tab;
	tab.size = TAILLEINITIALE;                        //initialisation de la taille
	tab.elt = (int*)malloc(tab.size * sizeof(int));   //allocation de la mémoire 
	if (tab.elt == NULL) return tab;                  //vérification de l'allocation de la mémoire
	for (int i = 0; i < tab.size; i++) {              //initialisation du tableau avec des 0
		*(tab.elt + i) = 0;
	}
	tab.eltsCount = 0;
	return tab;
}

//************************************************************************************************************//

int incrementArraySize(TABLEAU* tab, int incrementValue) {
	if (((*tab).elt == NULL) || (incrementValue <= 0)) return -1;                           //conditions d'incrémentation
	int* tmp = (*tab).elt;                                                                  //variable temporaire au cas ou la mémoire n'est pas allouée
	(*tab).elt = (int*)realloc((*tab).elt, ((*tab).size + incrementValue) * sizeof(int));   //allocation de la nouvelle mémoire
	if ((*tab).elt == NULL) {                                                               //vérification de l'allocation de la mémoire
		(*tab).elt = tmp;
		return -1;
	}
	for (int i = (*tab).size; i < (*tab).size + incrementValue - 1; i++) {                  //mise à 0 de toutes les nouvelles valeurs 
		(*tab).elt[i] = 0;
	}
	(*tab).size += incrementValue;                                                          //augmentation de la taille du tableau
	return (*tab).size;
}

//************************************************************************************************************//

int setElement(TABLEAU* tab, int pos, int element) {
	if (((*tab).elt == NULL) || (pos < 1)) return 0;                                //conditions de validation
	if (pos - 1 < (*tab).size) {                                                    //premier cas si on ne dépasse pas la mémoire allouée
		(*tab).elt[pos - 1] = element;                                              //on incruste l'élement dans le tableau
		return 0;
	}
	else {

		if (incrementArraySize(tab, pos - (*tab).size) == -1) return 0;             //si on dépasse la mémoire, on augmente cette mémoire
		(*tab).elt[pos - 1] = element;                                              //on y ajoute ensuite l'élement
		return pos;

	}
}

//************************************************************************************************************//

int displayElements(TABLEAU* tab, int startPos, int endPos) {
	int temp;
	if (((*tab).elt == NULL) || (startPos < 1) || (endPos > (*tab).size) || (endPos < 1) || (startPos > (*tab).size)) return -1; //on vérifie que tout est valide
	if (startPos > endPos) {                                                                                                     //si start > end, on échange les deux.
		temp = startPos;
		startPos = endPos;
		endPos = temp;
	}
	if (startPos == endPos) {                                                                               //si les les deux sont égaux, on ne display qu'un élément
		printf("pos %d : %d\n", startPos, (*tab).elt[startPos - 1]);
		return 0;
	}
	for (int i = startPos - 1; i < endPos; i++) {                                                          //sinon on display tout entre start et end
		printf("%d ", (*tab).elt[i]);
	}
	return 0;
}

//************************************************************************************************************//

int deleteElements(TABLEAU* tab, int startPos, int endPos) {
	int* tmp;                                                                        //variable pour enregistrer le tableau
	int temp;                                                                        //variable pour échanger start et end
	if (((*tab).elt == NULL) || (startPos < 1) || (endPos > (*tab).size)) return -1; //on vérifie que tout est valide
	if (startPos > endPos) {                                                         //si start > end, on échange les deux.
		temp = startPos;
		startPos = endPos;
		endPos = temp;
	}
	if (startPos == endPos) {                                                        //on supprime un seul élément, et on décale tout les éléments de 1 vers la gauche apres celui supprimé
		for (int i = startPos - 1; i < (*tab).size - 1; i++) {
			(*tab).elt[i] = (*tab).elt[i + 1];
		}
		tmp = (*tab).elt;
		(*tab).elt = (int*)realloc((*tab).elt, ((*tab).size - 1) * sizeof(int));    //on diminue la mémoire de 1 vu qu'un élément a été supprimé
		if ((*tab).elt == NULL) {                                                   //on vérifie que la mémoire s'est bien réallouée apres le changement
			(*tab).elt = tmp;
			return -1;
		}
		return (*tab).size;
	}
	for (int i = startPos - 1; i < (*tab).size - (endPos - startPos + 1); i++) {   //cas ou l'on supprime au minimum 2 éléments (n=2 si deux éléments etc..)
		(*tab).elt[i] = (*tab).elt[i + endPos - startPos + 1];                     //on décale tout ce qu'il y a après end vers start (décalage de "n" vers la gauche)
	}
	tmp = (*tab).elt;
	(*tab).elt = (int*)realloc((*tab).elt, ((*tab).size - (endPos - startPos + 1)) * sizeof(int)); //réallocation de la mémoire
	if ((*tab).elt == NULL) {                                                                      //on vérifie que la réallocation a bien fonctionnée
		(*tab).elt = tmp;
		return -1;
	}
	return (*tab).size;
}

//************************************************************************************************************//

int main() {
	TABLEAU tab = newArray();        // on initialise le tableau
	setElement(&tab, 1, 2);          //test: on place l'élément 2 à la premiere place du tableau
	setElement(&tab, 4, 6);          //test: on place l'élément 6 à la quatrième place du tableau
	displayElements(&tab, 1,4);      //on utilise la fonction display comme 2 est bien inférieur à 6,
	deleteElements(&tab, 2, 3);      // on supprime les élément entre la position 1 et 4 
	printf("\n");
	displayElements(&tab, 1, 4);

	return EXIT_SUCCESS;
}