/*
Ejercicio 2: C�lculo de �rea y per�metro

Escribe un programa que pregunte al usuario los dos lados de un rect�ngulo y presente por pantalla el
c�lculo del per�metro (suma de los lados) y el �rea (base por altura).
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

    printf("El �rea del rect�ngulo es de : %.3f unidades cuadradas", area);

    return 0;
}
