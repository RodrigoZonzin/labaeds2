#include <stdlib.h>
#include <stdio.h>

int mul(int x, int y){
    if(y <= 0) return 0; 

    return x+mul(x, y-1);
}


int main(){
    printf("%d \n", mul(10, 4));



    return 0;
}