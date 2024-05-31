#include "libro.h"

typedef struct list *List;

List newList();
int isEmpty(List);
void addHead(List, Libro);
Libro removeHead(List);
Libro getHead(List);
int sizeList(List);
int addListTail(List, Libro);
Libro removeListLibro(List, Libro);
void printList(List);
int existLibro(List, Libro);
Libro getNext(List, Libro);