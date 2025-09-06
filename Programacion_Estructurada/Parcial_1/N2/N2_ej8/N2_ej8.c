/*
Ejercicio 8: Bucles 3.
Realizar un programa que pida al usuario dos números y presente los números del
primero número al segundo que introdujo el usuario. Repetir este ejercicio con todos los
tipos de bucles (for, while, y do-while).
*/

#include <stdio.h>

int main()
{
    int numMin = 1, numMax = 1, cont = 1;
    printf("Ingrese el numero inicial: ");
    scanf("%d", &numMin);
    printf("Ingrese el numero final: ");
    scanf("%d", &numMax);
    printf("\nfor: ");
    cont = numMin;
    for (; cont <= numMax; cont++)
    {
        printf("%d ", cont);
    }
    cont = numMin;
    printf("\nwhile: ");
    while (cont <= numMax)
    {
        printf("%d ", cont);
        cont++;
    }
    cont = numMin;
    printf("\ndo-while: ");
    do
    {
        printf("%d ", cont);
        cont++;
    } while (cont <= numMax);

    return 0;
}