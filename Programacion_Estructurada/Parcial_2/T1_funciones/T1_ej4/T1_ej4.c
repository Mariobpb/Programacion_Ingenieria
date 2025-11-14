/*
Crea una función cuadrado(int n) que devuelva el cuadrado del número ingresado. Ejemplo: si
ingresas 5, debe retornar 25.
*/

#include <stdio.h>

int cuadrado(int);

int main()
{
    printf("5 al cuadrado es: %d\n", cuadrado(5));
    return 0;
}

int cuadrado(int n)
{
    return n * n;   
}