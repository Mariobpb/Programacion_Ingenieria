/*
Ejercicio 3: Cambio de dólares a euros

Suponiendo que 1 euro = 1.332505 dólares. Escribe un programa que pida al usuario un número de dólares y calcule el cambio en euros.
*/

#include <stdio.h>

int main() {
    float dollars = 0;
    float euros = 0;

    printf("Ingrese la cantidad de dolares a convertir: ");
    scanf("%f", &dollars);

    euros = dollars / 1.332505;

    printf("Se conviertieron %.2f: dólares a %.2f euros", dollars, euros);

    return 0;
}
