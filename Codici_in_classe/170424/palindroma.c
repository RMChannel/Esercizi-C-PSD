#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindromaRic(char *s, int l) {
    if (l<=1) return 1;
    else if (s[0]!=s[l-1]) return 0;
    else return palindromaRic(s+1,l-2);
}

int palindromaRecall(char *s) {
    return palindromaRic(s,strlen(s));
}

int palindroma(char *s) {
    if (strlen(s)<2) return 1;
    char *p1=s, *p2=s;
    for(;*p2;p2++);
    for(p2--;p1<p2;p1++,p2--) {
        for(;*p1==' ';p1++);
        for(;*p2==' ';p2--);
        if(*p1!=*p2) return 0;
    }
    return p1>=p2;
}

int main(int argc, char *argv[]) {
    if (argc!=2) {
        fprintf(stderr,"Numero di parametri errato\n");
        exit(EXIT_FAILURE);
    }
    if (palindromaRecall(argv[1])) printf("%s e' palindroma\n",argv[1]);
    else printf("%s non e' palindroma\n",argv[1]);
    return 0;
}