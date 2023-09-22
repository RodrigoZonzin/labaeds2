#include <stdlib.h>
#include <stdio.h>


void int_preenche(int* vet, int n){
    if(n < 0) return; 
    vet[n] = -555; 
    int_preenche(vet, n-1);
}

void int_preenche_decresc(int* vet, int n){
    if(n < 0) return; 
    vet[n] = n; 
    int_preenche_decresc(vet, n-1);
}

void int_preenche_cresc(int* vet, int n){
    if(n < 0) return; 
    int_preenche_cresc(vet, n-1);
    vet[n] = n; 
}

int maior(int* vet, int n) {
    if(n == 1) return vet[0];

    int maior_corrente = maior(vet+1, n-1);
    
    return (vet[0] > maior_corrente) ? vet[0] : maior_corrente;
}

int main(){
    int n = 5; 
    int* vet = (int*)malloc(sizeof(int)*n); 

    /* preenche */
    int_preenche(vet,n-1);
    for(int i =0; i<n; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");

    /* preenche crescente */
    int_preenche_cresc(vet,n-1);
    for(int i =0; i<n; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");

    /* preenche decrescente */
    int_preenche_decresc(vet,n-1);
    for(int i =0; i<n; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");

    /*maior*/
    printf("Maior: %d\n", maior(vet, 5)); 

    free(vet);
    return 0;
}