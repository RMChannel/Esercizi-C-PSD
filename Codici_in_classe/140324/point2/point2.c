#include <math.h>
#include <stdlib.h>
#include "point2.h"

struct Punto{
    float x;
    float y;
};

Punto creaPunto(float x, float y) {
    Punto p=malloc(sizeof(struct Punto));
    p->x=x;
    p->y=y;
    return p;
}

float ascissa(Punto p) {
    return p->x;
}

float ordinata(Punto p) {
    return p->y;
}

float distanza(Punto p1, Punto p2) {
    float dx=p1->x-p2->x;
    float dy=p1->y-p2->y;
    dx*=dx;
    dy*=dy;
    return (sqrt((dx+dy)));
}