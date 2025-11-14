/*
Crea una función typedef struct { float x, y; } Punto; Punto crearPunto(float x, float y); La función debe
devolver un punto con las coordenadas indicadas y mostrarlo desde main().
*/

#include <stdio.h>

typedef struct {
    float x, y;
} Punto;

Punto crearPunto(float x, float y);

int main()
{
    Punto p = crearPunto(3.5, 4.2);
    printf("Punto creado: (%.2f, %.2f)\n", p.x, p.y);
    return 0;
}
Punto crearPunto(float x, float y){
    Punto p;
    p.x = x;
    p.y = y;
    return p;
}