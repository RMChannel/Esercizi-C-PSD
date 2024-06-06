#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "item.h"

void printArray(Item a[], int n) { //Funzione di stampa dell'array
    for(int i=0;i<n;i++) outputItem(a[i]);
}


/*
Questa funzione si occupa dell'effettivo controllo che la coda sia uguale all'array, per farlo prende in input:
Array di item
Lunghezza
Coda di item
Variabile contatore
*/
void realQueryArrayEquals(Item a[], int n, Queue q, int *i) {
    if(!isEmptyQueue(q) && (*i)<n) { //Se la coda non è vuota e i non ha ancora raggiunto n
        Item item=dequeue(q); //Prendo l'elemento dalla coda
        if(cmpItem(a[(*i)],item)==0) { //Controllo sia uguale a quello preso in esame nell'array
            (*i)++; //Nel caso siano uguali, incremento i
            realQueryArrayEquals(a,n,q,i); //Richiamo ricorsivo
        }
        enqueue(q,item); //Alla fine rimetto tutto nella coda (essendo fatto in modo ricorsivo, la coda sarà rovesciata e per risolvere rifaremo il reverse)
    }
    else if(!isEmptyQueue(q) && (*i)==n) (*i)=-1; //Controllo nel caso in cui la coda non finisse, ma l'array si e nel caso metto i uguale a -1 così da far saltare il controllo nella funzione chiamante
}

/*
Questa funzione si occupa del rovescio della coda
*/
void reverseQueue(Queue q) {
    if(!isEmptyQueue(q)){ //Se la coda non è vuota
        Item item=dequeue(q); //Tolgo l'elemento attuale
        reverseQueue(q); //Richiamo ricorsivo
        enqueue(q,item); //E alla fine rimetto tutto, ma visto che viene fatto dall'ultimo al primo, troveremo che la coda sarà rovesciata
    }
}

/*
Questa funzione è quella che controlla che la coda e l'array siano uguali, per farlo prende in input:
Array di item
La sua lunghezza
Coda di item
*/
int queryArrayEquals(Item a[], int n, Queue q) {
    int i=0; //Variabile contatrice
    realQueryArrayEquals(a,n,q,&i); //Richiamo alla funzione di controllo effettiva
    reverseQueue(q); //Visto che nell'altra funzione rovesciamo la coda, per ripristinarla la rirovesciamo di nuovo
    return i==n; //Ritorno se i è uguale ad n, perché se lo è vuol dire che sicuramente la coda e l'array sono uguali
}

/*
Questa funzione ha 2 scopi:
1°Stampa della coda e dell'array prima e dopo il rihciamo del controllo
2°Richiamo al controllo dell'uguaglianza e stampare il risultato

Prende in input:
Array di item
Lunghezza array
Coda di item
*/
void queryArrayEqualsPrint(Item a[], int n, Queue q) {
    printf("Coda (prima): "); //Stampa array e coda prima del controllo
    printQueue(q);
    printf("\nArray (prima): ");
    printArray(a,n);
    printf("\nConfronto coda e array: "); //Stampo se la coda e array sono uguali, in base alla funzione queryArrayEquals()
    if(queryArrayEquals(a,n,q)) printf("uguali");
    else printf("diversi");
    printf("\nCoda (dopo): "); //Stampo array coda dopo il controllo
    printQueue(q);
    printf("\nArray (dopo): ");
    printArray(a,n);
    printf("\n\n");
}

int main() {
    char *ciao=malloc(sizeof(char)*10);
    char *bella=malloc(sizeof(char)*10); //Mi creo gli item delle varie parole di test
    char *gente=malloc(sizeof(char)*10);
    char *brutta=malloc(sizeof(char)*10);
    strcpy(ciao,"ciao");
    strcpy(gente,"gente"); //Copio i valori negli item
    strcpy(bella,"bella");
    strcpy(brutta,"brutta");
    Item a[10]; //ARRAY DI ITEM
    Queue queue=newQueue(); //CODA DI ITEM
    queryArrayEqualsPrint(a,0,queue); //Richiamo alla funzione con coda e array vuoti
    a[0]=ciao;
    enqueue(queue,ciao);
    queryArrayEqualsPrint(a,1,queue); //Richiamo alla funzione con coda e array che contengono solo "ciao"
    queue=newQueue();
    enqueue(queue,ciao);
    a[0]=ciao;
    a[1]=bella;
    queryArrayEqualsPrint(a,2,queue); //Richiamo alla funzione con coda e array che contengono "ciao" e "bella"
    enqueue(queue,bella);
    queryArrayEqualsPrint(a,2,queue);
    queue=newQueue();
    enqueue(queue,ciao);
    enqueue(queue,bella);
    enqueue(queue,gente);
    a[1]=brutta;
    a[2]=gente;
    queryArrayEqualsPrint(a,3,queue); //Richiamo alla funzione con coda e array che contengono "ciao" "gente" ma con la differenza della parola in mezzo "brutta" e "bella"
}