typedef struct Libro *Libro;
Libro initLibro(char *autore, char *titolo, char *editore, int *anno);
char *autore(Libro libro);
char *titolo(Libro libro);
char *editore(Libro libro);
int anno(Libro libro);