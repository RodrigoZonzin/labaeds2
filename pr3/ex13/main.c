#include "inteiros.h"


int main(){

    Inteiros *A = cria_conjunto_vazio(3);
    inserir_elemento(A, 1);
    inserir_elemento(A, 2);
    inserir_elemento(A, 3);
    inserir_elemento(A, 4);

    Inteiros *B = cria_conjunto_vazio(2);
    inserir_elemento(B, 1);
    inserir_elemento(B, 3);
    inserir_elemento(B, 6);
    inserir_elemento(B, 9);
    printf("A = ");
    printa_conjunto(A);
    printf("B = ");
    printa_conjunto(B);
    printf("\n");

    
    printf("Uniao:\n");
    Inteiros *_uniao = uniao(A, B);
    printa_conjunto(_uniao);

    printf("\nIntersecao:\n");
    Inteiros *_inter = intersecao(A, B);
    printa_conjunto(_inter);

    printf("\nA-B:\n");
    Inteiros *_dif1 = diferenca(A, B);
    printa_conjunto(_dif1);

    printf("\nB-A:\n");
    Inteiros *_dif2 = diferenca(B, A);
    printa_conjunto(_dif2);


    printf("\nA == B? : %d\n", Inteiros_iguais(A, B));

    destroi(A);
    destroi(B);
    destroi(_uniao);
    destroi(_inter);
    destroi(_dif1);
    destroi(_dif2);


    return 0;
}