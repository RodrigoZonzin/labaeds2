#include <stdio.h>
#include <stdlib.h>


void insertionSort(int *vetor, int N){
    int i, chave, j;
    for(i = 1; i < N; i++){
        chave = vetor[i];
        j = i - 1;

        while(j >= 0 && vetor[j] > chave){
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }
}

void insertionSortReverse(int *vetor, int N){
    int i, chave, j;
    for(i = 1; i < N; i++){
        chave = vetor[i];
        j = i - 1;

        while(j >= 0 && vetor[j] < chave){
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }
}

void selectionSort(int *vetor, int N){
    int i, j, min_idx;
  
    for(i = 0; i < N - 1; i++){
        min_idx = i;
        for(j = i + 1; j < N; j++){
            if(vetor[j] < vetor[min_idx]){
                min_idx = j;
            }
        }
  
        int temp = vetor[min_idx];
        vetor[min_idx] = vetor[i];
        vetor[i] = temp;
    }
}

void selectionSortReverse(int *vetor, int N){
    int i, j, max_idx;
  
    for(i = 0; i < N - 1; i++){
        max_idx = i;
        for(j = i + 1; j < N; j++){
            if(vetor[j] > vetor[max_idx]){
                max_idx = j;
            }
        }
  
        int temp = vetor[max_idx];
        vetor[max_idx] = vetor[i];
        vetor[i] = temp;
    }
}

void bubbleSort(int vetor[], int N){
    int i, j;
    for(i = 0; i < N - 1; i++){
        for(j = 0; j < N - i - 1; j++){
            if(vetor[j] > vetor[j + 1]){
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

void bubbleSortReverse(int vetor[], int N){
    int i, j;
    for(i = 0; i < N - 1; i++){
        for(j = 0; j < N - i - 1; j++){
            if(vetor[j] < vetor[j + 1]){
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}


int main(int argc, char** argv){
    int N = 0; 
    fscanf(stdin, "%d", &N); 
    int *vet  =(int*)malloc(sizeof(int)*N);

    for(int i =0; i<N; i++){
        fscanf(stdin, "%d", &vet[i]); 
    }

    int alg = atoi(argv[1]);

    if(alg == 1){
        bubbleSort(vet, N);
        for(int i =0; i<N; i++){
            fprintf(stdout, "%d  ", vet[i]); 
        }
        printf("\n");
    }

    if(alg == 12){
        bubbleSortReverse(vet, N);
        for(int i =0; i<N; i++){
            fprintf(stdout, "%d  ", vet[i]); 
        }
        printf("\n");
    }

    if(alg == 2){
        selectionSort(vet, N);
        for(int i =0; i<N; i++){
            fprintf(stdout, "%d  ", vet[i]); 
        }
        printf("\n");
    }

    if(alg == 22){
        selectionSortReverse(vet, N);
        for(int i =0; i<N; i++){
            fprintf(stdout, "%d  ", vet[i]); 
        }
        printf("\n");
    }

    if(alg == 3){
        insertionSort(vet, N);
        for(int i =0; i<N; i++){
            fprintf(stdout, "%d  ", vet[i]); 
        }
        printf("\n");
    }

    if(alg == 32){
        insertionSortReverse(vet, N);
        for(int i =0; i<N; i++){
            fprintf(stdout, "%d  ", vet[i]); 
        }
        printf("\n");
    }

    return 0;
}