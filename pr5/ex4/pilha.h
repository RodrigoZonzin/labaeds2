#define _PILHA_H


typedef struct NO{
    int info ;
    struct NO* prox ;
}NO;

typedef struct{
    int qtd;
    struct NO* topo ;
}Pilha ;
