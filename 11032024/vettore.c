
#include <stdio.h>

//creo la funzione che prende in input la stringa dal file input_file.txt
//input_array_str prende una stringa di caratteri e la trasforma in un array di interi (es)
int input_array_str(int *arr, char *line, int *pos){
    int i = 0, n = 0;
    //*pos = 0;
    while(sscanf(line,"%d%n",&arr[i],&n)==1){//%n = numero di caratteri (es: 1 2 , dove ' ' è lo spazio, mi darà n=3)
        printf("numero letto : %d\ncaratteri letti: %d\n", arr[i], n);//printf di controllo
    line+=n; //serve a scorrere la stringa
    i++;//fa scorrere l'array
    
    }
    //*pos=counter +1;
return i;//i è la dimensione dell'array
}


//funzione che somma gli elementi presi in input e restituisce il totale
int sum_array(int a[], int n){//prende in input l'array e il numero di elementi utile per il ciclo
    int i=0; //variabile cotatore
    int summ=0; //variabile temporanea dove mettere la somma
    //ciclo for che scorre l'array e fa la somma dei suoi elementi
    for(; i<n; i++){
        summ += a[i];
    }

return summ;

}


//funzione getresult
//prende la linea di oracle, dichiara un intero, fa una scanf della riga e ritorna l'intero preso
int getresult(char *line){
    int n;
    sscanf(line, "%d", &n);
    return n;
}

//funzione che prende i due array e li somma posizione per posizione
void sum_2array(int *arr1, int *arr2, int *imax1, int *imax2){// *c mi serve per poi riportare nel main l'array somma di a e b
    
    //noi dobbiamo supporre che nel caso peggiore le due stringhe hanno dimenensione diverse, ma sappiamo che in oracle la dimensione dell'array sarà uguale a quella dell'array + grande perchè deriva da una somma
    /*noi abbiamo 3 casi da coprire 
    imax1=imax2
    imax1<imax2
    imax1>imax2
    con questo if copriamo tutti e 3 i casi
    perchè  -se considero il caso in cui sono uguali sono apposto
            -se considero il caso in cui imax1>imax2 sono coperto perchè imax1 comprende tutti gli elementi di imax2
            -il problema sussiste quando considero il caso imax1<imax2 perchè se no non considererei gli elementi in più di imax2 perchè guarderei solo le dimensioni del primo array
             con questo if di controllo uguaglio le dimensioni delle 2 righe 
    */
    if(*imax1<*imax2) *imax1=*imax2;

    //creo un for che somma tutti gli elementi che verranno salvati in arr1 (quindi arr1 verrà sovrascritto con l'array somma)
    for (int i=0; (i<*imax1); i++){
        arr1[i]=arr1[i]+arr2[i];
    }
}


//funzione di controllo per driver2 diversa da quella di driver1 perchè devo controllare un intero array
int controlloOracleArray(int *arr, int *oracle, int imax){
    for(int i=0; i<imax; i++){
        if(arr[i] != oracle[i])//controlla l'uguaglianza tra input e oracle, imax non lo controllo perchè so di sicuro che ha le dimensioni dell'array più grande
        return 0; //sono diversi
    return 1; //sono uguali   
    }
}

int sum_prod(int *arr1, int *arr2, int *imax1, int *imax2){
    int a = 0;
    if(*imax1<*imax2) *imax1=*imax2;
    for (int i=0; (i<*imax1); i++){
        arr1[i]=arr1[i]*arr2[i];
    }
    for (int i = 0; i < *imax1; i++)a = a+arr1[i];
    return a;
}

void outputArray(int *a, int n) {
    for (int i=0;i<n;i++) printf("%d ",a[i]);
}