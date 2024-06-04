#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "stack.h"

int calcolo(char c, int n1, int n2) {
	switch(c) {
		case '+':
			return n1+n2;
		case '-':
			return n1-n2;
		case '/':
			return n1/n2;
		case '*':
			return n1*n2;
		default:
			return 0;
	}
}

int main(){
	FILE *fp;
	if((fp=fopen("input.txt","r"))==NULL) {
		fprintf(stderr,"File non trovato\n");
		exit(EXIT_FAILURE);
	}
	char line[200];
	char buffer[10];
	int countExpressions=1;
	while(fgets(line,sizeof(line),fp)) {
		Stack Numbers=newStack();
		Stack Operations=newStack();
		char *lineP=line, *lineF=line;
		int counter=0, result=0;
		while(*lineF) lineF++;
		while(lineP<lineF) {
			sscanf(lineP,"%s",buffer);
			if(buffer[0]>='0' && buffer[0]<='9') {
				int *n=malloc(sizeof(int));
				(*n)=atoi(buffer);
				push(Numbers,n);
				counter++;
			}
			else {
				char *c=malloc(sizeof(char));
				(*c)=buffer[0];
				push(Operations,c);
				if(counter==2) {
					int *item1=top(Numbers);
					pop(Numbers);
					int *item2=top(Numbers);
					pop(Numbers);
					int temp=calcolo(buffer[0],*item2,*item1);
					if(result==0) result=temp;
					else {
						lineP+=strlen(buffer)+1;
						sscanf(lineP,"%s",buffer);
						result=calcolo(buffer[0],temp,result);
					}
					counter=0;
				}
				else if(counter==1) {
					int *item=top(Numbers);
					pop(Numbers);
					result=calcolo(buffer[0],result,*item);
					counter=0;
				}
				else {
					c=top(Operations);
					pop(Operations);
					int *item1=top(Numbers);
					pop(Numbers);
					int *item2=top(Numbers);
					pop(Numbers);
					result+=calcolo(*c,*item2,*item1);
					lineP+=strlen(buffer)+1;
					sscanf(lineP,"%s",buffer);
					c=malloc(sizeof(char));
					(*c)=buffer[0];
					item1=top(Numbers);
					pop(Numbers);
					result=calcolo(*c,*item1,result);
					counter=0;
				}
			}
			lineP+=strlen(buffer)+1;
		}
		printf("--- Espressione %d ---\nEspressione postfix: %sRisultato: %d\n\n",countExpressions,line,result);
		countExpressions++;
	}
	return 0;
}