#include "fila.h"

int main(){
    int chamada = 10;
    int elemento;
    Fila *f;

    while(chamada != 7){
        printf("\n\n1-Cria Fila\t2-Enfilera\t3-VerInicio\n");
        printf("4-Desenfilera\t5-Imprimir\t6-Destruir\n");
        scanf("%d", &chamada);


        if(chamada == 1){
            f = cria_fila();
            continue;
        }

        if(chamada == 2){
            printf("Qual elemento?\n"); 
            scanf("%d", &elemento); 
            enfilera(f, elemento);
            continue;
        }

        if(chamada == 3){
            printf("%d\n", inicio_fila(f)); 
            continue;
        }

        if(chamada == 4){
            desenfilera(f);
            continue;
        }

        if(chamada==5){
            imprime_fila(f);
            continue;
        }

        if(chamada == 6){
            destroiFila(f);
            break;
        }
    }
    printf("E eh isso\n");
    return 0;
}