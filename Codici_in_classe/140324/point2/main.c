#include <stdio.h>
#include "point2.h"

int main(int argc, char *argv[]) {
    float x1,y1,x2,y2;
    printf("Inserisci le coordinate del 1°punto: ");
    scanf("%f %f",&x1,&y1);
    printf("Inserisci le coordinate del 2°punto: ");
    scanf("%f %f",&x2,&y2);
    Punto p1=creaPunto(x1,y1);
    Punto p2=creaPunto(x2,y2);
    printf("%.1f\n",distanza(p1,p2));
    return 0;
}