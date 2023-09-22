#include <stdio.h>
#include <stdlib.h>


void print_crescente(int n){
    if(n == 0) return;
    else print_crescente(n-1);  
    printf("%d ", n);
}

void print_decrescente(int n){
    printf("%d ", n);
    if(n == 1) return; 
    else print_decrescente(n-1);
}

int main(int argc, char const *argv[]){

    int n = 5; //atoi(argv[1]);

    print_crescente(n);
    printf("\n");
    
    print_decrescente(n);
    printf("\n");

    return 0;
}
