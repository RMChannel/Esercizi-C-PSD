#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "libro.h"
#include "libreria.h"

int main(int argc, char *argv[]) {
    Libro libro1=createItem("Dio","Madre","Bastardo",2012);
    Libro libro2=createItem("Leqso","Porco","Daniele",2016);
    Libro libro3=createItem("Simone","Ambiente","Ariel Immigrato",2024);
    Libreria libreria=newLibreria();
    addLibro(libro1,libreria);
    addLibro(libro2,libreria);
    addLibro(libro3,libreria);
    outputLibreria(libreria);
    printf("\n");
     ordinaLibreria(libreria);
    outputLibreria(libreria);
}