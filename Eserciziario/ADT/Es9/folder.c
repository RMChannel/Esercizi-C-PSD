#include <stdio.h>
#include <stdlib.h>
#include "folder.h"
#include "file.h"
#define N 100

struct folder{
    File files[N];
    int size;
};

Folder newFolder() {
    Folder folder=malloc(sizeof(struct folder));
    folder->size=0;
    return folder;
}

void addFile(Folder folder, File file) {
    if(folder->size==N) return;
    folder->files[folder->size]=file;
    folder->size++;
}

void removeFile(Folder folder, File file) {
    for(int i=0;i<folder->size;i++) {
        if(file==folder->files[i]) {
            for(;i<folder->size;i++) folder->files[i]=folder->files[i+1];
            folder->size--;
            return;
        }
    }
    printf("File non trovato\n");
}

void printFolder(Folder folder) {
    for (int i=0;i<folder->size;i++) printFile(folder->files[i]);
}

void sortForName(Folder folder) {
    File temp;
    for(int i=0;i<folder->size;i++) {
        for(int j=i;j<(folder->size)-1;j++) {
            if(controlName(folder->files[j],folder->files[j+1])>0) {
                temp=folder->files[j];
                folder->files[j]=folder->files[j+1];
                folder->files[j+1]=temp;
            }
        }
    }
}

void sortForExtension(Folder folder) {
    File temp;
    for(int i=0;i<folder->size;i++) {
        for(int j=i;j<(folder->size)-1;j++) {
            if(controlExtension(folder->files[j],folder->files[j+1])>0) {
                temp=folder->files[j];
                folder->files[j]=folder->files[j+1];
                folder->files[j+1]=temp;
            }
        }
    }
}

File searchForName(Folder folder, char *name) {
    File temp=newFile(name,"",0);
    for(int i=0;i<folder->size;i++) {
        if(controlName(folder->files[i],temp)==0) return folder->files[i];
    }
    return NULL;
}

File searchForExtension(Folder folder, char *ext) {
    File temp=newFile("",ext,0);
    for(int i=0;i<folder->size;i++) {
        if(controlExtension(folder->files[i],temp)==0) return folder->files[i];
    }
    return NULL;
}