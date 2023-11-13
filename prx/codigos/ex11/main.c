#include <stdio.h>
#include <stdlib.h>
#include "ex11.h"

#include <stdio.h>
#include <stdlib.h>

// Assuming AVL and other function declarations here

int main() {
    int *cont = (int*)malloc(sizeof(int));
    int escolha, elem, busca;
    AVL *avl;
    printf("O que deseja fazer?\n1 - Criar AVL\n2 - Inserir um elemento\n"
        "3 - Buscar um elemento\n4 - Remover um elemento\n5 - Imprimir a AVL em ordem"
        "\n6 - Mostrar a quantidade de nos na AVL\n7 - Destruir a AVL\n8 - Sair\n");

    scanf("%d", &escolha);

    while (escolha != 8) {
        if (escolha == 1) {
            avl = criaAVL();
            printf("Arvore criada!");
            aguardaLimpa();
        } else if (escolha == 2) {
            printf("Digite o elemento que deseja inserir: ");
            scanf("%d", &elem);
            insereElem(avl, elem);
            aguardaLimpa();
        } else if (escolha == 3) {
            printf("Digite o elemento que deseja consultar: ");
            scanf("%d", &elem);
            busca = pesquisa(avl, elem);
            if (busca == 1)
                printf("O numero esta na arvore!");
            else
                printf("O numero nao esta na arvore!");
            aguardaLimpa();
        } else if (escolha == 4) {
            printf("Digite o elemento que deseja remover: ");
            scanf("%d", &elem);
            removeElem(avl, elem);
            aguardaLimpa();
        } else if (escolha == 5) {
            imprime(avl);
            aguardaLimpa();
        } else if (escolha == 6) {
            *cont = 0;
            contador(*avl, 0, cont);
            printf("O numero de nos eh: %d!", *cont);
            aguardaLimpa();
        } else if (escolha == 7) {
            destroiAVL(avl);
            printf("Arvore destruida!");
            aguardaLimpa();
        } else {
            printf("\nErro!\n\n");
        }

        printf("O que deseja fazer?\n1 - Criar AVL\n2 - Inserir um elemento\n"
            "3 - Buscar um elemento\n4 - Remover um elemento\n5 - Imprimir a AVL em ordem"
            "\n6 - Quantidade de nos na AVL\n7 - Destruir a AVL\n8 - Sair\n");

        scanf("%d", &escolha);
    }

    free(cont);  // Free the allocated memory

    return 0;
}
