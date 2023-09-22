#define CATALOGOPRODUTO_H

#include <stdio.h>
#include <stdlib.h>

#include "Produto.h"

struct catalogoProdutos_t{
    int n; 
    Produto itens[100];
};

typedef struct catalogoProdutos_t CatalogoProdutos;


CatalogoProdutos* criarCatalogo();
void adicionarProduto(CatalogoProdutos*, char*, double, int);  
int verificarEstoque(CatalogoProdutos*, char*); 
void imprimirCatalogo(CatalogoProdutos *c); 