#include "entry.h"
#include "key.h"

typedef struct hashtable *HashTable;

HashTable newHashtable(int);
int insertHash(HashTable, Entry);
Entry searchHash(HashTable, Key);
Entry deleteHash(HashTable, Key);
void printHash(HashTable);
