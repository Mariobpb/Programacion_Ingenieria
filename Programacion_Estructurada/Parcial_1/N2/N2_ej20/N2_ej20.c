/*
Ejercicio 20: Factorial.
Realizar un programa que pida un número y calcule su factorial.
*/

#include <stdio.h>

int main()
{
    int num, res = 1;
    printf("Ingrese un numero: ");
    scanf("%d", &num);
    if (num < 0)
        printf("Imposible calcular factorial");
    else
    {
        for (int i = 1; i <= num; i++)
            res *= i;
        printf("%d! = %d", num, res);
    }

    return 0;
}
