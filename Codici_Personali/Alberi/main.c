#include <stdio.h>
#include <stdlib.h>
#include "alberi.h"
#include "item.h"

int main(int argc, char *argv[]) {
    Albero albero=newAlbero();
    Item item=inputItem(5);
    Ramo ramoBase=initAlbero(albero,item);
    item=inputItem(7);
    createLeft(ramoBase,albero,item);
    item=inputItem(6);
    createRight(ramoBase,albero,item);
    printRamo(ramoBase);
}