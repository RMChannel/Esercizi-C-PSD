#include <stdio.h>
#include "list.h" 
#include "item.h"

int main(){
	List list=newList();
	if(isEmpty(list)) printf("La lista e' vuota\n");
	return 0;
}