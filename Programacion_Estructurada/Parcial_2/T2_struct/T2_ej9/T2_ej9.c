/*
Define una estructura typedef struct { int id; char nombre[30]; float precio; int cantidad; } Producto; Crea
un arreglo de 3 productos y una función que calcule el valor total del inventario.
*/

#include <stdio.h>

typedef struct {
    int id;
    char nombre[30];
    float precio;
    int cantidad;
} Producto;

float valorTotalInv(Producto ps[]);

int main()
{
    Producto productos[3] = {
        {1, "P1", 10.5, 20},
        {2, "P2", 5.0, 50},
        {3, "P3", 2.5, 100}
    };
    printf("Valor total del inventario: %.2f\n", valorTotalInv(productos));
    return 0;
}

float valorTotalInv(Producto ps[]){
    float pTotal = 0;
    for (int i = 0; i < 3; i++)
        pTotal += ps[i].precio * ps[i].cantidad;
    return pTotal;
}