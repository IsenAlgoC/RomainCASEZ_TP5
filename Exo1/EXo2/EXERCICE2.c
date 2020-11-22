#include<stdio.h>
#include<stdlib.h>

#define TAILLEINITIALE 100

typedef struct Tableau {
	int* elt;                // le tableau d�entiers
	int size;                // la taille de ce tableau d�entiers
	int eltsCount;           // le nombre d��l�ments dans le tableau
} TABLEAU;

//************************************************************************************************************//

TABLEAU newArray() {
	TABLEAU tab;
	tab.size = TAILLEINITIALE;                        //initialisation de la taille
	tab.elt = (int*)malloc(tab.size * sizeof(int));   //allocation de la m�moire 
	if (tab.elt == NULL) return tab;                  //v�rification de l'allocation de la m�moire
	for (int i = 0; i < tab.size; i++) {              //initialisation du tableau avec des 0
		*(tab.elt + i) = 0;
	}
	tab.eltsCount = 0;
	return tab;
}

//************************************************************************************************************//

int incrementArraySize(TABLEAU* tab, int incrementValue) {
	if (((*tab).elt == NULL) || (incrementValue <= 0)) return -1;                           //conditions d'incr�mentation
	int* tmp = (*tab).elt;                                                                  //variable temporaire au cas ou la m�moire n'est pas allou�e
	(*tab).elt = (int*)realloc((*tab).elt, ((*tab).size + incrementValue) * sizeof(int));   //allocation de la nouvelle m�moire
	if ((*tab).elt == NULL) {                                                               //v�rification de l'allocation de la m�moire
		(*tab).elt = tmp;
		return -1;
	}
	for (int i = (*tab).size; i < (*tab).size + incrementValue - 1; i++) {                  //mise � 0 de toutes les nouvelles valeurs 
		(*tab).elt[i] = 0;
	}
	(*tab).size += incrementValue;                                                          //augmentation de la taille du tableau
	return (*tab).size;
}

//************************************************************************************************************//

int setElement(TABLEAU* tab, int pos, int element) {
	if (((*tab).elt == NULL) || (pos < 1)) return 0;                                //conditions de validation
	if (pos - 1 < (*tab).size) {                                                    //premier cas si on ne d�passe pas la m�moire allou�e
		(*tab).elt[pos - 1] = element;                                              //on incruste l'�lement dans le tableau
		return 0;
	}
	else {

		if (incrementArraySize(tab, pos - (*tab).size) == -1) return 0;             //si on d�passe la m�moire, on augmente cette m�moire
		(*tab).elt[pos - 1] = element;                                              //on y ajoute ensuite l'�lement
		return pos;

	}
}

//************************************************************************************************************//

int displayElements(TABLEAU* tab, int startPos, int endPos) {
	int temp;
	if (((*tab).elt == NULL) || (startPos < 1) || (endPos > (*tab).size) || (endPos < 1) || (startPos > (*tab).size)) return -1; //on v�rifie que tout est valide
	if (startPos > endPos) {                                                                                                     //si start > end, on �change les deux.
		temp = startPos;
		startPos = endPos;
		endPos = temp;
	}
	if (startPos == endPos) {                                                                               //si les les deux sont �gaux, on ne display qu'un �l�ment
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
	int temp;                                                                        //variable pour �changer start et end
	if (((*tab).elt == NULL) || (startPos < 1) || (endPos > (*tab).size)) return -1; //on v�rifie que tout est valide
	if (startPos > endPos) {                                                         //si start > end, on �change les deux.
		temp = startPos;
		startPos = endPos;
		endPos = temp;
	}
	if (startPos == endPos) {                                                        //on supprime un seul �l�ment, et on d�cale tout les �l�ments de 1 vers la gauche apres celui supprim�
		for (int i = startPos - 1; i < (*tab).size - 1; i++) {
			(*tab).elt[i] = (*tab).elt[i + 1];
		}
		tmp = (*tab).elt;
		(*tab).elt = (int*)realloc((*tab).elt, ((*tab).size - 1) * sizeof(int));    //on diminue la m�moire de 1 vu qu'un �l�ment a �t� supprim�
		if ((*tab).elt == NULL) {                                                   //on v�rifie que la m�moire s'est bien r�allou�e apres le changement
			(*tab).elt = tmp;
			return -1;
		}
		return (*tab).size;
	}
	for (int i = startPos - 1; i < (*tab).size - (endPos - startPos + 1); i++) {   //cas ou l'on supprime au minimum 2 �l�ments (n=2 si deux �l�ments etc..)
		(*tab).elt[i] = (*tab).elt[i + endPos - startPos + 1];                     //on d�cale tout ce qu'il y a apr�s end vers start (d�calage de "n" vers la gauche)
	}
	tmp = (*tab).elt;
	(*tab).elt = (int*)realloc((*tab).elt, ((*tab).size - (endPos - startPos + 1)) * sizeof(int)); //r�allocation de la m�moire
	if ((*tab).elt == NULL) {                                                                      //on v�rifie que la r�allocation a bien fonctionn�e
		(*tab).elt = tmp;
		return -1;
	}
	return (*tab).size;
}

//************************************************************************************************************//

int main() {
	TABLEAU tab = newArray();        // on initialise le tableau
	setElement(&tab, 1, 2);          //test: on place l'�l�ment 2 � la premiere place du tableau
	setElement(&tab, 4, 6);          //test: on place l'�l�ment 6 � la quatri�me place du tableau
	displayElements(&tab, 1,4);      //on utilise la fonction display comme 2 est bien inf�rieur � 6,
	deleteElements(&tab, 2, 3);      // on supprime les �l�ment entre la position 1 et 4 
	printf("\n");
	displayElements(&tab, 1, 4);

	return EXIT_SUCCESS;
}