#include "fila.h"

Fila* cria_fila(){
    Fila *f = (Fila*)malloc(sizeof(Fila*)); 
    f->elementos = (int*)malloc(sizeof(int)*50);
    f->n = 0;

    return f;
}

void enfilera(Fila *f, int a){
    f->elementos[f->n] = a;
    f->n = f->n + 1;
}

void desenfilera(Fila *f){
    for(int i = 0; i< (f->n)-1; i++){
        f->elementos[i] = f->elementos[i+1]; 
    }
    f->n = f->n - 1; 
}

void imprime_fila(Fila *f){
    printf("[");
    for(int i = 0; i<(f->n)-1; i++){
        printf("%d ", f->elementos[i]); 
    }
    printf("%d]\n", f->elementos[f->n -1]);
}

int inicio_fila(Fila *f){
    return f->elementos[0];
}

void destroiFila(Fila *f){
    free(f->elementos);
    free(f);
}

void clearTerminal(){
    #ifdef _WIN32
        system("cls"); // Limpa o terminal no Windows
    #else
        system("clear"); // Limpa o terminal no Unix/Linux
    #endif
}
