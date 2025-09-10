/*
Ejercicio 14: Función máximo divisor comunes.
Escribir el código de la función que retorne el máximo común divisor de dos números
que recibe como argumento.
*/

#include <stdio.h>

void impComunDivisores(int a, int b)
{
    int MCD;
    for (int i = a; i >= a; i++)
    {
        if ((i % a == 0) && (i % b == 0))
        {
            MCD = i;
            break;
        }
    }
    printf("El MCD de %d y %d es %d", a, b, MCD);
}

int main()
{
    int a, b;
    printf("Introduzca el primer numero:");
    scanf("%d", &a);
    printf("Introduzca el segundo numero:");
    scanf("%d", &b);
    impComunDivisores(a, b);

    return 0;
}
