#include "piatto.h"
typedef struct menu *Menu;
Menu newMenu();
void addPiatto(Menu menu, Piatto piatto);
void removePiatto(Menu menu, Piatto piatto);
void sortForPrezzo(Menu menu);
void sortForNome(Menu menu);
void printMenu(Menu menu);