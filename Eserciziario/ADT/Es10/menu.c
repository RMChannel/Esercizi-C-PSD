#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "piatto.h"
#define N 100

struct menu{
    Piatto piatti[100];
    int size;
};

Menu newMenu() {
    Menu menu=malloc(sizeof(struct menu));
    menu->size=0;
    return menu;
}

void addPiatto(Menu menu, Piatto piatto) {
    if(menu->size==N) return;
    else {
        menu->piatti[menu->size]=piatto;
        menu->size++;
    }
}

void removePiatto(Menu menu, Piatto piatto) {
    for(int i=0;i<menu->size;i++) {
        if(menu->piatti[i]==piatto) {
            for(;i<menu->size;i++) {
                menu->piatti[i]=menu->piatti[i+1];
            }
            menu->size--;
            return;
        }
    }
}

void sortForPrezzo(Menu menu) {
    for(int i=0;i<menu->size;i++) {
        for(int j=i;j<(menu->size-1);j++) {
            if(search(menu->piatti[j],menu->piatti[j+1],1)) {
                Piatto temp=menu->piatti[j];
                menu->piatti[j]=menu->piatti[j+1];
                menu->piatti[j+1]=temp;
            }
        }
    }
}

void sortForNome(Menu menu) {
    for(int i=0;i<menu->size;i++) {
        for(int j=i;j<(menu->size-1);j++) {
            if(search(menu->piatti[j],menu->piatti[j+1],2)) {
                Piatto temp=menu->piatti[j];
                menu->piatti[j]=menu->piatti[j+1];
                menu->piatti[j+1]=temp;
            }
        }
    }
}

void printMenu(Menu menu) {
    for(int i=0;i<menu->size;i++) {
        outputPiatto(menu->piatti[i]);
    }
}