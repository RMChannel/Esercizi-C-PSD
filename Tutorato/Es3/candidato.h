typedef struct candidato *Candidato;

Candidato initCandidato(char* name, char* surname, int punteggio);
char* name(Candidato);
char* surname(Candidato);
int score(Candidato);
void swapCandidato(Candidato , Candidato);