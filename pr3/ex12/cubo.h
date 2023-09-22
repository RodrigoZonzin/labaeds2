#define _CUBO_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct cubo{
    int lado; 
    int altura;
    int profundidade; 
};

typedef struct cubo Cubo; 

Cubo* cria_cubo(int);
double area_cubo(Cubo*);
double volume_cubo(Cubo*);