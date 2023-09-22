#include "contaBancaria.h"

int main(){
    ContaBancaria *c = criarConta(1, "Rodrigo Zonzin");
    imprimirInfo(c);

    depositar(c, 1000.05);
    imprimirInfo(c);

    sacar(c, 2.0333); 
    imprimirInfo(c);
}