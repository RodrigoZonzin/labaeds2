#ifndef LDE_H
#define LDE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int info;
    struct NO* prox;
    struct NO* ant;
}NO;

typedef struct NO* Lista;

Lista* criaLista(){
    Lista *li;
    li = (Lista*) malloc (sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

int listaVazia(Lista *li){
    if(li == NULL) return 1;
    if(*li == NULL) return 1;//True - Vazia!
    return 0;//False - tem elemento!
}

NO* alocarNO(){
    return (NO*) malloc (sizeof(NO));
}

void liberarNO(NO* q){
    free(q);
}

int insereIni(Lista* li, int elem){
    if(li == NULL) return 0;
    NO* novo = alocarNO();
    if(novo == NULL) return 0;
    novo->info = elem;
    novo->prox = *li;
    novo->ant = NULL;
    if(!listaVazia(li))
        (*li)->ant = novo;
    *li = novo;
    return 1;
}

int insereFim(Lista* li, int elem){
    if(li == NULL) return 0;
    NO* novo = alocarNO();
    if(novo == NULL) return 0;
    novo->info = elem;
    novo->prox = NULL;
    if(listaVazia(li)){
        novo->ant = NULL;
        *li = novo;
    }else{
        NO* aux = *li;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
        novo->ant = aux;
    }
    return 1;
}

int removeIni(Lista *li){
    if(li == NULL) return 0;
    if(listaVazia(li)) return 0;
    NO* aux = *li;
    *li = aux->prox;
    if(aux->prox != NULL)
        aux->prox->ant = NULL;
    liberarNO(aux);
    return 1;
}

int removeFim(Lista *li){
    if(li == NULL) return 0;
    if(listaVazia(li)) return 0;
    NO* aux = *li;
    while(aux->prox != NULL)
        aux = aux->prox;
    if(aux->ant == NULL)
        *li = aux->prox;
    else
        aux->ant->prox = NULL;
    liberarNO(aux);
    return 1;
}

void imprimeLista(Lista* li){
    if(li == NULL) return;
    if(listaVazia(li)){
        printf("Lista Vazia!\n");
        return;
    }
    printf("Elementos:\n");
    NO* aux = *li;
    while(aux != NULL){
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}

void destroiLista(Lista* li){
    if(li != NULL){
        NO* aux;
        while((*li) != NULL){
            aux = *li;
            *li = (*li)->prox;
            //printf("Destruindo.. %d\n", aux->info);
            liberarNO(aux);
        }
        free(li);
    }
}


int procura(Lista* lista, int x){
    NO* atual = *lista; 

    while(atual != NULL){
        if (atual->info == x){
            return 1; 
        }
        atual = atual->prox; 
    }

    return 0; 
}

int tamanho(Lista* lista){
    int tamanho = 0;
    NO* atual = *lista;

    while(atual != NULL){
        tamanho++;
        atual = atual->prox; 
    }

    return tamanho;
}

void inserirOrdenado(Lista* lista, int x){
    NO* novoNo = alocarNO();
    novoNo->info = x; 

    if(*lista == NULL){
        novoNo->prox = NULL;
        novoNo->ant = NULL;
        *lista = novoNo;
    } 
    else if(x <= (*lista)->info){
        novoNo->prox = *lista;
        novoNo->ant = NULL;
        (*lista)->ant = novoNo;
        *lista = novoNo;
    } 
    else{
        NO* atual = *lista;

        while(atual->prox != NULL && atual->prox->info < x){
            atual = atual->prox;
        }

        novoNo->prox = atual->prox;
        novoNo->ant = atual;
        
        if(atual->prox != NULL){
            atual->prox->ant = novoNo;
        }
        
        atual->prox = novoNo;
    }
}

void removerElemento(Lista* lista, int valor) {
    if (*lista == NULL) return;

    NO* atual = *lista;

    if(atual->info == valor){
        *lista = atual->prox; 
        if(*lista != NULL){
            (*lista)->ant = NULL;
        }
        free(atual); 
        return;
    }

    while(atual != NULL && atual->info != valor){
        atual = atual->prox;
    }

    if(atual == NULL) return;
    if(atual->ant != NULL) atual->ant->prox = atual->prox;
    if(atual->prox != NULL) atual->prox->ant = atual->ant;

    free(atual); 
}



#endif
