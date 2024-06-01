#include <stdio.h>
#include <stdlib.h>
#include "spesa.h"
#include "item.h"

int main() {
    Item item1=newItem("Latte",3,3.5);
    Item item2=newItem("Pollo",2,5);
    Item item3=newItem("Prosciutto",1,4);
    Spesa spesa=newSpesa();
    addItem(spesa,item1);
    addItem(spesa,item2);
    addItem(spesa,item3);
    outputSpesa(spesa);
    printf("Totale: %.2f\n\n",calcolaSpesa(spesa));
    removeItem(spesa,item2);
    outputSpesa(spesa);
    printf("Totale: %.2f\n\n",calcolaSpesa(spesa));
}