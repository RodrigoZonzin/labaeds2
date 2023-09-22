#include "cubo.h"


int main(int argc, char **argv){
    double a = atof(argv[1]);
    Cubo *c = cria_cubo(a);

    printf("Area: %.4lf unidades quadradas\n", area_cubo(c));
    printf("Volume: %.4lf unidades cubicas\n", volume_cubo(c));

    return 0; 
}