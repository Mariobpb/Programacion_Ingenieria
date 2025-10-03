/*
Ejercicio 16: Bucles con if 4.
Realizar un programa que pida que se dos números consecutivos (3 y 4; 9 y 10 etc.).
Cuando se introducen tres números consecutivos dice “gracias” y termina. Mientras no se
introduzcan tres números consecutivos el programa sigue pidiendo números indefinidamente.
*/

#include <stdio.h>

int main()
{
    int num1, num2, num3;
    do
    {
        printf("Ingrese primer numero: ");
        scanf("%d", &num1);
        printf("Ingrese segundo numero: ");
        scanf("%d", &num2);
    } while (!(num2 == num1 + 1));
    printf("Gracias");

    return 0;
}
