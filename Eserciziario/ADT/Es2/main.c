#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"
#include "libro.h"

int main() {
    Libro l1=createLibro("Bibbia","Gesu' Cristo","Religione",0);
    Libro l2=createLibro("Five Night's At Freddy's","Scott Cawton","Horror",2014);
    Libro l3=createLibro("Ciccio Gamer's Bible","Ciccio Gamer","Divino",2020);
    Libreria lib=createLibreria();
    addLibro(lib,l1);
    addLibro(lib,l2);
    addLibro(lib,l3);
    printLibreria(lib);
    if(searchForTitle(lib,"Bibbia")) printf("Bibbia trovato\n");
    if(!searchForTitle(lib,"Piiiparaparapo")) printf("Non trovato\n");
    if(searchForAuthor(lib,"Ciccio Gamer")) printf("Ciccio Gamer trovato\n");
    if(!searchForAuthor(lib,"Piiiparaparapo")) printf("Non trovato\n");
}