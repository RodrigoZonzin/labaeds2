#include "fila.h"

Fila* cria_fila(){
    Fila*f=(Fila*)malloc(sizeof(Fila));
    f->qtd=0;
    f->ini= NULL;
    f->fim= NULL;
    return f;
}

void enfilera(Fila*f, int a){
    NO* novo=(NO*)malloc(sizeof(NO));

    novo->info = a;
    novo->prox = NULL;

    if(f->qtd == 0){
        f->ini = novo;
        f->fim = novo;
    }
    else{
        f->fim->prox=novo;
        f->fim=novo;
    }

    f->qtd++;
}

void desenfilera(Fila*f){
    if(f->qtd==0){
        return;
    }

    NO* temp = f->ini;
    f->ini=f->ini->prox;
    free(temp);
    f->qtd--;
}

void imprime_fila(Fila*f){
    printf("[");
    NO*atual=f->ini;

    while(atual!=NULL){
        if(atual->prox == NULL){
            printf("%d]\n", atual->info);
            break;
        }
        printf("%d ",atual->info);
        atual=atual->prox;
    }
}

int inicio_fila(Fila*f){
    if(f->qtd==0){
        printf("Lista vazia.\n");
        return-1;
    }
    return f->ini->info;
}

void destroiFila(Fila*f){
    NO*atual=f->ini;
    while(atual!=NULL){
        NO*temp=atual;
        atual=atual->prox;
        free(temp);
    }
    free(f);
}