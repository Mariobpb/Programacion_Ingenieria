/*
Ejercicio 3: Cambio de d�lares a euros

Suponiendo que 1 euro = 1.332505 d�lares. Escribe un programa que pida al usuario un n�mero de d�lares y calcule el cambio en euros.
*/

#include <stdio.h>

int main() {
    float dollars = 0;
    float euros = 0;

    printf("Ingrese la cantidad de dolares a convertir: ");
    scanf("%f", &dollars);

    euros = dollars / 1.332505;

    printf("Se conviertieron %.2f: d�lares a %.2f euros", dollars, euros);

    return 0;
}
