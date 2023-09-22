#include "CatalogoProduto.h"
#include <string.h>

CatalogoProdutos* criarCatalogo(){
    CatalogoProdutos *cat = (CatalogoProdutos*)malloc(sizeof(CatalogoProdutos));

    cat->n = 0;
    return cat;
}

void adicionarProduto(CatalogoProdutos *c, char *nome, double preco, int quantidade){
    strcpy(c->itens[c->n].nome, nome);
    c->itens[c->n].preco  = preco;
    c->itens[c->n].quantidade = quantidade;
    
    (c->n)++; 
}
int verificarEstoque(CatalogoProdutos *c, char *nome){
    for(int i = 0; i< c->n; i++){
        if(!strcmp(c->itens[i].nome, nome)){ 
            return c->itens[i].quantidade;
        }
    }

    return -1;
}
void imprimirCatalogo(CatalogoProdutos *c){
    for(int  i =0; i<c->n; i++){
        printf("%s\n", c->itens[i].nome); 
        printf("%.2lf\n", c->itens[i].preco); 
        printf("%d\n", c->itens[i].quantidade); 

        printf("\n");
    }
}


int main(){
    CatalogoProdutos *c = criarCatalogo();
    imprimirCatalogo(c);

    adicionarProduto(c, "COMPUTADOR", 2000.50, 3); 
    adicionarProduto(c, "CELULAR", 1500.00, 2); 
    adicionarProduto(c, "TV", 4000.00, 1); 

    imprimirCatalogo(c); 

    printf("ESTOQUE: %d\n", verificarEstoque(c, "CELULAR"));
    return 0;
}