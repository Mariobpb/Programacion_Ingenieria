/*
Ejercicio 13: Bucles con if 1.
Realizar un programa que pida al usuario dos números y presente los números impares
que hay desde el primer número al segundo que introdujo el usuario.
*/

#include <stdio.h>

int main()
{
    int numMin, numMax;
    printf("Ingrese el numero inicial: ");
    scanf("%d", &numMin);
    printf("Ingrese el numero final: ");
    scanf("%d", &numMax);

    printf("Numeros impares: ");
    for (int i = numMin; i <= numMax; i++)
    {
        if ((i % 2 == 1) || (i % 2 == -1))
            printf("%d ", i);
    }

    return 0;
}