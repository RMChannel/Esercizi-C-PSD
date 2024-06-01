#include "auto.h"
typedef struct catalogo *Catalogo;

Catalogo newCatalogo();
void addCatalogo(Car car, Catalogo catalogo);
void sellCar(Car car, Catalogo catalogo);
void printCatalogo(Catalogo catalogo);
Car searchForMarchio(Catalogo catalogo, char *marchio);
Car searchForModello(Catalogo catalogo, char *modello);