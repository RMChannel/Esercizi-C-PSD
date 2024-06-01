#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
    List list=newList();
    addTail(list,3);
    addTail(list,4);
    addTail(list,5);
    addTail(list,6);
    addInPos(list,9,2);
    removeItem(list,5);
    printList(list);
}