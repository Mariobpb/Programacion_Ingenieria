/*
Ejercicio 9: Condición if 1.
Realizar un programa que pida al usuario dos números y diga cuál es el mayor y cuál el
menor.
*/

#include <stdio.h>

int main()
{
    int num1, num2;
    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);
    if (num1 < num2)
        printf("%d < %d", num1, num2);
    else if (num1 > num2)
        printf("%d > %d", num1, num2);
    else
        printf("%d = %d", num1, num2);

    return 0;
}