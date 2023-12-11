#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Medidas de Complexidade
int comp; //Num. de comparacoes

int* copiaVetor(int* v, int n){
    int i;
    int *v2;
    v2 = (int*) malloc (n*sizeof(int));
    for(i=0; i<n; i++) v2[i] = v[i];
    return v2;
}
void imprimeVetor(int* v, int n){
    int i, prim = 1;
    printf("[");
    for(i=0; i<n; i++)
        if(prim){ printf("%d", v[i]); prim = 0; }
        else printf(", %d", v[i]);
    printf("]\n");
}

void preencheAleatorio(int* v, int n, int ini, int fim){
    int i;
    for(i=0; i<n; i++)
        v[i] = ini + rand() % (fim-ini + 1); 
}

void troca(int* a, int *b){
	int aux = *a;
	*a = *b;
	*b = aux;
} 

int buscaSequencial(int *v, int n, int elem){
    int i;
    for(i=0; i<n; i++){
        comp++;
        if(v[i] == elem) 
            return i; //Elemento encontrado
    }
    return -1; //Elemento encontrado
}

int particao(int *v, int ini, int fim){
    int i = ini, j = fim;
    int pivo = v[(ini+fim)/2];
    while (1) {
        while(v[i] < pivo){ i++; } //procura algum >= pivo do lado esquerdo
        while(v[j] > pivo){ j--; } //procura algum <= pivo do lado direito
        
        if(i<j){
            troca(&v[i], &v[j]); //troca os elementos encontrados
            i++;
            j--;
        }else
            return j; //retorna o local onde foi feita a particao
    }    
}

void QuickSort(int *v, int ini, int fim){
    if(ini < fim ){
        int q = particao(v, ini, fim);
        QuickSort(v, ini, q);
        QuickSort(v, q+1, fim);
    }
}

int rec_buscaBinaria(int *v, int ini, int fim, int elem){
    if(ini > fim) return -1;
    int meio = (ini + fim)/2;
    comp++;
    if(v[meio] == elem) 
        return meio;
    else 
        if(elem < v[meio])
            return rec_buscaBinaria(v, ini, meio-1, elem);
        else
            return rec_buscaBinaria(v, meio+1, fim, elem);
}

int it_buscaBinaria(int *v, int ini, int fim, int elem){
    int meio;
    while(ini <= fim){
        meio = (ini + fim)/2;
        comp++;
        if(elem == v[meio]) return meio;
        else
            if(elem < meio)
                fim = meio-1;
            else
                ini = meio+1;
    }
    return -1;
}

int main(int argc, char **argv){

    //Atribuicoes iniciais
    srand(time(NULL));
    comp = 0;
    clock_t t;
    //1 -- sequencial, 2 -- binaria recursiva, 3-- binaria iterativa
    int escolha = atoi(argv[1]);

    int *v;
    int n, x;
    //printf("Digite o tamanho do vetor:\n");
    //scanf("%d", &n);
    n = atoi(argv[2]);

    v = (int*) malloc (n*sizeof(int));

    preencheAleatorio(v, n, 1, n);
    //imprimeVetor(v, n);
    QuickSort(v, 0, n-1);
    
    //printf("Digite um elemento para busca:\n");
    //scanf("%d", &x);
    x = atoi(argv[3]);

    int ind;

    printf("sucesso,tempo,comparacoes\n");
    if(escolha == 1){
        comp = 0;
        for(int i =0; i<n; i++){
            t = clock();
                ind = buscaSequencial(v, i, x);
                comp = comp + ind;
            t = clock() - t;
            printf("%d,%f,%d\n", ind, ((float)t)/CLOCKS_PER_SEC, comp); 
        }
    }
    
    if(escolha == 2){
        comp = 0;
        for(int i =0; i<n; i++){
            t = clock();
                ind = rec_buscaBinaria(v, 0, i-1, x);
                comp += ind;
            t = clock() - t;
            printf("%d,%f,%d\n", ind, ((float)t)/CLOCKS_PER_SEC, comp); 
        }
    }

    if(escolha == 3){
        comp = 0;
        for(int i =0; i<n; i++){
            t = clock();
                ind = it_buscaBinaria(v, 0, i-1, x);
                comp += ind;
            t = clock() - t;
            printf("%d,%f,%d\n", ind, ((float)t)/CLOCKS_PER_SEC, comp); 
        }
    }

    free(v);
    return 0;
}