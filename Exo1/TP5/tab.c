#include<stdio.h>
#include<stdlib.h>



int initTab(int * tab, int size) {

	if ((tab == NULL) || (size < 0)) {
		return -1;
	}
	else {
		for (int i = 0; i < size; i++) {
			tab[i] = 0;
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

