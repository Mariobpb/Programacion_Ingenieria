/*
Ejercicio 13: Función divisores comunes.
Escribir el código de la función que imprima por pantalla todos los divisores comunes
de dos números que recibe como argumento.
*/

#include <stdio.h>

void impComunDivisores(int a, int b)
{
    printf("Los comun divisores de %d y %d son: ", a, b);
    for (int i = 1; i <= a; i++)
    {
        if ((a % i == 0) && (b % i == 0))
            printf("%d ", i);
    }
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
