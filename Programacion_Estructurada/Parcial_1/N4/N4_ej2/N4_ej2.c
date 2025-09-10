/*
Ejercicio 2: ¿Qué imprime?.
¿Qué imprime el siguiente fragmento de código? Compruébalo.
int mi_funcion(int x)
{
return x*x;
}
void main(void){
printf(“La function devuelde %d”,mi_funcion(5));
}
*/

#include <stdio.h>

int mi_funcion(int x)
{
    return x * x;
}
void main(void)
{
    printf("La function devuelde %d", mi_funcion(5));
}