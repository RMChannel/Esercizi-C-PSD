#include <stdio.h>
#include <stdlib.h>

/*Questa funzione ha complessità O(n)
Esssa si occupa della stampa in reverse della stringa e anche del conto dei caratteri.
Prende in input il puntatore alla stringa, il puntatore al carattere finale della stringa e una variabile n (che rappresenta il conto dei caratteri)
*/
void realPrintReverseAndCount(char *s, char *si, int n) {
    printf("%c",*s); //Stapo il carattere
    if(s!=si) { //Se non mi trovo al 1° carattere
        realPrintReverseAndCount((s-1),si,n+1); //Allora richiamo la funzione con una posizione indietro e col conto dei caratteri aumentato di 1
    }
    else { //Se mi trovo al 1°carattere, allora stampo il numero di caratteri, che sarà l'n calcolato fino a quel punto +1 (contando l'ultimo carattere stampato in quel momento)
        printf(" %d\n",n+1);
        return;
    }
}
//Questa funzione ha complessità O(n)
void printReverse(char *s) { //Questa funzione si occupa solo del richiamo alla funzione effettiva di stampa
    char *sFinal=s;
    while(*sFinal) sFinal++; //Mi creo un puntatore che punta al carattere finale della stringa
    sFinal--; //Sottraggo di 1, perché alla fine del ciclo la stringa si troverà sul carattere '\0', però ho bisogno di trovarmi sull'ultimo carattere, quindi torno indietro di una posizione
    realPrintReverseAndCount(sFinal,s,0); //Richiamo la funzione di stampa
}

int main() {
    char s[200]; //Dichiaro la stringa dove andrò a salvare la parola su cui lavorare
    printf("Inserisci una parola: ");
    scanf("%s",s); //Faccio inserire la parola all'utente
    printReverse(s); //Richiamo alla funzione
}

//Non ho usato alcun tipo di struttura perché sfruttando i puntatori sono riuscito a gestire tutto direttamente sulla stringa stessa.