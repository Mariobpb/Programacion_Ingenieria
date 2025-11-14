/*
Crea una función llamada saludo() que no reciba parámetros ni retorne valores, y que muestre en
pantalla: ¡Hola, mundo desde una función!
*/

#include <stdio.h>

void saludo();

int main()
{
    saludo();
    return 0;
}

void saludo()
{
    printf("¡Hola, mundo desde una función!\n");
}