#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auto.h"

struct car { //Definisco la struttura auto
    char *targa;
    char *modello;
    int immatricolazione;
    int produzione;
};


//Questa funzione mi crea un auto e la restituisce, si prende in input: targa, modello, anno di immatricolazione, anno di produzione.
Car newcar(char *targa,char *modello,int immatricolazione,int produzione) {
    Car car=malloc(sizeof(car)); //Alloco lo sapzio necessario
    car->immatricolazione=immatricolazione; //Associo il valore dell'anno di immatricolazione
    car->produzione=produzione; //Associo il valore dell'anno di produzione
    char *t=malloc(sizeof(char)*8); //Mi alloco la memoria per la targa
    strcpy(t,targa); //Copio da quella passata
    car->targa=t; //Passo la stringa alla variabile auto
    char *m=malloc(sizeof(char)*50); //Mi alloco la memoria per il modello
    strcpy(m,modello); //Copio da quello passato
    car->modello=m; //Passo la stringa alla variabile auto
    return car; //Restituisco l'auto
}

void outputItem(Car car) { //Questa funzione si occupa della stampa di tutti i valori di un auto, si prende in input solo l'auto da stampare
    printf("targa: %s, immatricolazione: %d, modello: %s, produzione: %d\n",car->targa,car->immatricolazione,car->modello,car->produzione);
}

int cmpItem(Car car1, Car car2) { //Questa funzione mi restituisce la differenza degli anni di produzione delle due auto passate, è necessaria per il bubbleSort del catalogo, si prende in input le due auto da confrontare
    int prod1=car1->produzione; //Mi prendo il 1°anno
    int prod2=car2->produzione; //Mi prendo il 2°anno
    return prod1-prod2; //Restituisco la differenza
}

void swap(Car car1, Car car2) { //Questa funzione si occupa di fare lo swap tra 2 auto, si prende in input le due auto da swappare
    Car temp=newcar(car1->targa,car1->modello,car1->immatricolazione,car1->produzione); //Mi creo un auto temporanea a cui passo i valori della 1°auto 
    car1->immatricolazione=car2->immatricolazione;
    car1->produzione=car2->produzione; //Ai valori della 1°auto associo quelli della 2°
    strcpy(car1->modello,car2->modello);
    strcpy(car1->targa,car2->targa);
    car2->immatricolazione=temp->immatricolazione;
    car2->produzione=temp->produzione; //Poi copio i dati della 1°, dall'auto temporanea, alla 2°
    strcpy(car2->modello,temp->modello);
    strcpy(car2->targa,temp->targa);
    free(temp); //Libero la memoria associata alla 1°auto
    
}

int confrontoTarga(Car car1, Car car2) { //Questa funzione controlla se 2 targhe sono diverse o uguali, prende in input le due auto da confrontare
    return strcmp(car1->targa,car2->targa); //Semplicemente restituisce il valore della strcmp() tra le targhe delle due auto
}