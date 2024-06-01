#include "item.h"

typedef struct spesa *Spesa;
Spesa newSpesa();
void addItem(Spesa spesa, Item item);
Item removeItem(Spesa spesa, Item item);
float calcolaSpesa(Spesa spesa);
void outputSpesa(Spesa spesa);