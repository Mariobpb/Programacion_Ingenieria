/*
Ejercicio 22: Divisores de un número.
Realizar un programa que pida un número y diga todos sus divisores.
*/

#include <stdio.h>

int main()
{
    int num;
    printf("Ingrese un numero: ");
    scanf("%d", &num);
    printf("Divisores de %d: ", num);
    for (int i = 1; i <= num; i++)
        if (num % i == 0)
            printf("%d ", i);

    return 0;
}
