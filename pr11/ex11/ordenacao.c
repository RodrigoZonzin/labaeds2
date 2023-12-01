#include <stdlib.h>
#include <stdio.h>
#include <sys/resource.h>
#include <sys/time.h>


void shellsort(int*, int);
void shellsortReverse(int*, int);

void quicksort(int*, int, int);
void quicksortReverse(int*, int, int);

void mergesort(int*, int, int);
void mergesortReverse(int*, int, int);

void heapsort(int*, int);
void heapsortReverse(int*, int);

void shellsort(int *vetor, int n){
    int intervalo, i, j, temp;
    for(intervalo = n / 2; intervalo > 0; intervalo /= 2){
        for(i = intervalo; i < n; i += 1){
            temp = vetor[i];
            for(j = i; j >= intervalo && vetor[j - intervalo] > temp; j -= intervalo){
                vetor[j] = vetor[j - intervalo];
            }
            vetor[j] = temp;
        }
    }
}

void shellsortReverse(int *vetor, int n) {
    int intervalo, i, j, temp;
    for (intervalo = n / 2; intervalo > 0; intervalo /= 2) {
        for (i = intervalo; i < n; i += 1) {
            temp = vetor[i];
            for (j = i; j >= intervalo && vetor[j - intervalo] < temp; j -= intervalo) {
                vetor[j] = vetor[j - intervalo];
            }
            vetor[j] = temp;
        }
    }
}


void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particiona(int vetor[], int inicio, int fim) {
    int pivo = vetor[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (vetor[j] <= pivo) {
            i++;
            troca(&vetor[i], &vetor[j]);
        }
    }
    troca(&vetor[i + 1], &vetor[fim]);
    return i + 1;
}

void quicksort(int *vetor, int inicio, int fim) {
    if (inicio < fim) {
        int indice_pivo = particiona(vetor, inicio, fim);

        quicksort(vetor, inicio, indice_pivo - 1);
        quicksort(vetor, indice_pivo + 1, fim);
    }
}

int particionaReverse(int vetor[], int inicio, int fim) {
    int pivo = vetor[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (vetor[j] >= pivo) { 
            i++;
            troca(&vetor[i], &vetor[j]);
        }
    }
    troca(&vetor[i + 1], &vetor[fim]);
    return i + 1;
}

void quicksortReverse(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int indice_pivo = particionaReverse(vetor, inicio, fim);

        quicksortReverse(vetor, inicio, indice_pivo - 1);
        quicksortReverse(vetor, indice_pivo + 1, fim);
    }
}

// HEAPSORT
void maxHeapify(int vetor[], int tamanho, int indice) {
    int maior = indice;
    int filho_esq = 2 * indice + 1;
    int filho_dir = 2 * indice + 2;

    if (filho_esq < tamanho && vetor[filho_esq] > vetor[maior])
        maior = filho_esq;

    if (filho_dir < tamanho && vetor[filho_dir] > vetor[maior])
        maior = filho_dir;

    if (maior != indice) {
        troca(&vetor[indice], &vetor[maior]);
        maxHeapify(vetor, tamanho, maior);
    }
}

void heapsort(int vetor[], int tamanho) {
    for (int i = tamanho / 2 - 1; i >= 0; i--)
        maxHeapify(vetor, tamanho, i);

    for (int i = tamanho - 1; i >= 0; i--) {
        troca(&vetor[0], &vetor[i]);
        maxHeapify(vetor, i, 0);
    }
}


void maxHeapifyReverse(int vetor[], int tamanho, int indice) {
    int maior = indice;
    int filho_esq = 2 * indice + 1;
    int filho_dir = 2 * indice + 2;

    if (filho_esq < tamanho && vetor[filho_esq] < vetor[maior])
        maior = filho_esq;

    if (filho_dir < tamanho && vetor[filho_dir] < vetor[maior])
        maior = filho_dir;

    if (maior != indice) {
        troca(&vetor[indice], &vetor[maior]);
        maxHeapifyReverse(vetor, tamanho, maior);
    }
}

void heapsortReverse(int vetor[], int tamanho) {
    for (int i = tamanho / 2 - 1; i >= 0; i--)
        maxHeapifyReverse(vetor, tamanho, i);

    for (int i = tamanho - 1; i >= 0; i--) {
        troca(&vetor[0], &vetor[i]);
        maxHeapifyReverse(vetor, i, 0);
    }
}

//MERGE
void merge(int vetor[], int esquerda, int meio, int direita) {
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    int *esq = (int *)malloc(n1 * sizeof(int));
    int *dir = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        esq[i] = vetor[esquerda + i];
    for (int j = 0; j < n2; j++)
        dir[j] = vetor[meio + 1 + j];

    int i = 0, j = 0, k = esquerda;
    while (i < n1 && j < n2) {
        if (esq[i] <= dir[j]) {
            vetor[k] = esq[i];
            i++;
        } else {
            vetor[k] = dir[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vetor[k] = esq[i];
        i++;
        k++;
    }

    while (j < n2) {
        vetor[k] = dir[j];
        j++;
        k++;
    }

    free(esq);
    free(dir);
}

void mergesort(int vetor[], int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        mergesort(vetor, esquerda, meio);
        mergesort(vetor, meio + 1, direita);

        merge(vetor, esquerda, meio, direita);
    }
}

void mergeReverse(int vetor[], int esquerda, int meio, int direita) {
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    int *esq = (int *)malloc(n1 * sizeof(int));
    int *dir = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        esq[i] = vetor[esquerda + i];
    for (int j = 0; j < n2; j++)
        dir[j] = vetor[meio + 1 + j];

    int i = 0, j = 0, k = esquerda;
    while (i < n1 && j < n2) {
        if (esq[i] >= dir[j]) { 
            vetor[k] = esq[i];
            i++;
        } else {
            vetor[k] = dir[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vetor[k] = esq[i];
        i++;
        k++;
    }

    while (j < n2) {
        vetor[k] = dir[j];
        j++;
        k++;
    }

    free(esq);
    free(dir);
}

void mergesortReverse(int vetor[], int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        mergesortReverse(vetor, esquerda, meio);
        mergesortReverse(vetor, meio + 1, direita);

        mergeReverse(vetor, esquerda, meio, direita);
    }
}

/* 
int main(int argc, char** argv){
    int N = 0; 
    struct rusage inicio, fim;
    struct timeval tempo_inicial, tempo_final;

    fscanf(stdin, "%d", &N); 
    int *vet  =(int*)malloc(sizeof(int)*N);

    for(int i =0; i<N; i++){
        fscanf(stdin, "%d", &vet[i]); 
    }

    int alg = atoi(argv[1]);


    if(alg == 1){
        for(int i=0; i< N; i++){
            getrusage(RUSAGE_SELF, &inicio);        
                shellsort(vet, i); 
            getrusage(RUSAGE_SELF, &fim);
            tempo_inicial = inicio.ru_utime;
            tempo_final = fim.ru_utime;
            double tempo_execucao = (tempo_final.tv_sec - tempo_inicial.tv_sec) +
                                    (tempo_final.tv_usec - tempo_inicial.tv_usec) / 1000000.0;
            printf("%d,%.10lf\n", i, tempo_execucao);
        }
    }

    if(alg == 12){
        shellsortReverse(vet, N); 
    }

    if(alg == 2){
        quicksort(vet, 0, N); 
    }

    if(alg == 22){
        quicksortReverse(vet, 0, N); 
    }

    if(alg == 3){
        heapsort(vet, N);
    }

    if(alg == 32){
        heapsortReverse(vet, N);
    }

    if(alg == 4){
        mergesort(vet, 0, N); 
    }
    if(alg == 42){
        mergesortReverse(vet, 0, N);
    }
}
*/

int main(int argc, char** argv) {
    int N = 0;
    fscanf(stdin, "%d", &N);
    int *vet = (int*)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++) {
        fscanf(stdin, "%d", &vet[i]);
    }

    int alg = atoi(argv[1]);

    struct rusage inicio, fim;
    struct timeval tempo_inicial, tempo_final;

    N = 1000;
    for (int i = 0; i < N; i++){
        getrusage(RUSAGE_SELF, &inicio);
        if (alg == 1) {
            shellsort(vet, i);
        } else if (alg == 12) {
            shellsortReverse(vet, N); 
        } else if (alg == 2) {
            quicksort(vet, 0, N);
        } else if (alg == 22) {
            quicksortReverse(vet, 0, N); 
        } else if (alg == 3) {
            heapsort(vet, N);
        } else if (alg == 32) {
            heapsortReverse(vet, N); 
        } else if (alg == 4) {
            mergesort(vet, 0, N);
        } else if (alg == 42) {
            mergesortReverse(vet, 0, N); 
        }
        getrusage(RUSAGE_SELF, &fim);
        tempo_inicial = inicio.ru_utime;
        tempo_final = fim.ru_utime;
        double tempo_execucao = (tempo_final.tv_sec - tempo_inicial.tv_sec) +
                                (tempo_final.tv_usec - tempo_inicial.tv_usec) / 1000000.0;
        printf("%d,%.10lf\n", i, tempo_execucao);
    }

    if(alg == -1){
        for(int i = 0; i<30; i++){
            printf("%d ", vet[i]);
        }
        printf("\n");
    }
    

    free(vet);
    return 0;
}