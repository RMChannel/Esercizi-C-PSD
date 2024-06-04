#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h" 
#include "item.h"

void reverseList2(List list) {
	if(!isEmpty(list)) {
		Item item=removeHead(list);
		reverseList2(list);
		addListTail(list,item);
	}
}

int main(){
	FILE *fp;
	if((fp=fopen("input.txt","r"))==NULL) {
		fprintf(stderr,"File non trovato\n");
		exit(EXIT_FAILURE);
	}
	char line[200];
	char word[50];
	while(fgets(line,sizeof(line),fp)) {
		List list=newList();
		char *lineF=line;
		char *lineP=line;
		while(*lineF) lineF++;
		while(lineP<lineF) {
			sscanf(lineP,"%s",word);
			lineP+=strlen(word)+1;
			char *oggetto=malloc(sizeof(word));
			strcpy(oggetto,word);
			addListTail(list,oggetto);
		}
		printList(list);
		reverseList2(list);
		printf("\n");
		printList(list);
		printf("\n\n");
	}
	return 0;
}