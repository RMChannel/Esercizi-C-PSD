#include <stdlib.h>
#include "auto.h"

struct Auto {
    char *targa;
    int annoI;
    int annoP;
    char *modello;
};

Auto initAuto(char *targa, int annoI, int annoP, char *modello) {
    Auto car=malloc(sizeof(struct Auto));
    car->annoI=annoI;
    car->annoP=annoP;
    car->targa=targa;
    car->modello=modello;
    return car;
}

char *targa(Auto car) {
    return car->targa;
}

char *modello(Auto car) {
    return car->modello;
}

int annoI(Auto car) {
    return car->annoI;
}

int annoP(Auto car) {
    return car->annoP;
}