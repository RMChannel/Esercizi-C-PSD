#include "item.h"

typedef struct albero *Albero;
typedef struct ramo *Ramo;

Albero newAlbero();
Ramo initAlbero(Albero, Item);
int isEmpty(Albero);
int createRight(Ramo ramo, Albero albero, Item item);
int createLeft(Ramo ramo, Albero albero, Item item);
void printRamo(Ramo ramo);