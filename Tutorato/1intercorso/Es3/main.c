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
	FILE *fp;
	Candidato candidato;
	char line[100]="";
	char esame[10]="";
	char *lineP=line, *lineF;
	char nome[20]="";
	char cognome[20]="";
	int punteggio=0;
	if((fp=fopen("input.txt","r"))==NULL) { //Controllo che il file esista
		fprintf(stderr,"File non trovato\n");
		exit(EXIT_FAILURE); //Nel caso termino il programma
	}
	while(fgets(line,sizeof(line),fp)) { //Scansiono il file riga per riga
		lineP=line; //Mi creo un puntatore alla linea, per gestirmi la posizione
		sscanf(line,"%s",esame); //Mi prendo il nome dell'esame
		lineP+=strlen(esame)+1; //Salto sulla linea il nome dell'esame e lo spazio
		for(lineF=lineP;*lineF;lineF++); //Il puntatore lineF serve come indicatore della fine dellla linea
		Concorso concorso=createConcorso(esame); //Creo il concorso
		while(lineP<lineF) { //Il ciclo continua finché non arriviamo al punto finale della linea
			sscanf(lineP,"%s %s %d",nome,cognome,&punteggio); //Mi prendo nome e cognome e punteggio
			lineP+=strlen(nome)+strlen(cognome)+3; //Salto sul puntatore il nome, il cognome e gli spazi
			if (punteggio>10) lineP+=2;//Salto altri 2 caratteri nel caso in cui il punteggio è >10
			else lineP+=1; //Nel caso in cui il punteggio è minore di 10, ne salto solo uno
			candidato=initCandidato(nome,cognome,punteggio); //Creo il candidato
			addCandidato(concorso,candidato); //Aggiungo il candidato al concorso
		}
		stampaEordina(concorso); //Lo stampo e ordino
		free(concorso); //Libero la memoria
	}
}
