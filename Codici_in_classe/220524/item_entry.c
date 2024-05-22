#include "entry.h"
#include "item.h"

int cmpItem(Item i1, Item i2) {
    Entry entry1=i1;
    Entry entry2=i2;
    if (equals(getKey(entry1),getKey(entry2))) return 1;
    else return 0; 
}