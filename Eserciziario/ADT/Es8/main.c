#include <stdio.h>
#include <stdlib.h>
#include "ordine.h"

int main() {
    Ordine ord1=newOrdine(54123,3,15.65,3,5,2024);
    Ordine ord2=newOrdine(34216,1,60,7,5,2024);
    Ordine ord3=newOrdine(20345,9,102.50,1,5,2024);
    Ordini orders=newOrdini();
    addOrdine(orders,ord1);
    addOrdine(orders,ord2);
    addOrdine(orders,ord3);
    showOrders(orders);
    printf("Totale finale: %.2f\n",total(orders));
}