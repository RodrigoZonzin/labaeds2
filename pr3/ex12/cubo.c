#include "cubo.h"

Cubo* cria_cubo(int lado){
    Cubo *c = (Cubo*)malloc(sizeof(Cubo));

    c->lado = lado;
    return c;
}

double area_cubo(Cubo *c){
    return (6*pow(c->lado,2));
}

double volume_cubo(Cubo *c){
    return pow(c->lado, 3);
}

