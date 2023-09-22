#include "inteiros.h"


int main(){

    Inteiros *A = cria_conjunto_vazio(3);
    inserir_elemento(A, 1);
    inserir_elemento(A, 2);
    inserir_elemento(A, 3);
    inserir_elemento(A, 4);

    Inteiros *B = cria_conjunto_vazio(2);
    inserir_elemento(B, 1);
    inserir_elemento(B, 6);

    Inteiros *C = uniao(A, B);
    printa_conjunto(C);
    
    

    //printf("Menor: %d\n", menor_valor(A));
    //printf("Maior: %d\n", maior_valor(A));

    return 0;
}