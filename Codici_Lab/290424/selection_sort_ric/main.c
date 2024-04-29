#include <stdio.h>
#include "item.h"
#include "array.h"

int main(int argc, char *argv) {
    Item item1=inputItem(4);
    Item item2=inputItem(5);
    Item item3=inputItem(3);
    Item item4=inputItem(1);
    Item item5=inputItem(2);
    Item array[]={item1,item2,item3,item4,item5};
    int n=5;
    printArray(array,n);
    selectionSortRic(array,n);
    printArray(array,n);
}