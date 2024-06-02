#include <stdio.h>
#include "list.h" 
#include "item.h"

int main(){
	List list=newList();
	char p1[]="lenzuolo";
	char p2[]="testo";
	char p3[]="buongiorno";
	char p4[]="casa";
	addHead(list,p1);
	addHead(list,p2);
	addHead(list,p3);
	addHead(list,p4);
	removeFromChar(list,'b');
	printList(list);
	return 0;
}