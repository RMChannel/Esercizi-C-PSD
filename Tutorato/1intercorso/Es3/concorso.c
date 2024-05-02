#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "concorso.h"
#include "list.h"
#include "candidato.h"
#define FALSE 0
#define TRUE 1

struct concorso{
	char *name;
	List candidati;
};


Concorso createConcorso(char* name){
	Concorso p = malloc(sizeof(struct concorso));
	p->name = strdup(name);
	p->candidati = newList();
	return p;
}

void addCandidato(Concorso p, Candidato s){
	addHead(p->candidati, s);
}

void removeCandidato(Concorso p, char *name){
	Candidato s = initCandidato(name, "", 0);
	removeListItem(p->candidati, s);
}

void printConcorso(Concorso p){
	printf("Concorso: %s", p->name);
	printList(p->candidati);
	printf("\n");
}

/*
La funzione si occupa di eliminare tutti i candidati con punteggio minore a 70
Si prende in input solo il concorso
E da in output il concorso con le rimozioni adeguate
*/
void removeSeventy(Concorso p) {
	List c=p->candidati; //Mi prendo la lista
	int n=sizeList(c);
	Candidato candidato;
	for(int i=0;i<n;i++) {
		candidato=getListItemPos(c,i); //Prendo i candidati, uno per uno, scorrendo la lista tramite l'indice i
		if (score(candidato)<70) {
			removeListItemPos(c,i); //Nel caso in cui il punteggio è minore di 70 lo vado ad eliminare sfurttando sempre l'indice i
			i--; //Decremento sia i che n, i perché non devo andare avanti visto che l'elemento successivo ha sostituito quello appena eliminato
			n--; //Invece n lo decremento perché la dimensione della lista sarà sicuramente diminuita visto che abbiamo eliminato l'elemento
		}
	}
}


/*
La funzione si occupa di ordinare i candidati del concorso, a seconda del loro punteggio, sfruttando l'algoritmo di sorting chiamato Adaptive Bubble Sort
Prende in input solo il concorso
Da in output il concorso ordinato
*/
void ordinaConcorso(Concorso p) {
	List c=p->candidati; //Mi prendo la lista dei candidati
	int n=sizeList(c);
	int ordinato=TRUE;
	Candidato c1, c2;
	for (int i=1;i<n && ordinato;i++) {
		ordinato=FALSE;
		for (int j=0;j<(n-1);j++) {
			c1=getListItemPos(c,j); //Mi prendo il candidato nella posizione j
			c2=getListItemPos(c,j+1); //Mi prendo il candidato nella posizione j+1
			if (cmpItem(c1,c2)) { //Controllo il punteggio con la cmpItem
				swapCandidato(c1,c2); //Nel caso faccio lo swap tra i due candidati
				ordinato=TRUE;
			}
		}
	}
}