/*
Ejercicio 21: Potencias.
Realizar un programa que pida la base y el exponente y calcule la potencia.
*/

#include <stdio.h>

int main()
{
    int base, exponente, res;
    printf("Ingrese la base: ");
    scanf("%d", &base);
    printf("Ingrese el exponente: ");
    scanf("%d", &exponente);
    res = 1;
    for (int i = 0; i < exponente; i++)
        res *= base;
    printf("%d^%d = %d", base, exponente, res);

    return 0;
}
