#include <stdio.h>
#include "stack.h"
#define N 30

/*
Questa funzione serve a capire se il carattere passato è una parentesi,
e se lo è, se è aperta o chiusa.
*/
int openOrClosed(char par) {
	if (par=='(' || par=='[' || par=='{') return 1;
	else if (par==')' || par==']' || par=='}') return 2;
	else return 0;
}
/*
Questa funzione restituisce di che tipo è la parentesi passata
*/
int whatType(char par) {
	if (par=='(' || par==')') return 1;
	else if (par=='[' || par==']') return 2;
	else if  (par=='{' || par=='}') return 3;
	else return 0;
}

/*
Questa funzione controlla se l'espressione data è bilanciata o meno
*/
int isBalanced2(char *exp) {
	Stack par=newStack();
	Item n;
	for (;*exp;exp++) {
		n=inputItem(whatType(*exp)); //Si salva di che tipo è la parentesi data
		switch (openOrClosed(*exp)) { //A seconda se la parentesi è aperta o chiusa eseguiamo delle funzioni, nel caso non sia un parentesi non facciamo niente
			case 1://Parentesi aperta trovata
				push(par,n); //Salviamo la parentesi aperta nello stack
				break;
			case 2://Parentesi chiusa trovata
				if (compareItem(top(par),n)) pop(par); //Nel caso in cui la parentesi chiusa corrisponde a quella nello stack (come tipo), allora la elimina dallo stack
				else return 0; //Se non corrispondono, allora l'equazione sarà sicuramente non bilanciata
				break;
			default:
				break;
		}
	}
	return isEmptyStack(par); //Restituisco se lo stack è vuoto o meno, perché se è vuoto allora vuol dire che l'equazione è bilanciata, altrimenti se non è vuoto, allora non è bilanciata
}

int isBalanced(char *exp) {
	int par;
	if(!(*exp)) return 4;
	else {
		switch(openOrClosed(*exp)) {
			case 1:
				par=isBalanced(exp+1);
				if (par==whatType(*exp)) {
					exp++;
					while(par!=whatType(*exp)) exp++;
					exp++;
					isBalanced(exp);
				}
				else return 0;
				break;
			case 2:
				return whatType(*exp);
				break;
			default:
				isBalanced(exp+1);
				break;
		}
	}
}


int main() {
	char exp1[N]="(1+[x+{5+4}-7])"; //Casi esempio
	char exp2[N]="(1+2";
	char exp3[N]="(2+[3*4+{5])";
	char exp4[N]="";
	char exp5[N]="[";

	printf("1) Valuto: %s\n", exp1);
	if (isBalanced(exp1))
		printf("L' espressione e' bilanciata\n\n");
	else
		printf("L'espressione non e' bilanciata\n\n");

	printf("2) Valuto: %s\n", exp2);
	if (isBalanced(exp2))
			printf("L' espressione e' bilanciata\n\n");
	else
			printf("L'espressione non e' bilanciata\n\n");

	printf("3) Valuto: %s\n", exp3);
	if (isBalanced(exp3))
			printf("L' espressione e' bilanciata\n\n");
	else
			printf("L'espressione non e' bilanciata\n\n");

	printf("4) Valuto: %s\n", exp4);
	if (isBalanced(exp4))
			printf("L' espressione e' bilanciata\n\n");
	else
			printf("L'espressione non e' bilanciata\n\n");

	printf("5) Valuto: %s\n", exp5);
	if (isBalanced(exp5))
			printf("L' espressione e' bilanciata\n\n");
	else
			printf("L'espressione non e' bilanciata\n\n");
}
