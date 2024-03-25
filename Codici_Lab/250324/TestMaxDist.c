#include <stdio.h>
#include <stdlib.h>
#include "point.h"

int main(int argc, char *argv[]) {
    int n;
    float x,y;
    printf("Quanti punti vuoi inserire?\n");
    scanf("%d",&n);
    Punto *pAll=malloc(sizeof(Punto)*n);
    for (int i=0;i<n;i++) {
        printf("Inserisci le coordinate del %d°punto: ",i+1);
        scanf("%f %f",&x,&y);
        pAll[i]=creaPunto(x,y);
    }
    printf("%.1f\n",MaxDist(pAll,n));
}