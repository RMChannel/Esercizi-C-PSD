#include "item.h"

void swap(Item *a, Item *b){
	Item temp=*b;
	*b=*a;
	*a=temp;
}