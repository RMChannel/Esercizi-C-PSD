#include <stdio.h>
#include <stdlib.h>

void outputArray(int *a, int n) { //Funzione di stampa dell'array
	int i;
	for(i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}

void merge(int a1[], int a2[],int n1, int n2, int a[]) {
	int i,j,k, copia[n1+n2]; //Ci creiamo 3 contatori, insieme ad un array di dimensione uguale alla somma delle dimensioni degli array passati
	for(i=0,j=0,k=0;i<n1 && j<n2;k++) { //Scorriamo l'array copia, così da salvare in modo ordinato gli elementi degli array passati
		if (a1[i]<=a2[j]) { //Se l'elemento del 1°array è minore o uguale a quello del 2°, allora copia il 1° e scorro avanti
			copia[k]=a1[i];
			i++;
		}
		else { //In caso contrario, prendo l'elemento del 2°array
			copia[k]=a2[j];
			j++;
		}
	}
	for(;i<n1;i++,k++) copia[k]=a1[i]; //Dopo aver preso tutti gli elementi dal ciclo di prima, potrebbe accadere che uno degli array abbia elementi in più rispetto all'altro
	for(;j<n2;j++,k++) copia[k]=a2[j]; //E per risolvere il problema, facciamo una copia di tutti gli elementi rimanenti nell'array copia
	for(k=0;k<(n1+n2);k++) { //Poi, ricordiamo che noi passiamo alla funzione anche un array a (dove viene salvato l'array formato dall'insieme degli altri 2)
		a[k]=copia[k]; //Allora copiamo in a l'array copia
	}
}

void mergeSortIterativo2(int *a, int n) {
    for(int dim=1;dim<n;dim*=2) {
        printf("Dim %d:\n",dim);
        for(int n1=0,n3=dim;n3<n;n1+=(dim*2),n3+=(dim*2)) {
            int n2=n1+dim-1;
            int n4=n3+dim-1;
            if (n4>=n) n4=n-1;
            printf("merge di %d - %d e %d - %d\n",a[n1],a[n2],a[n3],a[n4]);
        }
    }
}


/*
Questa funzione divide l'array originale in tutti sottoarray (partendo da dimensione 1, poi di dimensione sempre doppia (2,4,8,16,....)) e lo ordina
tramite la funzione merge.
*/
void mergeSortIterativo(int *a, int n) {
    for(int dim=1;dim<n;dim*=2) { //Mi creo la variabile dimensione per gestirmi le dimensioni dei sottoarray
        for(int n1=0,n3=dim;n3<n;n1+=(dim*2),n3+=(dim*2)) { //Inizializzo n1 a 0 e n3 a dim (visto che deve partire dall'elemento che corrisponde alla dimensione), poi ad ogni ciclo incremento n1 ed n3 del doppio della dimensione
            int n2=n1+dim-1; //n2 è uguale ad n1 + la dimnesione -1, perché questo rappresenta la fine del 1°sottoarray
            int n4=n3+dim-1; //Stessa cosa per il 2°array con n4
            if (n4>=n) n4=n-1; //Nel caso in cui n4 superi il limite dell'array, allora ripristino n4 all'ultimo ellemento degli array
            merge(a+n1,a+n3,n3-n1,n4-n2,a+n1); //Infine faccio il merge dei sottoarray e passo come dimensioni la differenza tra i puntatori opposti (n3 ed n1 | n4 ed n2)
        }
    }
}

int main() {
    int a[]={6,3,1,4,5,2,0,7}; //Mi creo l'array
    mergeSortIterativo(a,8); //Ordino l'array col mergeSort
    outputArray(a,8); //Stampo
}