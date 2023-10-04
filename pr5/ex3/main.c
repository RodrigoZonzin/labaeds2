#include "pilha.h"

int main(){
    int tamanho = 50; 
    Pilha* pilha = cria_pilha(tamanho);

    empilhar(pilha, 10);
    empilhar(pilha, 20);
    empilhar(pilha, 30);
    imprimir_pilha(pilha);

    printf("Topo: %d\n", ver_topo(pilha));

    desempilhar(pilha);
    desempilhar(pilha);

    imprimir_pilha(pilha);

    destruir_pilha(pilha);

    return 0;
}
