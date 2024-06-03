#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "piatto.h"

Item inputItem(char *p, int n) {
    return newPiatto(p,n);
}

void outputItem(Item i) {
    outputPiatto(i);
}