#include <stdio.h>
#include <stdlib.h>
#include "rubrica.h"
#include "contatto.h"

int main() {
    Rubrica r=newRubrica();
    Contatto c1=createContatto("Roberto","Cito","34710304385","robbencito@gmail.com");
    Contatto c2=createContatto("Salvatore","Cito","3349764705","cito719@gmail.com");
    Contatto c3=createContatto("Mariarosaria","Cianelli","3205397560","cianellirosaria@gmail.com");
    addRubrica(r,c1);
    addRubrica(r,c2);
    addRubrica(r,c3);
    printRubrica(r);
    free(r);
    free(c1);
    free(c2);
    free(c3);
    return 0;
}