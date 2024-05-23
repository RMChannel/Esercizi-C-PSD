#include <stdio.h>
#include "hashtable.h"
#include "list.h" 
#include "item.h"
#include "entry.h"
#include "key.h"
#define SIZE 5

int main(){
	HashTable ht=newHashtable(SIZE);
    for(int i=0;i<SIZE;i++) {
        printf("Inserisci la %d chiave: ",i+1);
        Key k=inputKey();
        printf("Inserisci il %d item: ",i+1);
        Item item=inputItem();
        Entry entry=newEntry(k,item);
        insertHash(ht,entry);
    }
    printf("Inserisci una chiave da ricercare: ");
    Key k=inputKey();
    Entry entry=searchHash(ht,k);
    if (entry) outputItem(getValue(entry));
}