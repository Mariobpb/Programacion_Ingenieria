/*
Ejercicio 24: Máximo común divisor.
Realizar un programa que pida dos números y diga su máximo común divisor.
*/

#include <stdio.h>

int main()
{
    int num1, num2, cont, MCD = 0;
    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);

    cont = num1;
    while (MCD == 0)
    {
        if ((cont % num1 == 0) && (cont % num2 == 0))
            MCD = cont;
        cont++;
    }
    printf("MCD de %d y %d: %d", num1, num2, MCD);

    return 0;
}