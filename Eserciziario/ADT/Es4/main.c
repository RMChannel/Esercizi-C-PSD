#include <stdio.h>
#include <stdlib.h>
#include "auto.h"
#include "catalogo.h"

int main(){
    Car car1=newcar("Kia","Picanto",2006,3500);
    Car car2=newcar("Renault","Clio",2014,5000); //Creazione delle 4 auto demo
    Car car3=newcar("Peugeot","207",2006,500);
    Car car4=newcar("Ferrari","SP3 Daitona",2022,2000000);
    Catalogo catalogo=newCatalogo(); //Creo il catalogo
    addCatalogo(car1,catalogo);
    addCatalogo(car2,catalogo);
    addCatalogo(car3,catalogo); //Aggiungo le 4 auto al catalogo
    addCatalogo(car4,catalogo);
    printf("Aggiunte 4 auto\nContenuto del catalogo:\n"); //Stampo il catalogo
    printCatalogo(catalogo);
    printf("\nRimozione di: "); //Rimuovo la 2°auto
    outputItem(car2);
    sellCar(car2,catalogo);
    printf("Contenuto del catalogo:\n");
    printCatalogo(catalogo);
}