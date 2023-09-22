#include <stdio.h>
#include <stdlib.h>


int negativos(int*, int);

int negativos(int *vet, int N){
    int count = 0; 

    for(int i = 0; i<N; i++){
        if(vet[i] < 0) count++; 
    }

    return count;
}


int main(){
    int vet[5] = {-1, 2, -3, -4, 5};
    printf("%d\n", negativos(vet, sizeof(vet)/sizeof(vet[0])));


    return 0; 
}


