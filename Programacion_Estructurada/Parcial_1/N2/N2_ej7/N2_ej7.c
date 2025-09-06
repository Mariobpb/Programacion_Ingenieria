/*
Ejercicio 7: Bucles 2.
Realizar un programa que pida al usuario un número y presente los números del 1 al
número que introdujo el usuario. Repetir este ejercicio con todos los tipos de bucles
(for, while, y do-while).
*/

#include <stdio.h>

int main()
{
    int numMax = 1, cont = 1;
    printf("Ingrese un numero: ");
    scanf("%d", &numMax);
    printf("\nfor: ");
    for (; cont <= numMax; cont++)
    {
        printf("%d ", cont);
    }
    cont = 1;
    printf("\nwhile: ");
    while (cont <= numMax)
    {
        printf("%d ", cont);
        cont++;
    }
    cont = 1;
    printf("\ndo-while: ");
    do
    {
        printf("%d ", cont);
        cont++;
    } while (cont <= numMax);

    return 0;
}