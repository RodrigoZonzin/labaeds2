#include <stdio.h>
#include "LSE.h"

int main(){
    Lista *L;
    L = criaLista();

    insereOrdenado(L, 10);
    insereOrdenado(L, 30);
    insereOrdenado(L, 8);
    insereOrdenado(L, 1);
    insereOrdenado(L, 30);
    insereOrdenado(L, 30);
    printf("Tamanho: %d\n", tamanhoLi(L));
    printf("Existe 20? Onde esta?: %d\n", procuraLi(L, 30));
    //removeIni(L);

    imprimeLista(L);
    removerElemento(L, 30);
    imprimeLista(L);

    destroiLista(L);
    return 0;
}
