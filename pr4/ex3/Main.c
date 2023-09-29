#include <stdio.h>
#include "LDE.h"

int main(){
    Lista *L;
    L = criaLista();

    inserirOrdenado(L, 80);
    inserirOrdenado(L, 90);
    inserirOrdenado(L, 20);
    inserirOrdenado(L, 40);
    inserirOrdenado(L, 70);
    inserirOrdenado(L, 50);
    inserirOrdenado(L, 60);
    inserirOrdenado(L, 30);
    inserirOrdenado(L, 10);


    printf("Existe 90? %d\n", procura(L, 90));
    printf("Existe 511? %d\n", procura(L, 511));
    printf("Tamanho %d\n", tamanho(L));
    

    imprimeLista(L);

    removerElemento(L, 20);
    removerElemento(L, 90);

    imprimeLista(L);

    destroiLista(L);
    return 0;
}