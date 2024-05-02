#include "item.h"

typedef struct list *List;

List newList();
int isEmpty(List);
void addHead(List, Item);
Item removeHead(List);
Item getHead(List);
int sizeList(List);
void printList(List);
Item getListItemPos(List, int);
int setListItemPos(List, int, Item);
Item searchList(List, Item, int *);
Item removeListItem(List, Item);
Item removeListItemPos(List, int );
int addListItem(List, Item, int);
int addListTail(List, Item);
void reverseList(List);
// List cloneList(List);
