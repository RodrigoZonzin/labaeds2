#include <stdio.h>
#include <stdlib.h>

#include "matrizEstatica.h"



// Inicializa uma matriz com linhas e colunas especificadas
Matriz* criaMatriz(int linhas, int colunas){
    Matriz *matriz = (Matriz*) malloc(sizeof(Matriz));

    matriz->linhas = linhas;
    matriz->colunas = colunas;
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            matriz->data[i][j] = 0; // Pode ser outro valor padrão se preferir
        }
    }

    return matriz;
}

// Define o valor de um elemento da matriz na posição (linha, coluna)
void definirElemento(Matriz *matriz, int linha, int coluna, int valor){
    if(linha >= 0 && linha < matriz->linhas && coluna >= 0 && coluna < matriz->colunas){
        matriz->data[linha][coluna] = valor;
    } else{
        printf("Posição inválida\n");
    }
}

// Obtém o valor de um elemento da matriz na posição (linha, coluna)
int obterElemento(Matriz *matriz, int linha, int coluna){
    if(linha >= 0 && linha < matriz->linhas && coluna >= 0 && coluna < matriz->colunas){
        return matriz->data[linha][coluna];
    } else{
        printf("Posição inválida\n");
        return 0; // Pode retornar outro valor padrão se preferir
    }
}

// Imprime a matriz
void imprimirMatriz(Matriz *matriz){
    for(int i = 0; i < matriz->linhas; i++){
        for(int j = 0; j < matriz->colunas; j++){
            printf("%d ", matriz->data[i][j]);
        }
        printf("\n");
    }
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

int main(){
    Matriz *minhaMatriz = criaMatriz(3, 3);
    

    definirElemento(minhaMatriz, 0, 1, 1);
    definirElemento(minhaMatriz, 1, 1, 2);
    definirElemento(minhaMatriz, 2, 2, 3);

    imprimirMatriz(minhaMatriz);

    int valor = obterElemento(minhaMatriz, 1, 1);
    printf("Valor na posição (1, 1): %d\n", valor);

    Matriz *minhaTransposta = transposta(minhaMatriz);
    imprimirMatriz(minhaTransposta);

    return 0;
}
