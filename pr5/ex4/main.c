#include "pilha.h"

int main(){
    Pilha* pilha = cria_pilha();

    empilhar(pilha, 10);
    empilhar(pilha, 20);
    empilhar(pilha, 30);

    printf("Topo da pilha: %d\n", ver_topo(pilha));

    desempilhar(pilha);

    imprimir_pilha(pilha);
    destruir_pilha(pilha);

    return 0;
}