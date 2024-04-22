#include "item.h"
typedef struct list *List;

List newList();
int isEmpty(List);
void printListRec(List list);
void addHead(List, Item);
Item removeHead(List);
int sizeList(List list);
Item searchListRec(List list, Item item, int *pos);
int countItemListRec(List list, Item item);
void destroyListRec(List list);