#include <stdio.h>
#include <stdlib.h>
#include "auto.h"
#include "catalogo.h"

int main(){
    Car car1=newcar("DG115DY","Kia Picanto",2006,2005);
    Car car2=newcar("FE320PD","Renault Clio",2014,2015); //Creazione delle 4 auto demo
    Car car3=newcar("DE103CV","Peugeot 207",2006,1948);
    Car car4=newcar("ENZO","Ferrari SP3 Daitona",2022,2022);
    Catalogo catalogo=newCatalogo(); //Creo il catalogo
    addCatalogo(car1,catalogo);
    addCatalogo(car2,catalogo);
    addCatalogo(car3,catalogo); //Aggiungo le 4 auto al catalogo
    addCatalogo(car4,catalogo);
    printf("Aggiunte 4 auto\nContenuto del catalogo:\n"); //Stampo il catalogo
    printCatalogo(catalogo);
    printf("\nRimozione di: "); //Rimuovo la 2°auto
    outputItem(car2);
    removeCatalogo(car2,catalogo);
    printf("Contenuto del catalogo:\n");
    printCatalogo(catalogo);
    printf("\nAggiunta di: "); //La riaggiungo
    outputItem(car2);
    addCatalogo(car2,catalogo);
    printf("\nContenuto del catalogo:\n");
    printCatalogo(catalogo);
    ordinaCatalogo(catalogo); //Ordino il catalogo
    printf("\nOrdino il catalogo:\n");
    printCatalogo(catalogo);
    printf("\nCerco la targa: DG115DY\n"); //Ricerco una targa presente nel catalogo
    searchCar(catalogo,"DG115DY");
    printf("\nCerco la targa: NN000NN\n"); //Ricerco una targa non presente nel catalogo
    searchCar(catalogo,"NN000NN");
}