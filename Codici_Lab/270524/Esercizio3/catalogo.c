#include <stdlib.h>
#include <stdio.h>
#include "auto.h"
#include "catalogo.h"
#include "list.h"

struct catalogo{ //Mi creo la struttura catalogo con solo la lista
    List catalogo;
};

Catalogo newCatalogo() { //Questa funzione si occupa di creare un catalogo nella memoria
    Catalogo catalogo=malloc(sizeof(struct catalogo)); //Alloco la memoria necessaria
    catalogo->catalogo=newList(); //Associo una lista nuova vuota al catalogo
    return catalogo; //Restituisco il catalogo creato
}

void addCatalogo(Car car, Catalogo catalogo) { //Questa funzione si occupa di aggiungere un auto al catalogo, prende in input l'auto da aggiungere e il catalogo 
    addHead(catalogo->catalogo,car); //Richiamo la funzione addHead sulla lista del catalogo
}

Car removeCatalogo(Car car, Catalogo catalogo) { //Questa funzione si occupa di rimuovere un auto al catalogo, prende in input l'auto da rimuovere e il catalogo 
    return removeListItem(catalogo->catalogo,car); //Richiamo la funzione removeListItem sulla lista del catalogo
}

void ordinaCatalogo(Catalogo catalogo) { //Questa funzione si occupa di ordinare il catalogo in base all'anno di produzione, prende in input il catalogo da ordinare
    bubbleSort(catalogo->catalogo); //Richiamo la funzione di bubbleSort() sulla lista del catalogo
}

void printCatalogo(Catalogo catalogo) { //Questa funzione si occupa della stampa del catalogo, prende in input solo il catalogo da stampare
    printList(catalogo->catalogo); //Richiamo la funzione printList() sulla lista del catalogo
}

void searchCar(Catalogo catalogo, char *targa) { //Questa funzione si occupa di controllare se un auto è presente nel catalogo passato (tramite la sua targa), nel caso risulti nel catalogo la stampa anche
    int n;
    Car car=newcar(targa,"",0,0); //Mi creo un auto temporanea dove darò solo la targa
    Car temp=searchListItem(catalogo->catalogo,car,&n); //Richiamo la funzione di ricerca searchListItem() passandogli l'auto temporanea e mi salvo il valore restituito in una variabile
    if(temp==NULL) { //Se non è presente, e quindi è stato restituito NULL
        printf("Non trovata\n"); //Viene stampato "Non trovata"
    }
    else { //Altrimenti, se è stata trovata
        printf("Trovata: "); //Stampa "Trovata: " e poi stampa l'auto
        outputItem(temp);
    }
    free(car); //Libero la memoria dell'auto temporanea
}