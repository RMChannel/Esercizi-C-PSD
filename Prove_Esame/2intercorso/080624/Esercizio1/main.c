#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void printTwoMax(List list) {
    printf("Lista prima: ");
    printList(list);
    Item *a=dueMassimo(list);
    printf("\ndueMassimo: ");
    outputItem(a[0]);
    outputItem(a[1]);
    printf("\nLista dopo: ");
    printList(list);
    printf("\n\n");
}

int main() {
    List emptyList=newList(); //Creo la lista vuota
    printTwoMax(emptyList); //Controllo la lista vuota
    Item ciao=malloc(sizeof(char)*10);
    Item mondo=malloc(sizeof(char)*10); //Creo gli item "ciao" e "mondo"
    strcpy(ciao,"ciao");
    strcpy(mondo,"mondo");
    List list1=newList();
    List list2=newList();
    addHead(list1,ciao); //Aggiungo solo l'elemento "ciao" alla lista
    addHead(list2,mondo);
    addHead(list2,ciao); //Aggiungo i 2 elementi della lista
    printTwoMax(list1); //Controllo la 1°lista
    printTwoMax(list2); //Controllo la 2°lista
    List randomList=newList(); //Mi creo la lista randomica
    for(int i=0;i<7;i++) { //Aggiungo gli elementi random
        addHead(randomList,randomItem());
    }
    printTwoMax(randomList); //Controllo  la lista randomica
}