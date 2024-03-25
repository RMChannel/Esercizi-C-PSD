#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "point.h"

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

/*
Crea un punto data le coordinate

creaPunto(reale, reale) -> punto

Pre-condizione: true
Post-condizione: p=(x,y)
*/


float ascissa(Punto p) {
    return p->x;
}

/*
Ritorna l'ascissa di un punto dato

ascissa(punto)->reale

Pre-condizione: true
Post-condizione: p=(x,y)
*/

float ordinata(Punto p) {
    return p->y;
}

/*
Ritorna l'ordinata di un punto dato

ordinata(punto)->reale

Pre-condizione: true
Post-condizione: p=(x,y)
*/

float distanza(Punto p1, Punto p2) {
    float dx=p1->x-p2->x;
    float dy=p1->y-p2->y;
    dx*=dx;
    dy*=dy;
    return (sqrt((dx+dy)));
}

/*
Restituisce il valore della distanza tra due punti dati

distanza(punto,punto)->reale

Pre-condizione: true
Post-condizione: d = sqrt((ascissa(p1)-ascissa(p2))^2 + (ordinata(p1)-ordinata(p2))^2)
*/

void MovePunto(Punto p, float deltax, float deltay) {
    p->x+=deltax;
    p->y+=deltay;
}

/*
Dato un punto p e due valori deltax e deltay, la funzione sposta il punto di deltax e deltay

MovePunto(punto,reale,reale)->void

Pre-condizione: true
Post-condizioni:
p->x= p->x+deltax
p->y= p->y+deltay
*/

Punto Centroide(Punto pAll[],int npunti) {
    float xAll=0, yAll=0;
    for (int i=0;i<npunti;i++) {
        xAll+=ascissa(pAll[i]);
        yAll+=ordinata(pAll[i]); //faccio la somma di tutte le ascisse e ordinate dei punti
    }
    xAll/=npunti;
    yAll/=npunti; //calcolo la media
    return creaPunto(xAll,yAll);; //creo il punto Cetroide
}

/*
Calcola il punto centrale di coordinate uguali alle medie delle ascisse e delle ordinate dei punti dati

Centroide(array di punti, intero) -> punto

Pre-condizione: inpAll c'è almeno un punto
Post-condizione: p=((media delle ascisse),(media delle ordinate))
*/

int Coppie(Punto pAll[],int npunti, float d) {
    int n=0;
    for (int i=0;i<npunti;i++) {
        for (int i2=i+1;i2<npunti;i2++) { //con i 2 for mi prendo solamente le uniche coppie possibili
            printf("%d %d\n",i,i2);
            if (distanza(pAll[i],pAll[i2])<d) n++;
        }
    }
    return n;
}

/*
Dato un array di punti e una distanza d, la funzione si occupa di contare tutte le distanze (fra le coppie di punti possibili) minori a quella di d

Coppie(array di punti, ntero, reale) -> intero

Pre-condizione: Nell'array di punti ci sono almeno 2 punti
Post-condizione: n=numero di coppie di punti con distanza minore a d
*/

float MaxDist(Punto pAll[], int npunti) {
    float d=0;
    for (int i=0;i<npunti;i++) {
        for (int i2=i;i2<npunti;i2++) {
            if (distanza(pAll[i],pAll[i2])>d && i!=i2) d=distanza(pAll[i],pAll[i2]);
        }
    }
    return d;
}

/*
MaxDist(array di punti, ntero) -> reale

Pre-condizione: Nell'array di punti ci sono almeno 2 punti
Post-condizione: d=Distanza massima fra le coppie di punti date
*/