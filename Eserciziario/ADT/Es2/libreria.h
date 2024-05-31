#include "libro.h"

typedef struct libreria *Libreria;
Libreria createLibreria();
void addLibro(Libreria lib, Libro book);
void printLibreria(Libreria lib);
Libro searchForTitle(Libreria lib, char *s);
Libro searchForAuthor(Libreria lib, char *s);