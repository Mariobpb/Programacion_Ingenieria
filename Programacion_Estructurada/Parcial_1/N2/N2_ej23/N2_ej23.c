/*
Ejercicio 23: Divisores comunes de dos números.
Realizar un programa que pida dos números y diga sus divisores comunes.
*/

#include <stdio.h>

int main()
{
    int num1, num2;
    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);

    printf("Divisores en comun de %d y %d: ", num1, num2);
    for (int i = 1; i <= num1; i++)
        if ((num1 % i == 0) && (num2 % i == 0))
            printf("%d ", i);

    return 0;
}
