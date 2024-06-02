#include <stdio.h>
#include "list.h" 
#include "item.h"

int main(){
	List list=newList();
	char p1[]="gatto";
	char p2[]="luna";
	char p3[]="tonno";
	char p4[]="ciao";
	addHead(list,p1);
	addHead(list,p2);
	addHead(list,p3);
	addHead(list,p4);
	removeFromChar(list,'t');
	printList(list);
	return 0;
}