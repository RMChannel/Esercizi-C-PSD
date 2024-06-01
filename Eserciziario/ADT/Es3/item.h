typedef struct item *Item;

Item newItem(char *name, int q, float p);
void outputItem(Item item);
float returnPrice(Item item);