#define _FILA_H

#include <stdio.h>
#include <stdlib.h>


struct fila{
    int *elementos;
    int n;
};
typedef struct fila Fila;

Fila* cria_fila();
void enfilera(Fila*, int);
void desenfilera(Fila*);
void imprime_fila(Fila*); 
void destroiFila(Fila*);
