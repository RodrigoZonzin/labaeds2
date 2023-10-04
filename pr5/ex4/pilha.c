#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

Pilha* cria_pilha(){
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->qtd = 0;
    p->topo = NULL;
    return p;
}

void empilhar(Pilha* p, int valor){
    NO* novo = (NO*)malloc(sizeof(NO));
    novo->info = valor;
    novo->prox = p->topo;
    p->topo = novo;
    p->qtd++;
}

int ver_topo(Pilha* p){
    if(p->qtd > 0){
        return p->topo->info;
    } 
    else{
        printf("A pilha esta vazia.\n");
        return -1; 
    }
}

void desempilhar(Pilha* p){
    if (p->qtd > 0){
        NO* temp = p->topo;
        p->topo = p->topo->prox;
        free(temp);
        p->qtd--;
    } 
    else{
        printf("A pilha esta vazia.\n");
    }
}

void imprimir_pilha(Pilha* p){
    printf("Pilha: [");
    NO* atual = p->topo;

    while(atual != NULL){
        printf("%d", atual->info);
        if(atual->prox != NULL) {
            printf(", ");
        }
        atual = atual->prox;
    }
    printf("]\n");
}

void destruir_pilha(Pilha* p){
    while(p->topo != NULL){
        NO* temp = p->topo;
        p->topo = p->topo->prox;
        free(temp);
    }
    free(p);
}


