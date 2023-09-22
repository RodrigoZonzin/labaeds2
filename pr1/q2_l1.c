#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

int* preenche_vetor(int n); 
int maior_vetor(int*, int); 
int menor_vetor(int*, int); 
float media_vetor(int*, int); 
void desaloca(int*);

int main(int argc, char **argv){
    int n = atoi(argv[1]);
    int *v = preenche_vetor(n);
    

    printf("Maior: %d\n", maior_vetor(v, n));
    printf("Menor: %d\n", menor_vetor(v, n));
    printf("Media: %.2f\n", media_vetor(v, n));

    desaloca(v);
    return 0;
}

int maior_vetor(int *v, int n){
    int maior = v[0];

    for(int i = 0; i<n; i++){
        if(v[i] >= maior){
            maior = v[i];
        }
    }

    return maior;
}

int menor_vetor(int *v, int n){
    int menor = v[0];

    for(int i = 0; i<n; i++){
        if(v[i] <= menor){
            menor = v[i];
        }
    }

    return menor;
}

float media_vetor(int *v, int n){
    int sum = 0; 
    float media;
    
    for(int i =0; i<n; i++){
        sum += v[i];
    }
    return (float)sum/n;
}

int* preenche_vetor(int n){
    int * vetor = (int*)malloc(sizeof(int)*n);
    srand((time_t)time(NULL));

    for(int i = 0; i<n; i++){
        vetor[i] = rand() % 100;
    }

    return vetor;
}

void desaloca(int *v){
    free(v);
}


