#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "candidato.h"
#include <string.h>

Item inputItem(){
	printf("Non usare inputItem(). Non richiedere input da tastiera.\n");
	return initCandidato("nome", "cognome",0);
}

void outputItem(Item item){
	Candidato s = item;
	printf("\n%s - %s - %d", name(s), surname(s),score(s));
}

/*
La funzione si occupa di controllare che il primo candidato abbia maggiore del secondo
Prende in input due item, che sono due candidati
Da in output 1 se il punteggio del 1°candidato è maggiore del 2°, altrimenti restituisce 0
*/
int cmpItem(Item item1, Item item2){
	Candidato s1 = item1;
	Candidato s2 = item2;
	//completare con il criterio scelto
	return score(s1)>score(s2);
}
