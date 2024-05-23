#include "key.h"
#include "item.h"

typedef struct entry *Entry;

Entry newEntry(Key, Item);
Key getKey(Entry);
Item getValue(Entry);