#include "auto.h"
typedef struct Catalogo *Catalogo;

Catalogo newCatalogo();
void addCar(Catalogo, Auto);
int searchCar(Catalogo, Auto);
void ordinaCatalogo(Catalogo);
void printCatalogo(Catalogo);