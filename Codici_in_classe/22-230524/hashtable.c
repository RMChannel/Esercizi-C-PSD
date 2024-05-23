#include <stdlib.h>
#include "entry.h"
#include "hashtable.h"
#include "key.h"
#include "list.h"

struct hashtable {
    List *entries;
    int size;
};

HashTable newHashtable(int size) {
    HashTable hashtable=malloc(sizeof(HashTable));
    hashtable->size=size;
    hashtable->entries=malloc(sizeof(List)*size);
    for(int i=0;i<size;i++) hashtable->entries[i]=newList();
    return hashtable;
}

void insertHash(HashTable hashtable, Entry entry) {
    Key key=getKey(entry);
    int index=hashValue(key,hashtable->size);
    addHead(hashtable->entries[index],entry);
}

Entry searchHash(HashTable hashtable, Key key) {
    int index=hashValue(key,hashtable->size);
    Entry entry=newEntry(key,NULL);
    int n;
    return searchListItem(hashtable->entries[index],entry, &n);
}

Entry deleteHash(HashTable hashtable, Key key) {
    int index=hashValue(key,hashtable->size);
    Entry entry=newEntry(key,NULL);
    int n;
    return removeListItem(hashtable->entries[index],entry);
}

void printHash(HashTable hashtable) {
    for(int i=0;i<hashtable->size;i++) printList(hashtable->entries[i]);
}