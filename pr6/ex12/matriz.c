#include <stdio.h>
#include <stdlib.h>

struct matriz {
    int **data;
    int linhas;
    int colunas;
};

typedef struct matriz Matriz;

Matriz *criaMatriz(int linhas, int colunas) {
    Matriz *mat = (Matriz *)malloc(sizeof(Matriz));
    if (mat == NULL) {
        perror("Erro ao alocar a matriz");
        exit(1);
    }

    mat->linhas = linhas;
    mat->colunas = colunas;

    mat->data = (int **)malloc(linhas * sizeof(int *));
    if (mat->data == NULL) {
        perror("Erro ao alocar as linhas da matriz");
        exit(1);
    }

    for (int i = 0; i < linhas; i++) {
        mat->data[i] = (int *)malloc(colunas * sizeof(int));
        if (mat->data[i] == NULL) {
            perror("Erro ao alocar as colunas da matriz");
            exit(1);
        }
    }

    return mat;
}

void preencherMatriz(Matriz *mat, int *valores) {
    for (int i = 0; i < mat->linhas; i++) {
        for (int j = 0; j < mat->colunas; j++) {
            mat->data[i][j] = valores[i * mat->colunas + j];
        }
    }
}

void imprimirMatriz(Matriz *mat) {
    for (int i = 0; i < mat->linhas; i++) {
        for (int j = 0; j < mat->colunas; j++) {
            printf("%d ", mat->data[i][j]);
        }
        printf("\n");
    }
}

void liberarMatriz(Matriz *mat) {
    for (int i = 0; i < mat->linhas; i++) {
        free(mat->data[i]);
    }
    free(mat->data);
    free(mat);
}

Matriz* transposta(Matriz* original){
    int linhas = original->colunas;
    int colunas = original->linhas;
    
    Matriz* resultado = criaMatriz(linhas, colunas);
    
    for(int i = 0; i < original->linhas; i++) {
        for(int j = 0; j < original->colunas; j++) {
            resultado->data[j][i] = original->data[i][j];
        }
    }
    
    return resultado;
}

int main() {
    int valores[] = {1, 2, 3, 4, 5, 6};
    int linhas = 2;
    int colunas = 3;

    Matriz *minhaMatriz = criaMatriz(linhas, colunas);
    preencherMatriz(minhaMatriz, valores);

    printf("Matriz:\n");
    imprimirMatriz(minhaMatriz);

    Matriz *minhaTransposta = transposta(minhaMatriz);
    imprimirMatriz(minhaTransposta);

    liberarMatriz(minhaMatriz);
    liberarMatriz(minhaTransposta);

    return 0;
}
