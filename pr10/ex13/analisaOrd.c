#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>
#include <sys/time.h>

int insertionSort(int *vetor, int N){
    int i, chave, j, comparacoes = 0;
    for(i = 1; i < N; i++){
        chave = vetor[i];
        j = i - 1;
        comparacoes++; 
        while(j >= 0 && vetor[j] > chave){
            vetor[j + 1] = vetor[j];
            j = j - 1;
            comparacoes += 2; 
        }
        vetor[j + 1] = chave;
    }
    return comparacoes; 
}

int insertionSortRevese(int *vetor, int N){
    int i, chave, j, comparacoes = 0;
    for(i = 1; i < N; i++){
        chave = vetor[i];
        j = i - 1;
        comparacoes++; 
        while(j >= 0 && vetor[j] < chave){ 
            vetor[j + 1] = vetor[j];
            j = j - 1;
            comparacoes += 2; 
        }
        vetor[j + 1] = chave;
    }
    return comparacoes; 
}



int selectionSort(int *vetor, int N){
    int i, j, min_idx;
    int comp_count = 0; 
  
    for(i = 0; i < N - 1; i++){
        min_idx = i;
        for(j = i + 1; j < N; j++){
            comp_count++; 
            if(vetor[j] < vetor[min_idx]){
                min_idx = j;
                comp_count++;
            }
        }
  
        int temp = vetor[min_idx];
        vetor[min_idx] = vetor[i];
        vetor[i] = temp;
        comp_count++;
    }

    return comp_count; 
}

int selectionSortReverse(int *vetor, int N){
    int i, j, max_idx; 
    int comp_count = 0; 
  
    for(i = 0; i < N - 1; i++){
        max_idx = i; 
        for(j = i + 1; j < N; j++){
            comp_count++; 
            if(vetor[j] > vetor[max_idx]){ 
                max_idx = j; 
                comp_count++;
            }
        }
  
        int temp = vetor[max_idx]; 
        vetor[max_idx] = vetor[i];
        vetor[i] = temp;
        comp_count++;
    }

    return comp_count; 
}



int bubbleSort(int *vetor, int N){
    int i, j;
    int comp_count = 0; 

    for(i = 0; i < N - 1; i++){
        for(j = 0; j < N - i - 1; j++){
            comp_count++;
            if(vetor[j] > vetor[j + 1]){
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
                comp_count++;
            }
        }
        comp_count++;
    }

    return comp_count;
}

int bubbleSortReverse(int *vetor, int N){
    int i, j;
    int comp_count = 0; 

    for(i = 0; i < N - 1; i++){
        for(j = 0; j < N - i - 1; j++){
            comp_count++;
            if(vetor[j] < vetor[j + 1]){ 
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
                comp_count++;
            }
        }
        comp_count++;
    }

    return comp_count;
}


int main(int argc, char **argv){
    int N = 0;
    fscanf(stdin, "%d", &N); 
    int *vet = (int*)malloc(sizeof(int)*N);

    for(int i = 0; i<N; i++){
        fscanf(stdin, "%d", &vet[i]); 
    }


    int alg = atoi(argv[1]);

    if(alg = 1){
        printf( "n, comp,tempo\n"); 
        for(int i = 0; i<N; i = i + 5){
            int numComparacoes = 0;
            
            struct rusage comeco, fim;
            double tempo_usuario, tempo_sistema;
            
            getrusage(RUSAGE_SELF, &comeco);  
                numComparacoes = insertionSort(vet, N); 
            getrusage(RUSAGE_SELF, &fim);  

            tempo_usuario = (double)(fim.ru_utime.tv_sec-comeco.ru_utime.tv_sec)+(double)(fim.ru_utime.tv_usec-comeco.ru_utime.tv_usec)/1000000.0;
            printf( "%d,%d,%.7f\n", i, numComparacoes, tempo_usuario);
        }
    }

    else if(alg = 12){
        printf( "n,comp,tempo\n"); 
        for(int i = 0; i<N; i = i + 5){
            int numComparacoes = 0;
            
            struct rusage comeco, fim;
            double tempo_usuario, tempo_sistema;
            
            getrusage(RUSAGE_SELF, &comeco);  
                numComparacoes = insertionSortRevese(vet, N); 
            getrusage(RUSAGE_SELF, &fim);  

            tempo_usuario = (double)(fim.ru_utime.tv_sec-comeco.ru_utime.tv_sec)+(double)(fim.ru_utime.tv_usec-comeco.ru_utime.tv_usec)/1000000.0;

            printf( "%d,%d,%.7f\n", i, numComparacoes, tempo_usuario);
        }
    }

    else if(alg == 2){
        printf( "n,comp,tempo\n"); 
        for(int i = 0; i<N; i = i + 5){
            int numComparacoes = 0;
            
            struct rusage comeco, fim;
            double tempo_usuario, tempo_sistema;
            
            getrusage(RUSAGE_SELF, &comeco);  
                numComparacoes = selectionSort(vet, N); 
            getrusage(RUSAGE_SELF, &fim);  

            tempo_usuario = (double)(fim.ru_utime.tv_sec-comeco.ru_utime.tv_sec)+(double)(fim.ru_utime.tv_usec-comeco.ru_utime.tv_usec)/1000000.0;

        
            printf( "%d,%d,%.7f\n", i, numComparacoes, tempo_usuario);
        }
    }

    else if(alg == 22){
        printf( "n,comp,tempo\n"); 
        for(int i = 0; i<N; i = i + 5){
            int numComparacoes = 0;
            
            struct rusage comeco, fim;
            double tempo_usuario, tempo_sistema;
            
            getrusage(RUSAGE_SELF, &comeco);  
                numComparacoes = selectionSortReverse(vet, N); 
            getrusage(RUSAGE_SELF, &fim);  

            tempo_usuario = (double)(fim.ru_utime.tv_sec-comeco.ru_utime.tv_sec)+(double)(fim.ru_utime.tv_usec-comeco.ru_utime.tv_usec)/1000000.0;

        
            printf( "%d,%d,%.7f\n", i, numComparacoes, tempo_usuario);
        }
    }

    else if(alg == 3){
        printf( "n,comp,tempo\n"); 
        for(int i = 0; i<N; i = i + 5){
            int numComparacoes = 0;
            
            struct rusage comeco, fim;
            double tempo_usuario, tempo_sistema;
            
            getrusage(RUSAGE_SELF, &comeco);  
                numComparacoes = bubbleSort(vet, N); 
            getrusage(RUSAGE_SELF, &fim);  

            tempo_usuario = (double)(fim.ru_utime.tv_sec-comeco.ru_utime.tv_sec)+(double)(fim.ru_utime.tv_usec-comeco.ru_utime.tv_usec)/1000000.0;

        
            printf( "%d,%d,%.7f\n", i, numComparacoes, tempo_usuario);
        }
    }

    else if(alg == 32){
        printf( "n,comp,tempo\n"); 
        for(int i = 0; i<N; i = i + 5){
            int numComparacoes = 0;
            
            struct rusage comeco, fim;
            double tempo_usuario, tempo_sistema;
            
            getrusage(RUSAGE_SELF, &comeco);  
                numComparacoes = bubbleSortReverse(vet, N); 
            getrusage(RUSAGE_SELF, &fim);  

            tempo_usuario = (double)(fim.ru_utime.tv_sec-comeco.ru_utime.tv_sec)+(double)(fim.ru_utime.tv_usec-comeco.ru_utime.tv_usec)/1000000.0;

            printf( "%d,%d,%.7f\n", i, numComparacoes, tempo_usuario);
        }
    }


    free(vet); 
    return 0; 
}