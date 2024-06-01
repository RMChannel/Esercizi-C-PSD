typedef struct contatto *Contatto;

Contatto createContatto(char *name, char *surname, char *phone, char *mail);
int cmpName(Contatto c1, Contatto c2);
int cmpTel(Contatto c1, Contatto c2);
Contatto editContatto(char *name, char *surname, char *phone, char *mail, Contatto c);
void outputContatto(Contatto c);