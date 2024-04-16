#include <stdio.h>
#include "item.h"
#include "auto.h"
#include "catalogo.h"

int main(int argc, char *argv[]) {
    Item car1=initAuto("DG115DY", 2006, 2005, "Kia Picanto");
    Item car2=initAuto("FM452MZ", 2015, 2014, "Peugeot 2008");
    Item car3=initAuto("CR723RF", 2006, 2005, "Peugeot 207");
    Catalogo catalogo=newCatalogo();
    addCar(catalogo,car1);
    addCar(catalogo,car2);
    addCar(catalogo,car3);
    printCatalogo(catalogo);
    ordinaCatalogo(catalogo);
    printf("\n\n");
    printCatalogo(catalogo);
}