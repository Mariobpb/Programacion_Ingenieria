/*
Ejercicio 2: Cálculo de área y perímetro

Escribe un programa que pregunte al usuario los dos lados de un rectángulo y presente por pantalla el
cálculo del perímetro (suma de los lados) y el área (base por altura).
*/

#include <stdio.h>

int main() {
    float width = 0;
    float height = 0;

    do {
        printf("Ingresa el ancho del rectángulo: ");
        scanf("%f", &width);
        printf("Ancho: %f \n", width);
    }while(width <= 0);

    do {
        printf("Ingresa la altura del rectángulo: ");
        scanf("%f", &height);
    }while(height <= 0);

    float area = width * height;

    printf("El área del rectángulo es de : %.3f unidades cuadradas", area);

    return 0;
}
