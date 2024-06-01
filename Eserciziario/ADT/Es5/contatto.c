#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contatto.h"

struct contatto{
    char *nome;
    char *cognome;
    char *tel;
    char *email;
};

Contatto createContatto(char *name, char *surname, char *phone, char *mail) {
    Contatto contatto=malloc(sizeof(struct contatto));
    char *n=malloc(sizeof(name));
    char *c=malloc(sizeof(surname));
    char *t=malloc(sizeof(phone));
    char *e=malloc(sizeof(mail));
    strcpy(n,name);
    strcpy(c,surname);
    strcpy(t,phone);
    strcpy(e,mail);
    contatto->nome=n;
    contatto->cognome=c;
    contatto->tel=t;
    contatto->email=e;
    return contatto;
}

int cmpName(Contatto c1, Contatto c2) {
    return strcmp(c1->nome,c2->nome)==0;
}

int cmpTel(Contatto c1, Contatto c2) {
    return strcmp(c1->tel,c2->tel)==0;
}

Contatto editContatto(char *name, char *surname, char *phone, char *mail, Contatto c) {
    if(name!=NULL) {
        char *n=malloc(sizeof(name));
        strcpy(n,name);
        c->nome=n;
    }
    if(surname!=NULL) {
        char *n=malloc(sizeof(surname));
        strcpy(n,name);
        c->cognome=n;
    }
    if(phone!=NULL) {
        char *n=malloc(sizeof(phone));
        strcpy(n,phone);
        c->tel=n;
    }
    if(mail!=NULL) {
        char *n=malloc(sizeof(mail));
        strcpy(n,mail);
        c->email=n;
    }
    return c;
}

void outputContatto(Contatto c) {
    printf("Nome: %s Cognome: %s Numero di telefono: %s E-Mail: %s\n",c->nome,c->cognome,c->tel,c->email);
}