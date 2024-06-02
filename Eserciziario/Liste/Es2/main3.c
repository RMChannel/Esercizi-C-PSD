#include <stdio.h>
#include "list.h" 
#include "item.h"

int main(){
	List list=newList();
	char p1[]="mango";
	char p2[]="palla";
	char p3[]="punto";
	char p4[]="pollo";
	addHead(list,p1);
	addHead(list,p2);
	addHead(list,p3);
	addHead(list,p4);
	removeFromChar(list,'p');
	printList(list);
	return 0;
}