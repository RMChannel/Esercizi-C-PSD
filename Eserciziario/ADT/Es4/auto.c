#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auto.h"

struct car { //Definisco la struttura auto
    char *marca;
    char *modello;
    int immatricolazione;
    int prezzo;
};


//Questa funzione mi crea un auto e la restituisce, si prende in input: marca, modello, anno di immatricolazione, prezzo.
Car newcar(char *marca,char *modello,int immatricolazione,int prezzo) {
    Car car=malloc(sizeof(car)); //Alloco lo sapzio necessario
    car->immatricolazione=immatricolazione; //Associo il valore dell'anno di immatricolazione
    car->prezzo=prezzo; //Associo il valore dell'anno di produzione
    char *mar=malloc(sizeof(char)*05); //Mi alloco la memoria per il marchio
    strcpy(mar,marca); //Copio da quella passata
    car->marca=mar; //Passo la stringa alla variabile auto
    char *m=malloc(sizeof(char)*50); //Mi alloco la memoria per il modello
    strcpy(m,modello); //Copio da quello passato
    car->modello=m; //Passo la stringa alla variabile auto
    return car; //Restituisco l'auto
}

void outputItem(Car car) { //Questa funzione si occupa della stampa di tutti i valori di un auto, si prende in input solo l'auto da stampare
    printf("Marca: %s, modello: %s, immatricolazione: %d, prezzo: %d\n",car->marca,car->modello,car->immatricolazione,car->prezzo);
}

int confrontoMarca(Car car1, Car car2) {
    return strcmp(car1->marca,car2->marca);
}

int confrontoModello(Car car1, Car car2) {
    return strcmp(car1->modello,car2->modello);
}