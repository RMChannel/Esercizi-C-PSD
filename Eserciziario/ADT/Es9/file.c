#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"

struct file{
    char *nome;
    char *estensione;
    float dimensione;
};

File newFile(char *name, char *extension, float dim) {
    File file=malloc(sizeof(struct file));
    file->dimensione=dim;
    char *n=malloc(sizeof(name));
    strcpy(n,name);
    file->nome=n;
    char *e=malloc(sizeof(extension));
    strcpy(e,extension);
    file->estensione=e;
    return file;
}

int controlName(File f1, File f2) {
    return strcmp(f1->nome,f2->nome);
}

int controlExtension(File f1, File f2) {
    return strcmp(f1->estensione,f2->estensione);
}

void printFile(File f) {
    printf("File: %s.%s\nDimensione: %.2fmb\n",f->nome,f->estensione,f->dimensione);
}