/*
    Criar pilha;
    Empilhar um item;
    Ver o topo da pilha.
    Desempilhar um item;
    Imprimir a pilha;
    Destruir a pilha;
    Sair;
*/
#include "pilha.h"

#include <stdio.h>
#include <stdlib.h>

Pilha* cria_pilha(int tamanho){
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->elementos = (int*)malloc(sizeof(int) * tamanho);
    p->n = 0;
    return p;
}

void empilhar(Pilha* p, int valor){
    p->elementos[p->n] = valor;
    p->n = p->n +1; 
}

int ver_topo(Pilha* p){
    if (p->n > 0){
        return p->elementos[p->n - 1];
    } 
    else{
        printf("A pilha esta vazia.\n");
        return -1; 
    }
}

void desempilhar(Pilha* p){
    if (p->n > 0) {
        p->n--;
    } else {
        printf("A pilha esta vazia.\n");
    }
}

void imprimir_pilha(Pilha* p) {
    printf("[");
    for (int i = 0; i < p->n - 1; i++) {
        printf("%d, ", p->elementos[i]);
    }

    if (p->n > 0) {
        printf("%d", p->elementos[p->n - 1]);
    }

    printf("]\n");
}

void destruir_pilha(Pilha* p) {
    free(p->elementos);
    free(p);
}


