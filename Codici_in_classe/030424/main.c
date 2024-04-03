#include <stdio.h>
#include "list.h" 
#include "item.h"

int main(){

	printf("Inserisci la lista: ");
	List list=newList();
	int n;
	Item item;
	for (int i=0; i<5; i++){
		item = inputItem();
		addHead(list, item);
	}
	printList(cloneListItem(list));
}