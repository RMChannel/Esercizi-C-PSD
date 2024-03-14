#include <math.h>
#include "point1.h"

Punto creaPunto(float x, float y) {
    Punto p={x,y};
    return p;
}

float ascissa(Punto p) {
    return p.x;
}

float ordinata(Punto p) {
    return p.y;
}

float distanza(Punto p1, Punto p2) {
    float dx=p1.x-p2.x;
    float dy=p1.y-p2.y;
    dx*=dx;
    dy*=dy;
    return (sqrt((dx+dy)));
}