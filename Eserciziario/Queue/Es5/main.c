#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "queue.h"

void reverseQueue(Queue queue) {
	if(!isEmptyQueue(queue)) {
		Item item=dequeue(queue);
		reverseQueue(queue);
		enqueue(queue,item);
	}
}

int main(){
	FILE *fp;
	if((fp=fopen("input.txt","r"))==NULL) {
		fprintf(stderr,"File non trovato\n");
		exit(EXIT_FAILURE);
	}
	char line[200];
	while(fgets(line,sizeof(line),fp)) {
		Queue queue=newQueue();
		char *lineP=line, *lineF=line;
		while(*lineF) lineF++;
		while(lineP<lineF) {
			char *word=malloc(sizeof(char)*50);
			sscanf(lineP,"%s",word);
			enqueue(queue,word);
			lineP+=strlen(word)+1;
		}
		reverseQueue(queue);
		printQueue(queue);
		printf("\n");
		free(queue);
	}
	return 0;
}