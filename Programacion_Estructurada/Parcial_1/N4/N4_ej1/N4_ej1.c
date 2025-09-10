/*
Ejercicio 1: ¿Qué imprime?.
¿Qué imprime el siguiente fragmento de código? Compruébalo.
int mi_funcion(void)
{
return 3+2;
}
void main(void){
printf(“La function devuelde %d”,mi_funcion());
}
*/

#include <stdio.h>

int mi_funcion(void)
{
    return 3 + 2;
}
void main(void)
{
    printf("La function devuelde %d", mi_funcion());
}