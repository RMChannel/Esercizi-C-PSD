#include <stdio.h>
#include "list.h" 
#include "item.h"

int main(){


	List list=newList ();
	for (int i=0; i<5; i++){
		Item item = inputItem();
		addHead(list, item);
	}
	printList(list);
	printf("\nInserisci l'item da eliminare: ");
	int pos=0;
	scanf("%d",&pos);
	removeListPos(list,pos);
	printList(list);
}