#include <stdio.h>
#include "point.h"

int main(int argc, char *argv[]) {
    float x,y,deltax,deltay;
    printf("Inserisci la x: ");
    scanf("%f",&x);
    printf("Inserisci la y: ");
    scanf("%f",&y);
    Punto p=creaPunto(x,y);
    printf("Inserisci DeltaX: ");
    scanf("%f",&deltax);
    printf("Inserisci DeltaY: ");
    scanf("%f",&deltay);
    MovePunto(p,deltax,deltay);
    printf("%.1f %.1f\n", ascissa(p), ordinata(p));
}