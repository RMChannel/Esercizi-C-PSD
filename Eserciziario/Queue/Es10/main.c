#include <stdio.h>
#include "item.h"
#include "queue.h"
#define N 3

int main(){
	Queue queue=newQueue();
	for(int i=0;i<N;i++) {
		char s[200];
		int n;
		printf("Inserisci il nome del piatto: ");
		scanf("%[^\n]",s);
		printf("Inserisci il numero del tavolo: ");
		scanf("%d",&n);
		getchar();
		enqueue(queue,inputItem(s,n));
	}
	for(int i=0;i<N;i++) {
		Item item=dequeue(queue);
		outputItem(item);
	}
	return 0;
}