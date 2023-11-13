#include <stdio.h>
#include <stdlib.h>
#include "ex12.h"
#include <string.h>

int main() {
    int *cont = (int*)malloc(sizeof(int));
    int escolha, ano_contratacao, busca;
    double salario;    
    char* nome = (char*)malloc(30 * sizeof(char));
    AVL avl = NULL;

    printf("O que deseja fazer?\n1 - Criar AVL\n2 - Inserir um salario do funcionario\n"
           "3 - Buscar um funcionario\n4 - Remover um funcionario\n5 - Imprimir a AVL em ordem"
           "\n6 - Imprimir as informacoes do Funcionario com o maior salario\n"
           "7 - Imprimir as informacoes do Funcionario com o menor salario\n8 - Destruir a AVL\n9 - Sair\n");

    while (1) {
        scanf("%d", &escolha);

        if (escolha == 9) {
            break;
        }

        if (escolha == 1) {
            if (avl == NULL) {
                avl = criaAVL();
                printf("Arvore criada!\n");
            } else {
                printf("A arvore ja foi criada!\n");
            }
            aguardaLimpa();
        } else if (escolha == 2) {
            if (avl == NULL) {
                printf("Crie a arvore AVL antes de inserir um funcionario!\n");
            } else {
                printf("Digite o salario, o nome e o ano de contratacao do Funcionario que deseja inserir: ");
                scanf("%lf", &salario);
                getchar();
                fgets(nome, 30, stdin);
                nome[strcspn(nome, "\n")] = '\0'; 
                scanf("%d", &ano_contratacao);
                
                insereElem(avl, salario, nome, ano_contratacao);
                aguardaLimpa();
            }
        } else if (escolha == 3) {
            if (avl == NULL) {
                printf("Crie a arvore AVL antes de buscar um funcionario!\n");
            } else {
                printf("Digite o salario do funcionario que deseja consultar: ");
                scanf("%lf", &salario);
                busca = pesquisa(avl, salario);
                if (busca == 1)
                    printf("O funcionario esta na arvore!\n");
                else
                    printf("O funcionario nao esta na arvore!\n"); 
                aguardaLimpa();
            }
        } else if (escolha == 4) {
            if (avl == NULL) {
                printf("Crie a arvore AVL antes de remover um funcionario!\n");
            } else {
                printf("Digite o salario do funcionario que deseja remover: ");
                scanf("%lf", &salario);
                removeElem(avl, salario);
                aguardaLimpa();
            }
        } else if (escolha == 5) {
            if (avl == NULL) {
                printf("Crie a arvore AVL antes de imprimir!\n");
            } else {
                imprime(avl);
                aguardaLimpa();
            }
        } else if (escolha == 6) {
            if (avl == NULL) {
                printf("Crie a arvore AVL antes de imprimir!\n");
            } else {
                Funcionario func = maior(avl);
                printf("O funcionario de maior salario eh:%s\nSeu salario eh de %.2lf\n"
                "Ele entrou no ano %d\n", func.nome,func.salario,func.anoContratacao);
                aguardaLimpa();
            }
        } else if (escolha == 7) {
            if (avl == NULL) {
                printf("Crie a arvore AVL antes de imprimir!\n");
            } else {
                Funcionario func = menor(avl);
                printf("O funcionario de menor salario eh:%s\nSeu salario eh de %.2lf\n"
                "Ele entrou no ano %d", func.nome,func.salario,func.anoContratacao);
                aguardaLimpa();
            }
        } else if (escolha == 8) {
            if (avl != NULL) {
                destroiAVL(avl);
                printf("arvore destruida!\n");
            } else {
                printf("A arvore ja foi destruida ou ainda nao foi criada!\n");
            }
            aguardaLimpa();
        } else {
            printf("\nOpcao invalida!\n\n");
        }
    }

    free(cont);
    free(nome);
    
    return 0;
}
