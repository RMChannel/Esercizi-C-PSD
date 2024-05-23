#include <stdlib.h>
#include "key.h"
#include "entry.h"

struct entry{
    Key key;
    Item value;
};

Entry newEntry(Key key, Item item) {
    Entry entry=malloc(sizeof(entry));
    entry->key=key;
    entry->value=item;
    return entry;
}

Key getKey(Entry entry) {
    if(entry==NULL) return NULL;
    else return entry->key;
}

Item getValue(Entry entry) {
    if(entry==NULL) return NULL;
    else return entry->value;
}