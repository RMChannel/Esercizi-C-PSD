typedef struct libro *Libro;
Libro createLibro(char *t, char *a, char *gen, int anno);
int cmpTitolo(char *s, Libro l);
int cmpAutore(char *s, Libro l);
void outputLibro(Libro l);