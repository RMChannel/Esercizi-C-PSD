#include <stdio.h>
#include "stack.h"
#define N 30


int openOrClosed(char par) {
	if (par=='(' || par=='[' || par=='{') return 1;
	else if (par==')' || par==']' || par=='}') return 2;
	else return 0;
}

int whatType(char par) {
	if (par=='(' || par==')') return 1;
	else if (par=='[' || par==']') return 2;
	else return 3;
}

int isBalanced(char *exp) {
	Stack par=newStack();
	Item n;
	for (;*exp;exp++) {
		n=inputItem(whatType(*exp));
		switch (openOrClosed(*exp)) {
			case 1:
				push(par,n);
				break;
			case 2:
				if (compareItem(top(par),n)) pop(par);
				break;
			default:
				break;
		}
	}
	return isEmptyStack(par);
}


int main() {
	char exp1[N]="(1+[x+{5+4}-7])";
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
