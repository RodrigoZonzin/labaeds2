#define _CUBO_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct cubo{
    double lado; 
};

typedef struct cubo Cubo; 

Cubo* cria_cubo(double);
double area_cubo(Cubo*);
double volume_cubo(Cubo*);