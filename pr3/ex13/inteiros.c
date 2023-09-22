#include "inteiros.h"


int comparador(const void *a, const void *b){
    return (*(int*)b - *(int*)a);
}

Inteiros* cria_conjunto_vazio(int n){
    Inteiros *A = (Inteiros*)malloc(sizeof(Inteiros));
    A->elemento = (int*)malloc(sizeof(int)*n);

    for(int i = 0; i<n; i++){
        A->elemento[i] = -99999;
    }
    
    
    A->n = n;
    A->ocupado = 0;

    return A;
}

void printa_conjunto(Inteiros *A){
    printf("[");
    for(int i = 0; i < A->ocupado; i++){
        printf("%d,", A->elemento[i]);
    }
    printf("]\n");
}

int menor_valor(Inteiros *A){
    int menor = A->elemento[0];

    for(int i = 0; i< A->ocupado; i++){
        if(A->elemento[i] <= menor && A->elemento[i] != -9999) menor = A->elemento[i];
    }

    return menor;
}

int maior_valor(Inteiros *A){
    int maior = A->elemento[0];

    for(int i = 0; i< A->ocupado; i++){
        if(A->elemento[i] >= maior) maior = A->elemento[i];
    }

    return maior;
}


void inserir_elemento(Inteiros *A, int ai){
    if(A->ocupado == A->n){
        A->elemento = realloc(A->elemento, sizeof(int)*A->n+10);
        A->n = sizeof(int)*A->n+10; 
    }

    for(int i = 0; i<A->ocupado; i++){
        if(A->elemento[i] == ai) return;
    }

    A->elemento[A->ocupado] = ai;
    A->ocupado = A->ocupado + 1;
}

Inteiros* uniao(Inteiros *A, Inteiros *B){
    
    int maior_n = (A->n >= B->n) ? A->n : B->n;
    int menor_n = (A->n < B->n) ? A->n : B->n;

    Inteiros *C = cria_conjunto_vazio(menor_n);

    for(int i = 0; i<maior_n; i++){
        for(int j = 0; j<menor_n; j++){
            if(A->elemento[i] == B->elemento[j]){
                C->elemento[j] = A->elemento[i];
            }
        }
    }

    return C;
}

int tam_inteiros(Inteiros*A){
    return A->ocupado;
}

/* RETORNA 1 SE O CONJUNTO FOR VAZIO E 0 EM CONTRÁRIO*/
int vazio(Inteiros *A){
    int i = 0;
    while(A->elemento[i]){
        if(A->elemento[i] != -9999) return 0;
        i++;
    }

    return 1;
}


int Inteiros_iguais(Inteiros *A, Inteiros *B){
    if(A->ocupado != B->ocupado) return 0;
    
    for(int i = 0; i< A->ocupado; i++){
        if(A->elemento[i] != B->elemento[i]) return 0;
    }

    return 1;
}

int pertence(Inteiros *A, int ai){
    for(int i = 0; i< A->ocupado; i++){
        if(A->elemento[i] == ai) return 1; 
    }

    return 0;
}

void remover_elemento(Inteiros *A, int ai){
    for(int i = 0; i<A->ocupado; i++){
        if(A->elemento[i] == ai){
            A->elemento[i] = -9999;
        }
    }
    //qsort(A->elemento, A->n, sizeof(int), comparador);
}
