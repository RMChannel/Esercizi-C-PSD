#include <stdio.h>
#include <stdlib.h>
#include "piatto.h"
#include "menu.h"

int main() {
    Menu menu=newMenu();
    Piatto p1=newPiatto("Polpette",3.5,"Carne macinata e sugo");
    Piatto p2=newPiatto("Gatto\'",20,"Patate, latte, provoletta, prosciutto, salame, pan grattato");
    Piatto p3=newPiatto("Spaghetti all'arrabbiata",13,"Spaghetti, pepe, sugo al pomodoro");
    addPiatto(menu,p1);
    addPiatto(menu,p2);
    addPiatto(menu,p3);
    editPiatto(p2,"",30,"");
    sortForNome(menu);
    printMenu(menu);
    printf("\n\n");
    sortForPrezzo(menu);
    printMenu(menu);
    printf("\n\n");
    removePiatto(menu,p2);
    printMenu(menu);
}