/*
Ejercicio 15: Bucles con if 3.
Realizar un programa que pida que se pulse la letra “C” si se pulsa cualquier otra tecla
que no sea la “C”, dice “letra incorrecta” y vulva a pedir que se pulse la letra “C”. Cuando se
pulsa la tecla “C” el programa dice “gracias” y termina.
*/

#include <stdio.h>

int main()
{
    int terminar = 0;
    char letra;
    do
    {
        printf("\nIngrese la letra 'C': ");
        scanf(" %c", &letra);
        if (letra != 'C')
            printf("Letra incorrecta");
        else
            terminar = 1;
    } while (!terminar);

    return 0;
}
