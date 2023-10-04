#include "fila.h"

int main(){
    Fila *f = cria_fila();

    enfilera(f, 00);
    enfilera(f, 01);
    enfilera(f, 10);
    enfilera(f, 11);

    imprime_fila(f);

    desenfilera(f);
    imprime_fila(f);



    return 0;
}