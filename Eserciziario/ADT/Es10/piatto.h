typedef struct piatto *Piatto;
Piatto newPiatto(char *nome, float prezzo, char *ingredienti);
void editPiatto(Piatto piatto, char *nome, float prezzo, char *ingredienti);
int search(Piatto p1, Piatto p2, int n);
void outputPiatto(Piatto p);