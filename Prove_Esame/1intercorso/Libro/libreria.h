typedef struct Libreria *Libreria;

Libreria newLibreria();
void addLibro(Item libro, Libreria libreria);
void outputLibreria(Libreria libreria);
void ordinaLibreria(Libreria libreria);