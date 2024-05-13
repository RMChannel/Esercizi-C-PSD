#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "btree.h"
#include "stack.h"

int isOperation(char *temp) {
    if ((*temp)=='+' || (*temp)=='*' || (*temp)=='-' || (*temp)=='/') return 1;
    else return 0;
}

void printSpace(char *temp)  {
    int control=isOperation(temp);
    if (control) printf(" ");
    outputItem(temp);
    if (control) printf(" ");
}

void inOrderInMain(BTree tree, BTree treeRoot) {
    if (!isEmptyTree(tree)) {
        if (isOperation(getBTreeRoot(tree)) && tree!=treeRoot) printf("(");
        inOrderInMain(getLeft(tree),treeRoot);
        printSpace((getBTreeRoot(tree)));
        inOrderInMain(getRight(tree),treeRoot);
        if (isOperation(getBTreeRoot(tree)) && tree!=treeRoot) printf(")");
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    if ((fp=fopen("input.txt","r"))==NULL) {
        fprintf(stderr,"File non trovato\n");
        exit(EXIT_FAILURE);
    }
    char line[100];
    while(fgets(line,sizeof(line),fp)) {
        char *lineP=line;
        int control=1;
        BTree number1, number2, operation;
        while(*lineP) {
            char *temp=malloc(sizeof(char)*10);
            sscanf(lineP,"%s",temp);
            lineP+=strlen(temp)+1;
            if(atoi(temp)) {
                if (control) {
                    number1=buildTree(NULL,NULL,temp);
                    control=0;
                }
                else {
                    number2=buildTree(NULL,NULL,temp);
                    control=1;
                }
            }
            else if (isOperation(temp)) {
                operation=buildTree(number1,number2,temp);
                number1=operation;
                number2=newTree();
                control=0;
            }
        }
        inOrderInMain(operation,operation);
        printf("\n");
    }
    return 0;
}