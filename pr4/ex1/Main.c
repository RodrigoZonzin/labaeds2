#include <stdio.h>
#include "Lista.h"

int main(){
    Lista *L;
    L = criaLista();

    insereFim(L, 10);
    insereFim(L, 20);
    insereFim(L, 21);
    insereFim(L, 28);
    insereFim(L, 30);

    removeLi(L, 20);

    imprimeLista(L);

    destroiLista(L);
    return 0;
}