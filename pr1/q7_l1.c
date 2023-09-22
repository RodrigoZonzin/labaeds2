#include <stdlib.h>
#include <stdio.h>

int somatorio_gaussiano(int n){
    return n*(n+1)/2;
}

int soma_intervalo(int i, int n){
    return somatorio_gaussiano(n) - somatorio_gaussiano(i-1); 
}

void imprime(int a, int b){
    if(b-a <= 0) return;
    printf("%d ", soma_intervalo(a, b));
    imprime(a, b-1);
}

int main(int agc, char **argv){

    int a = atoi(argv[1]), 
        b = atoi(argv[2]); 

    imprime(a, b);
    printf("\n");

    return 0;
}