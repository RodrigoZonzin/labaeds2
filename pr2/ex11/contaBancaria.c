#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "contaBancaria.h"


ContaBancaria* criarConta(int num, char *titular){
    ContaBancaria *c = (ContaBancaria*)malloc(sizeof(ContaBancaria)*1);

    strcpy(c->nome_titular, titular);
    c->num_conta = num;
    c->saldo = 0.00;

    return c;
}

void depositar(ContaBancaria *c, double valor){
    c->saldo = c->saldo + valor; 
}

void sacar(ContaBancaria *c, double valor){
    if(c->saldo < valor) printf("VALOR INSUFICIENTE PARA SALDO!\n");
    else{
        c->saldo = c->saldo - valor; ;
    }

}

double consultarSaldo(ContaBancaria *c){
    return c->saldo;
} 

void imprimirInfo(ContaBancaria *c){
    printf("TITULAR: %s\n", c->nome_titular);
    printf("NUMERO DA CONTA: %d\n", c->num_conta);
    printf("SALDO: %.2lf\n", c->saldo);
    printf("\n");
}



