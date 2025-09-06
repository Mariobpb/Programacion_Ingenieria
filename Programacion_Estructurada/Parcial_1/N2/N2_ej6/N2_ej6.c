/*
Ejercicio 6: Bucles 1.
Realizar un programa que imprima los números del 1 al 57. Repetir este ejercicio con
todos los tipos de bucles (for, while, y do-while).
*/

#include <stdio.h>

int main()
{
    int cont = 1;
    printf("\nfor: ");
    for(; cont <= 57; cont++){
        printf("%d ", cont);
    }
    cont = 1;
    printf("\nwhile: ");
    while (cont <= 57)
    {
        printf("%d ", cont);
        cont++;
    }
    cont = 1;
    printf("\ndo-while: ");
    do{
        printf("%d ", cont);
        cont++;
    }while (cont <= 57);
    
    return 0;
}