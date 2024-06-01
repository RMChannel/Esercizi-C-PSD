#include <stdio.h>
#include "file.h"
#include "folder.h"

int main() {
    Folder folder=newFolder();
    File f1=newFile("GTAV","exe",3.5);
    File f2=newFile("Relazione","docx",2.3);
    File f3=newFile("EstrattoConto","pdf",5);
    File f4=newFile("Presentazione","pptx",20.3);
    addFile(folder,f1);
    addFile(folder,f2);
    addFile(folder,f3);
    addFile(folder,f4);
    removeFile(folder,f2);
    printFolder(folder);
    printf("\n\n");
    sortForName(folder);
    printFolder(folder);
    printf("\n\n");
    sortForExtension(folder);
    printFolder(folder);
    if(searchForName(folder,"GTAV")!=NULL) printf("GTAV trovato\n");
    if(searchForName(folder,"iPhone")==NULL) printf("iPhone non trovato\n");
    if(searchForExtension(folder,"exe")!=NULL) printf("exe trovato\n");
    if(searchForExtension(folder,"mp3")==NULL) printf("mp3 non trovato\n");
}