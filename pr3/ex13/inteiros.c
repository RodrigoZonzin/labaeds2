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
    for(int i = 0; i < A->ocupado-1; i++){
        printf("%d,", A->elemento[i]);
    }
    printf("%d]\n", A->elemento[A->ocupado-1]);
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

Inteiros* uniao(Inteiros *A, Inteiros *B) {
    Inteiros *C = cria_conjunto_vazio(A->n + B->n);

    for(int i = 0; i< A->ocupado; i++){
        inserir_elemento(C, A->elemento[i]);
    }

    for(int i = 0; i< B->ocupado; i++){
        if(!pertence(A, B->elemento[i])){
            inserir_elemento(C, B->elemento[i]);
        }
    }

    return C;
}

Inteiros* diferenca(Inteiros *A, Inteiros *B){
    Inteiros *dif = cria_conjunto_vazio(A->n);

    for(int i = 0; i< A->ocupado; i++){
        if(!pertence(B, A->elemento[i])){
            inserir_elemento(dif, A->elemento[i]);
        }
    }

    return dif;
}

Inteiros* intersecao(Inteiros *A, Inteiros *B){
    Inteiros *intersec = cria_conjunto_vazio(A->n);

    for (int i = 0; i < A->ocupado; i++){
        if(pertence(B, A->elemento[i])){
            inserir_elemento(intersec, A->elemento[i]);
        }
    }

    return intersec;
}

int tam_inteiros(Inteiros*A){
    return A->ocupado;
}

// RETORNA 1 SE O CONJUNTO FOR VAZIO E 0 EM CONTRARIO
int vazio(Inteiros *A){
    int i = 0;
    while(i< A->ocupado){
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

void destroi(Inteiros *A){
    free(A->elemento);
    free(A);
}