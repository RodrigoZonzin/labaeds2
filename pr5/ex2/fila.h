#define _FILA_H

#include <stdlib.h>
#include <stdio.h>

typedef struct NO{
    int info ;
    struct NO* prox ;
}NO;

typedef struct fila{
    int qtd;
    struct NO* ini;
    struct NO* fim;
}Fila;

Fila* cria_fila();
void enfilera(Fila*, int);
void desenfilera(Fila*);
void imprime_fila(Fila*);
int inicio_fila(Fila*);
void destroiFila(Fila*);