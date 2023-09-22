#include <stdlib.h>
#include <stdio.h>

void imprime_ordem_decrescente(char* vet, int pos_i){
    if(pos_i < 0) return; 
    printf("%c", vet[pos_i]); 
    imprime_ordem_decrescente(vet, pos_i-1);
}

int comparaChar(const void* a, const void* b){
    return (*(char*)a - *(char*)b);
}


int main(int argc, char** argv){
    int n = 13; 
    char vet_palavras[13] = "RODRIGOZONZIN";     

    qsort(vet_palavras, n, sizeof(char), comparaChar);

    imprime_ordem_decrescente(vet_palavras, n-1);
    printf("\n"); 

    return 0;
}