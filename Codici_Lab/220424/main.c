#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "item.h"

/*
Questa funzione serve a contare quante cifre ha un numero
è necessaria per il file, perché per saltare i caratteri
necessari per passare al numero successivo nella stringa linea,
(ovvero la riga del file), devo saltare di n posizioni quante sono le
n cifre
*/
int countCifre(int n) {
    int result=0;
    do {
        n/=10;
        result++;
    } while(n>0);
    return result;
}

int main(int argc, char *argv[]) {
    FILE *fp;
    if((fp=fopen("input.txt","r"))==NULL) { //Controllo che il file esista
        fprintf(stderr,"File non trovato\n");
        exit(EXIT_FAILURE);
    }
    List list;
    Item item;
    Item search=inputItem(12);
    char line[200];
    char *lineP, *lineF;
    int n;
    while(fgets(line,sizeof(line),fp)) {
        list=newList();
        lineP=line; //Mi creo la lista insieme a due altri puntatori, uno di inizio e uno di fine stringa
        lineF=line; //Questo perché, lineP lo usiamo come punto d'appoggio per recuperare ogni numero e lineF lo usiammo come punto finale della stringa, così da non andare fuori memoria
        for(;*lineF;lineF++); //Mando alla fine della stringa lineF
        while(lineP<lineF) {
            sscanf(lineP,"%d",&n); //Mi prendo un numero alla volta
            item=inputItem(n); //Creo litem
            addHead(list,item); //Lo aggiungo alla lista
            lineP+=countCifre(n)+1; //Salto di n cifre, spiegazione vicino alla funzione
        }
        printListRec(list);
        n=0;
        searchListRec(list,search,&n);
        printf("\nConto di 12: %d\nPosizione del primo 12: %d\n",countItemListRec(list,search),n); //Chiamate di test delle funzioni
        destroyListRec(list);
        printf("\n\n");
    }
}