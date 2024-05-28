#include "auto.h"
typedef struct catalogo *Catalogo;

Catalogo newCatalogo();
void addCatalogo(Car car, Catalogo catalogo);
Car removeCatalogo(Car car, Catalogo catalogo);
void ordinaCatalogo(Catalogo catalogo);
void printCatalogo(Catalogo catalogo);
void searchCar(Catalogo catalogo, char *targa);