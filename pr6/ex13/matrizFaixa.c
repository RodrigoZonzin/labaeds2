#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura da Matriz de Faixa (Tridiagonal)
typedef struct {
    int n;          // Dimensão da matriz
    int* diag;      // Elementos da diagonal principal
    int* sup;       // Elementos da superdiagonal (acima da diagonal principal)
    int* sub;       // Elementos da subdiagonal (abaixo da diagonal principal)
} TridiagonalMatrix;

// Função para inicializar uma Matriz de Faixa
TridiagonalMatrix* createTridiagonalMatrix(int n) {
    TridiagonalMatrix* mat = (TridiagonalMatrix*)malloc(sizeof(TridiagonalMatrix));
    if (mat == NULL) {
        perror("Erro ao alocar memória para a matriz");
        exit(1);
    }
    
    mat->n = n;
    mat->diag = (int*)malloc(n * sizeof(int));
    mat->sup = (int*)malloc((n - 1) * sizeof(int));
    mat->sub = (int*)malloc((n - 1) * sizeof(int));
    
    if (mat->diag == NULL || mat->sup == NULL || mat->sub == NULL) {
        perror("Erro ao alocar memória para os elementos da matriz");
        exit(1);
    }
    
    return mat;
}

// Função para definir um elemento na matriz
void setElement(TridiagonalMatrix* mat, int i, int j, int value) {
    if (i < 0 || i >= mat->n || j < 0 || j >= mat->n) {
        fprintf(stderr, "Índices fora dos limites da matriz\n");
        exit(1);
    }
    
    if (i == j) {
        mat->diag[i] = value;
    } else if (i == j - 1) {
        mat->sup[i] = value;
    } else if (i == j + 1) {
        mat->sub[j] = value;
    } else {
        fprintf(stderr, "Elemento fora da banda tridiagonal\n");
        exit(1);
    }
}

// Função para obter um elemento da matriz
int getElement(const TridiagonalMatrix* mat, int i, int j) {
    if (i < 0 || i >= mat->n || j < 0 || j >= mat->n) {
        fprintf(stderr, "Índices fora dos limites da matriz\n");
        exit(1);
    }
    
    if (i == j) {
        return mat->diag[i];
    } else if (i == j - 1) {
        return mat->sup[i];
    } else if (i == j + 1) {
        return mat->sub[j];
    } else {
        return 0;  // Elementos fora da banda tridiagonal são zeros
    }
}

void imprimeVetoresMatrix(TridiagonalMatrix* mat){
    printf("Diagonal: ");
    for (int i = 0; i < mat->n; i++) {
        printf("%d ", mat->diag[i]);
    }
    printf("\n");
    
    printf("Superdiagonal: ");
    for (int i = 0; i < mat->n - 1; i++) {
        printf("%d ", mat->sup[i]);
    }
    printf("\n");
    
    printf("Subdiagonal: ");
    for (int i = 0; i < mat->n - 1; i++) {
        printf("%d ", mat->sub[i]);
    }
    printf("\n");
}

// Função para liberar a memória da matriz
void freeTridiagonalMatrix(TridiagonalMatrix* mat) {
    free(mat->diag);
    free(mat->sup);
    free(mat->sub);
    free(mat);
}

int main() {
    int n = 5;
    TridiagonalMatrix* mat = createTridiagonalMatrix(n);
    
    // Preencher a matriz com alguns valores de exemplo
    for (int i = 0; i < n; i++) {
        setElement(mat, i, i, 2);
    }
    for (int i = 0; i < n - 1; i++) {
        setElement(mat, i, i + 1, 1);
        setElement(mat, i + 1, i, 1);
    }
    
    imprimeVetoresMatrix(mat);
    
    // Liberar a memória da matriz
    freeTridiagonalMatrix(mat);
    
    return 0;
}
