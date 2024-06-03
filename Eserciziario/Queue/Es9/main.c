#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "queue.h"

int isPalindroma(char *s) {
	Queue queue=newQueue();
	char *temp=s;
	while(*temp) temp++;
	temp--;
	while(temp>=s) {
		if((*temp)!=' ') enqueue(queue,inputItem(*temp));
		temp--;
	}
	temp=s;
	while(*temp) {
		if((*temp)!=' ') {
			char *c=dequeue(queue);
			if((*temp)!=(*c)) return 0;
		}
		temp++;
	}
	if((*temp) || (!isEmptyQueue(queue))) return 0;
	return 1;
}

int main(){
	char s[]="angolo bar a bologna";
	printf("%d\n",isPalindroma(s));
	return 0;
}