#ifndef _CONTABANCARIA_H
#define _CONTABANCARIA_H

struct contaBancaria_t{
    int num_conta;
    double saldo; 
    char nome_titular[20]; 
};
typedef struct contaBancaria_t ContaBancaria; 


ContaBancaria* criarConta(int, char*); 
void depositar(ContaBancaria*, double); 
void sacar(ContaBancaria*, double);
double consultarSaldo(ContaBancaria*); 
void imprimirInfo(ContaBancaria*); 

#endif