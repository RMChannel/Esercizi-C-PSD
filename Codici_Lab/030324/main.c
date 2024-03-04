#include <stdio.h>
#include "vettore.h"
#define MAXELEM 100

int main(int argc, char *argv[]) {
    int scelta=1;
    int elements=0;
    int n[100]={0};
    int temp;
    while (1) {
        printf("Scegli un'opzione:\n[1]Inserisci elementi nell'array\n[2]Stampa tutti gli elementi dell'array\n[3]Ricerca un elemento nell'array\n[4]Trova il minimo nell'array\n[5]Ordina l'array\n[6]Elimina un elemento dell'array\n[7]Aggiungi un singolo elemento\n[altro]Esci\n");
        scanf("%d",&scelta);
        switch(scelta) {
            case 1:
                printf("Inserite il numero di elementi da aggiungere: ");
                scanf("%d",&temp);
                elements+=temp;
                input_array(n,temp);
                break;
            case 2:
                output_array(n,elements);
                break;
            case 3:
                printf("Inserite un elemento intero da cercare: ");
                scanf("%d",&temp);
                ricerca_array(n,temp,elements);
                break;
            case 4:
                printf("Il minimo è %d\n",n[min_array(n,elements)]);
                break;
            case 5:
                ordinaArray(n,elements);
                printf("Ordinamento eseguito\n");
                break;
            case 6:
                printf("Inserisci l'elemento da eliminare: ");
                scanf("%d",&temp);
                delElemArray(n,elements,temp);
                elements--;
                break;
            case 7:
                input_array(n,1);
                elements++;
                break;
            default:
                return 0;
        }
    }
}