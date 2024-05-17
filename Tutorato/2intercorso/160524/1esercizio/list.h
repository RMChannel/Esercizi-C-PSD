#include "item.h"

typedef struct list *List;

List newList();
int isEmpty(List);
void addHead(List, Item);
Item removeHead(List);
Item getHead(List);
int sizeList(List);
int addListTail(List, Item);

void printList(List list);
Item searchListItem(List list, Item item);