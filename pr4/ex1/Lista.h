/*----------------- File: Lista.h ----------------------+
|Lista Sequencial Estatica                              |
|					      		                        |
|					      		                        |
| Implementado por Guilherme C. Pena em 12/09/2023      |
+-------------------------------------------------------+ */
#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct{
    int qtd;
    int dados[MAX];
}Lista;

Lista* criaLista(){
    Lista* li;
    li = (Lista*) malloc (sizeof(Lista));
    if(li != NULL)
        li->qtd = 0;
    return li;
}

void destroiLista(Lista *li){
    if(li != NULL)
        free(li);
}

int tamanhoLista(Lista *li){
    if(li == NULL)
        return -1;
    return li->qtd;
}

int listaCheia(Lista *li){
    if(li == NULL)
        return -1;
    return (li->qtd == MAX);
}

int listaVazia(Lista *li){
    if(li == NULL)
        return -1;
    return (li->qtd == 0);
}

int insereFim(Lista* li, int elem){
    if(li == NULL) return 0;
    if(!listaCheia(li)){
        li->dados[li->qtd] = elem;
        li->qtd++;
        return 1;
    }else{
        return 0;
    }
}

int insereIni(Lista* li, int elem){
    if(li == NULL) return 0;
    if(!listaCheia(li)){
        int i;
        for(i=li->qtd; i>0; i--){
            li->dados[i] = li->dados[i-1];
        }
        li->dados[0] = elem;
        li->qtd++;
        return 1;
    }else{
        return 0;
    }
}

int imprimeLista(Lista *li){
    if(li == NULL) return 0;
    int i;
    printf("Elementos:\n");
    for(i=0; i<li->qtd; i++){
        printf("%d ", li->dados[i]);
    }
    printf("\n");
    return 1;
}

int removeFim(Lista* li){
    if(li == NULL) return 0;
    if(!listaVazia(li)){
        li->qtd--;
        return 1;
    }else return 0;
}

int removeIni(Lista *li){
    if(li == NULL ) return 0;
    if(!listaVazia(li)){
        int i;
        for(i=0; i<li->qtd-1; i++)
            li->dados[i] = li->dados[i+1];
        li->qtd--;
        return 1;
    } else{
        return 0;
    }
}

int Procura(Lista *li, int x){
    for(int i = 0; i<= li->qtd; i++){
        if(li->dados[i] == x) return i;
    }

    return -1;
}

int comparador(const void *a, const void *b){
   return (*(int*)a - *(int*)b);
}

int novoInsere(Lista* li, int elem){
    if(li == NULL) return 0;
    if(!listaCheia(li)){
        li->dados[li->qtd] = elem;
        li->qtd++;

        qsort(li->dados, li->qtd, sizeof(int), comparador);
        return 1;
    }
    else return 0;
}

void removeLi(Lista *li, int item) {
    for(int i = 0; i < li->qtd; i++){
        if(li->dados[i] == item){
            if (i < li->qtd - 1){
                for (int j = i; j < li->qtd - 1; j++){
                    li->dados[j] = li->dados[j + 1];
                }
            }
            li->qtd--;
            return;
        }
    }
}


#endif
