#define _INTEIROS_H
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct inteiros{
    int *elemento;
    int n;
    int ocupado;
};

typedef struct inteiros Inteiros;

Inteiros* cria_conjunto_vazio(int n);
void printa_conjunto(Inteiros*);

void inserir_elemento(Inteiros*, int);
void remover_elemento(Inteiros*, int);
int pertence(Inteiros*, int);
int maior_valor(Inteiros*);
int menor_valor(Inteiros*);
int tam_inteiros(Inteiros*);

Inteiros* intersecao(Inteiros*, Inteiros*);
Inteiros* uniao(Inteiros*, Inteiros*);
int vazio(Inteiros*);
int Inteiros_iguais(Inteiros*, Inteiros*);
Inteiros* diferenca(Inteiros*, Inteiros*);

void destroi(Inteiros*);