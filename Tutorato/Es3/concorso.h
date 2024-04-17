#include "candidato.h"

typedef struct concorso *Concorso;

Concorso createConcorso(char* name);
void addCandidato(Concorso, Candidato);
void removeCandidato(Concorso, char*);
void printConcorso(Concorso);
void removeSeventy(Concorso);
void ordinaConcorso(Concorso);