#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "item.h"
#include "stack.h"

Item newItem(char *word) {  //Funzione di creazione item, partendo da una stringa
	char *a=malloc(sizeof(word));
	strcpy(a,word);
	return a;
}

void reverseStack(Stack *stackOrigin, Item param) { //Funzione che restituisce, sul puntatore dello Stack originale, lo Stack invertito e confrontato col parametro
	Item temp[50]; //Array temporaneo
	int i;
	Item item;
	for(i=0;!(isEmptyStack(*stackOrigin));pop(*stackOrigin)) { //Scorro tutto lo stack finché esso non vuoto, eliminando ogni volta che controllo l'elemento verificato col parametro
		item=top(*stackOrigin);
		if(compareItem(item,param)>0) { //Verifica col parametro
			temp[i]=item; //Mi salvo l'elemento
			i++; //Incremento il numero di elementi salvati
		}
	}
	for(int i2=0;i2<i;i2++) push(*stackOrigin,temp[i2]); //Rimetto gli elementi nello stackS
}

int countEquals(Stack *stack, Item param) { //Funzione che restituisce il numero di elementi, presenti nello stack, uguali al parametro passato
	Item item;
	int count=0;
	while(!(isEmptyStack(*stack))) { //Scorro tutto lo stack, eliminando ogni elemento che confronto, finché lo stack non è vuoto
		item=top(*stack); //Prendo l'elemento
		if (!(compareItem(item,param))) count++; //Nel caso in cui la compareitem restituisce 0, allora i due elementi sono sicuramente uguali e allora posso fare il conto
		pop(*stack); //Rimuovo l'elemento
	}
	return count;
}


int main() { // non modificare/spostare questa riga
	srand(time(NULL)); // non modificare/spostare questa riga
	FILE *fp=fopen("input.txt","r");
	Stack stack;
	char line[100], word[20];
	Item param, wordReal;
	char *linep, *linef;
	while(fgets(line,sizeof(line),fp)) {
		stack=newStack();
		linep=line;
		for(linef=line;*linef;linef++); //Mi calcolo il punto finale della stringa
		sscanf(linep,"%s",word); //Mi prendo la prima parola, che corrisponde al parametro
		if(word[0]=='!') param=randomItem(); //Nel caso in cui è un punto esclamativo, allora viene inserito in parametro una parola casuale
		else param=newItem(word); //Altrimenti viene inserita la parola data in input
		linep+=strlen(word)+1; //Salto sulla stringa fino alla nuova parola (+1 perché così saltiamo lo spazio)
		while(linep<linef) { //Andiamo avanti finché non finiamo la riga
			sscanf(linep,"%s ",word); //Prendo ogni parola
			linep+=strlen(word)+1; //Porto avanti il puntatore della riga
			if (strlen(word)>0) { //Nel caso in cui c'è una parola
				if(word[0]=='!') wordReal=randomItem(); //Se è un punto esclamativo, allora anche qui viene inserita una parola casuale
				else wordReal=newItem(word); //Altrimenti viene creato l'item con la parola trovata
				push(stack,wordReal); //E viene aggiunta allo Stack
			}
		}
		printf("Elemento parametro: %s\nStack originale: ",param); //Stampe finali
		printStack(stack);
		printf("\nStack invertito: ");
		reverseStack(&stack,param);
		printStack(stack);
		printf("\n\n");
		//printf("\nElementi uguali trovati al parametro: %d\n",countEquals(&stack,param));
		free(stack); //Libero lo stack
	}
}
