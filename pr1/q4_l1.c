#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


double _delta(int b, int a, int c){
    return (pow(b,2) - 4*a*c);
}

void bhaskara(int a, int b, int c, double *x1, double *x2){
    int delta = _delta(b,a,c);

    if(delta<0) exit(1);
    if(delta == 0.0){
        *x1 = (double)(-b + pow(delta, 0.5) ) / (2*a);
        *x1 = *x2;
    }
    
    if(delta > 0){
        *x1 = (double)(-b + pow(delta, 0.5) ) / (2*a);
        *x2 = (double)(-b - pow(delta, 0.5) ) / (2*a);
    }
}

int main(int argc, char **argv){
    double *x1 = (double*)malloc(sizeof(double));
    double *x2 = (double*)malloc(sizeof(double));


    int a = atoi(argv[1]),
        b = atoi(argv[2]),
        c = atoi(argv[3]);

    bhaskara(a, b, c, x1, x2);

    printf("x1 = %.2lf\nx2 = %.2lf\n", *x1, *x2);

    return 0;
}