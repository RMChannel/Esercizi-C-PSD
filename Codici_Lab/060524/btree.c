#include <stdlib.h>
#include "btree.h"
#include "item.h"
#include "queue.h"
#include "stack.h"
#include "list.h"

struct node{
  Item value;
  struct node* left;
  struct node* right;
};

BTree newTree(){
  return NULL;
}

int isEmptyTree(BTree tree){
  if(tree==NULL)
    return 1;
  else
    return 0;
}

BTree buildTree(BTree left, BTree right, Item i){
  BTree tree=malloc(sizeof(struct node));
  tree->left=left;
  tree->right=right;
  tree->value=i;
  return tree;
}

Item getBTreeRoot(BTree tree){
  if(isEmptyTree(tree))
    return NULL;
  else
    return tree->value;
}

BTree getLeft(BTree tree){
  if(isEmptyTree(tree))
    return NULL;
  else
    return tree->left;
}

BTree getRight(BTree tree){
  if(isEmptyTree(tree))
    return NULL;
  else
    return tree->right;
}

void preOrder(BTree tree){
  if(!isEmptyTree(tree)){
    outputItem(tree->value);
    preOrder(tree->left);
    preOrder(tree->right);
  }
}

void postOrder(BTree tree){
  if(!isEmptyTree(tree)){
    postOrder(tree->left);
    postOrder(tree->right);
    outputItem(tree->value);
  }
}

void inOrder(BTree tree){
  if(!isEmptyTree(tree)){
    inOrder(tree->left);
    outputItem(tree->value);
    inOrder(tree->right);
  }
}

/*
Questa funzione si occupa del calcolo del numero di nodi
Prende in input il ramo iniziale e una variabile n (passata per indirizzo)
dove verrà salvato il numero di nodi
*/
void nNodi(BTree tree, int *n) { 
  if(!isEmptyTree(tree)){ //Finché tutti i rami richiamati risultano vuoti
    (*n)++; //Incremento n
    nNodi(tree->left,n); //Controllo il suo ramo sinistro
    nNodi(tree->right,n); //Poi quello destro
  }
}

/*
Questa funzione fa da richiamo a quella per il calcolo del numero di nodi
*/
int numberOfNodi(BTree tree) {
  int n=0; //Si crea una variabile n, inizializzata a 0, dove verrà salvato il numero di nodi
  nNodi(tree,&n); //Richiamo alla funzione
  return n; //Restituisco il valore al chiamante
}


/*
Questa funzione si occupa di calcolare l'altezza di un albero
Prende in input due rami, (uno sinistro e uno destro) e una variabile n
dove verrà salata l'altezza dell'albero dato
*/
void searchHeight(BTree treeL, BTree treeR, int *n) {
  if(!isEmptyTree(treeL) || !isEmptyTree(treeR)) { //Finché tutti e due i rami non sono vuoti
    (*n)++; //Incrementa n ad ogni richiamo
    if (!isEmptyTree(treeL)) {
      searchHeight(treeL->left,treeL->right,n); //Nel caso in cui il ramo sinistro esiste, allora esiste un altro piano a sinistra
    }
    if (!isEmptyTree(treeR)) {
      searchHeight(treeR->left,treeR->right,n); //Nel caso in cui il ramo destro esiste, allora esiste un altro piano a destra
    }
  } //Continuo così finché non arrivo alla fine dell'albero e trovo sicuramente il percorso più lungo esistente
}

/*
Questa funzione fa da richiamo a quella per il calcolo dell'altezza
*/
int Height(BTree tree) {
  int n=-1; //Viene inizializzata una variabile a -1, questo perché qui verrà salvata l'altezza dell'albero dato e viene inizializzata a -1 perché dobbiamo saltare il primo ramo (quello iniziale)
  searchHeight(tree->left,tree->right,&n); //Richiamo alla funzione, dove vengono passati il ramo sinistro e il ramo destro
  return n; //Viene restituita l'altezza calcolata
}

/*
Questa funzione si occupa della stampa dell'albero a livello (in modo iterativo), ovvero viene stampato un livello alla volta
Prende in input solo l'albero
*/
void printLevel(BTree tree) {
  Queue queue=newQueue(); //Ci creiamo una coda
  enqueue(queue,tree); //Aggiungiamo il ramo iniziale
  while(!isEmptyQueue(queue)) { //Finché la coda non è vuota
    BTree temp=dequeue(queue); //Ci prendiamo il 1°elemento della coda
    if(!isEmptyTree(temp->left)) enqueue(queue,temp->left); //Nel caso in cui esistano elementi a sinistra, li aggiungiamo
    if(!isEmptyTree(temp->right)) enqueue(queue,temp->right); //Stessa cosa a destra
    outputItem(temp->value); //E alla fine viene stampato tutto
  } //Questo ciclo viene ripetuto finchè non vengono stampati tutti gli elementi pian piano inseriti nella coda
  free(queue); //Infine liberiamo la memoria della coda, visto che non è più necessaria
}

/*
Questa funzione si occupa della stampa dell'albero in pre-ordine (in modo iterativo),
prende in input solo l'albero
*/
void preOrderIterative(BTree tree) {
  Stack stack=newStack(); //Ci creiamo uno stack di appoggio
  do {
    if(isEmptyTree(tree->left)) { //Se il ramo a sinistra è vuoto
      outputItem(tree->value); //Stampiamo il ramo preso in esame
      tree=top(stack); //E ci prendiamo quello nello stack
      pop(stack); //Lo eliminiamo dallo stack
    }
    outputItem(tree->value); //Stampiamo il ramo
    if(!isEmptyTree(tree->right)) { //Nel caso in cui abbia un ramo a destra
      push(stack,tree->right); //Allora lo salviamo nello stack
      tree=tree->left; //E passiamo a quello a sinistra
    }
    else if (!isEmptyStack(stack)) { //Se lo stack non è vuoto
      tree=top(stack); //Allora prendiamo l'ultimo elemento salvato
      pop(stack); //Lo eliminiamo dallo stack
      outputItem(tree->value); //Stampiamo l'elemento che abbiamo preso
      if(!isEmptyTree(tree->right)) { //Nel caso in cui esista un elemento a destra
        push(stack,tree->right); //Lo salviamo nello stack
        tree=tree->left; //E passiamo a quello a sinistra
      }
    }
  } while(!isEmptyStack(stack)); //Finché lo stack non è vuoto, continuiamo il ciclo
  free(stack); //Infine liberiamo la memoria dello stack, visto che non è più necessario
}

/*
Questa funzione si occupa della stampa dell'albero in post-ordine (in modo iterativo),
prende in input solo l'albero
*/
void postOrderIterative(BTree tree) {
  Stack stack=newStack(); //Ci creiamo uno stack di appoggio
  int n=0, control=1; //n è solo una variabile di appoggio per la searchListItem, non ha uso, invece control sarà una variabile di controllo che verrà spiegata dopo
  List list=newList(); //Ci creiamo, anche, una lista di appoggio
  do {
    if (control) { //Se control è vero, allora ci salviamo il ramo nello stack
      push(stack,tree);
    }
    if (!isEmptyTree(tree->left) && searchListItem(list,tree->left->value,&n)==NULL) { //Nel caso in cui il ramo sinistro esista e che non sia salvato nella lista, allora andiamo su quel ramo
      tree=tree->left;
    }
    else { //In caso contrario
      control=1; //Impostiamo control ad 1
      if (searchListItem(list,tree->value,&n)!=NULL) { //Se l'elemento preso dal ramo già esiste nella lista
        pop(stack); //Allora eliminiamo l'ultimo elemento dallo stack
        tree=top(stack); //C'è lo prendiamo
        addHead(list,tree->value); //Aggiungiamo quell'elemento alla lista
        if (!isEmptyTree(tree->right) && searchListItem(list,tree->right->value,&n)==NULL) { //E nel caso in cui abbia un ramo destro e che non sia salvato nella lista
          tree=tree->right; //Allora andiamo sul ramo destro
          control=1; //E impostiamo control
        }
        else { //In caso contrario, allora stampiamo 
          outputItem(tree->value);
          control=0; //Impostiamo control a 0
          if (searchListItem(list,tree->right->value,&n)!=NULL && searchListItem(list,tree->left->value,&n)!=NULL && nStack(stack)==1) break; //E controlliamo che ci troviamo al ramo iniziale, dove tutti e due gli elementi (sinistro e destro) sono nella lista e che il numero di elementi dello Stack sia uguale a 1, se tutte le condizioni sono vere allora terminiamo il programma
        }
      }
      else { //In caso contrario, allora stampiamo
        outputItem(tree->value);
        addHead(list,tree->value); //Aggiungiamo l'elemento alla lista
        pop(stack); 
        tree=top(stack); //Prendiamo l'ultimo elemento dallo stack
        if (!isEmptyTree(tree->right)) tree=tree->right; //Nel caso in cui abbia un ramo a destra, andiamo su quel ramo
      }
    }
  } while(1); //Il ciclo non ha condizione perché la condizione di terminazione non è alla fine del ciclo, ma al suo interno, ed è per questo che abbiamo quell'if centrale
  free(stack); //Infine liberiamo la memoria dello stack, visto che non è più necessario
}

/*
Questa funzione si occupa della stampa dell'albero simmetricamente (in modo iterativo),
prende in input solo l'albero
*/
void SimmetricOrderIterative(BTree tree) {
  Stack stack=newStack(); //Ci creiamo uno stack di appoggio
  do {
    push(stack,tree); //Aggiungiamo il ramo iniziale allo stack
    if(!isEmptyTree(tree->left)) tree=tree->left; //Se il ramo sinistro esiste, allora andiamo su quello
    else { //Altrimenti stampiamo
      outputItem(tree->value);
      pop(stack); //Eliminiamo il ramo appena stampato
      if(isEmptyStack(stack)) break; //Se lo stack è vuoto, allora vuol dire che abbiamo finito tutti i rami
      tree=top(stack); //Altrimenti prendiamo il precedente ramo nello stack
      outputItem(tree->value); //Lo stampiamo
      if (!isEmptyTree(tree->right)) { //Se esiste il ramo a destra,
        pop(stack); //Allora eliminiamo un altro elemento dallo stack
        tree=tree->right; //E andiamo al ramo destro successivo
      }
    }
  } while(1); //Il ciclo non ha condizione perché la condizione di terminazione non è alla fine del ciclo, ma al suo interno, ed è per questo che abbiamo quell'if centrale
  free(stack); //Infine liberiamo la memoria dello stack, visto che non è più necessario
}