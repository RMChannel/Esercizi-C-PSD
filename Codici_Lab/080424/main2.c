#include <stdio.h>
#include "item.h"
#include "list.h"

int main(int argc, char *argv) {
    List list=newList();
    printf("Inserisci gli elementi: ");
    for (int i=0;i<5;i++) {
        addHead(list,inputItem());
    }
    bubbleSortList(list);
    printList(list);
}