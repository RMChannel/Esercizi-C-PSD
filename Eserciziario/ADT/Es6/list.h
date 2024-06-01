typedef struct list *List;
List newList();
int isEmpty(List list);
void addHead(List list, int n);
void addTail(List list, int n);
void printList(List list);
void addInPos(List list, int n, int pos);
int removeItem(List list, int n);