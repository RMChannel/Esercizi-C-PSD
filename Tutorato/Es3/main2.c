#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "concorso.h"
#include "candidato.h"
#include "item.h"


void sortByPoints(Concorso c) {
	removeSeventy(c);
	ordinaConcorso(c);
}


// utilizzare questa funzione nel main per <stampare, ordinare, stampare> la playlist
// da completare riga ***
void stampaEordina(Concorso c){
	printf("\n-- Stampa concorso originale --\n");
	printConcorso(c);
	printf("\n-- Stampa concorso dopo ordinamento per gradimento --\n");

	// *** inserire qui la chiamata all'operatore che ordina la concorso per gradimento
	sortByPoints(c);

	printConcorso(c);
	printf("\n\n");
}

// funzione che restituisce un numero intero tra 1 e 100
int randomInt() {
	return 1 + (rand() % 100);
}

int main() {
	srand(time(NULL));
	//completare qui
	Candidato candidato1=initCandidato("Roberto","Cito",randomInt());
	Candidato candidato2=initCandidato("Daniele","Carpentieri",randomInt());
	Candidato candidato3=initCandidato("Aleksander","Chickvilaze",randomInt()); //Creo i candidati con punteggio casuale
	Candidato candidato4=initCandidato("Arjel","Buzi",randomInt());
	Candidato candidato5=initCandidato("Simone","Abbatiello",randomInt());
	Candidato candidato6=initCandidato("Lorenzo Sabato","Cuomo",randomInt());
	Concorso concorso=createConcorso("Informatica"); //Creo il concorso informatica
	addCandidato(concorso,candidato1);
	addCandidato(concorso,candidato2); //Aggiungo tutti i candidati all'esame
	addCandidato(concorso,candidato3);
	addCandidato(concorso,candidato4);
	addCandidato(concorso,candidato5);
	addCandidato(concorso,candidato6);
	stampaEordina(concorso); //Stampo e ordino l'esame
}
