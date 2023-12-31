#include <stdio.h>
#include "LCSE.h"

int main(){
    Lista *L;
    L = criaLista();

    insereFim(L, 10);
    insereFim(L, 20);
    insereFim(L, 30);
    insereFim(L, 40);
    insereFim(L, 50);
    insereFim(L, 60);
    insereFim(L, 70);
    insereFim(L, 80);
    insereFim(L, 90);

    printf("Tamanho: %d\n", tamanho(L));
    printf("Procura 90: %d\n", procura(L, 90));

    removeIni(L);
    removeFim(L);

    imprimeLista(L);

    destroiLista(L);


    return 0;
}