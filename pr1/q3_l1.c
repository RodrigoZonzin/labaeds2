#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno{
    char nome[20]; 
    char matricula[10]; 
    float nota; 
};
typedef struct aluno Aluno;

void construtor(Aluno*, char*, char*, float);
void imprime_aluno(Aluno*);
void pesquisa_max_min(Aluno**, int);

int main(){
    Aluno **va = (Aluno**)malloc(sizeof(Aluno)*3);
    va[0] = (Aluno*)malloc(sizeof(Aluno));
    construtor(va[0], "Rodrigo", "212050002", 1.0);

    va[1] = (Aluno*)malloc(sizeof(Aluno));
    construtor(va[1], "Adelson", "212050019", 0.5);

    va[2] = (Aluno*)malloc(sizeof(Aluno));
    construtor(va[2], "Perozzo", "te_amo", 05.072022);

    pesquisa_max_min(va, 3);

    free(va[2]);
    free(va[1]);
    free(va[0]);
    free(va);
    return 0; 
}

void construtor(Aluno *a, char*nome, char*matricula, float nota){
    strcpy(a->nome,nome);
    strcpy(a->matricula, matricula);
    a->nota = nota;
}

void imprime_aluno(Aluno* a){
    printf("Nome: %s\n", a->nome);
    printf("Matricula: %s\n", a->matricula);
    printf("Nota: %.2f\n\n", a->nota);
}

void pesquisa_max_min(Aluno **va, int n){
    float maior = va[0]->nota,
          menor = va[0]->nota; 

    int maxi = 0,
        mini = 0; 

    for(int i = 0; i<n; i++){
        if(va[i]->nota >= maior){
            maior = va[i]->nota;
            maxi = i;
        }

        if(va[i]->nota <= menor){
            menor = va[i]->nota;
            mini = i;
        }
    }

    printf("Maior: \n");
    imprime_aluno(va[maxi]);
    printf("Menor: \n");
    imprime_aluno(va[mini]);
}

