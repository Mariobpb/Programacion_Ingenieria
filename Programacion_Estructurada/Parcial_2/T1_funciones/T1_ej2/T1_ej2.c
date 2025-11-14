/*
Escribe una función llamada sumar() que reciba dos números enteros como parámetros y muestre su
suma en pantalla.
*/

#include <stdio.h>

void sumar(int, int);

int main()
{
    sumar(5, 7);
    return 0;
}

void sumar(int a, int b)
{
    int suma = a + b;
    printf("%d + %d = %d\n", a, b, suma);
}