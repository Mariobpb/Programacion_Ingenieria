/*
Modifica el ejercicio anterior para que la función sumar() retorne el resultado en lugar de imprimirlo.
Muestra el resultado desde main().
*/

#include <stdio.h>

int sumar(int, int);

int main()
{
    int r = sumar(5, 7);
    printf("La suma es: %d\n", r);
    return 0;
}

int sumar(int a, int b)
{
    return a + b;
}