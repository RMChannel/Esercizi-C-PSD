#include <stdlib.h>
#include <string.h>
#include "candidato.h"

struct candidato{
	char *name;
	char *surname;
	int punteggio;
};

Candidato initCandidato(char* name, char* surname, int punteggio){
	Candidato s = malloc(sizeof(struct candidato));
	s->name = strdup(name);
	s->surname = strdup(surname);
	s->punteggio = punteggio;
	return s;
}

char* name(Candidato s){
	char *name = malloc(sizeof(char) * (1+strlen(s->name)));
	strcpy(name, s->name);
	return name;
}

char* surname(Candidato s){
	char *surname = malloc(sizeof(char) * (1+strlen(s->surname)));
	strcpy(surname, s->surname);
	return surname;
}
/*
La funzione ritorna il punteggio del candidato passato
Prende in input un candidato
Restituisce il punteggio
*/
int score(Candidato s) {
	int punteggio=s->punteggio;
	return punteggio;
}

/*
La funzione si occupa di scambiare due candidati
Prende in input i due candidati
Da in output i 2 candidati scambiati
*/
void swapCandidato(Candidato c1, Candidato c2) {
	Candidato temp=initCandidato(name(c1),surname(c1),score(c1)); //Creo un candidato temp dove mi salvo i dati del 1°candidato
	c1->name=c2->name;
	c1->surname=c2->surname;
	c1->punteggio=c2->punteggio;
	c2->name=temp->name; //Faccio lo scambio
	c2->surname=temp->surname;
	c2->punteggio=temp->punteggio;
	free(temp); //Libero la memoria per il candidato temporaneo visto che non serve più
}