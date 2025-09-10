/*
Ejercicio 3: ¿Qué imprime?.
¿Qué imprime el siguiente fragmento de código? Compruébalo.
int mi_funcion(int x)
{
int y;
y=2+x*3;
return y;
}
void main(void){
printf(“La function devuelde %d”,mi_funcion(5+2));
}
*/

#include <stdio.h>

int mi_funcion(int x)
{
    int y;
    y = 2 + x * 3;
    return y;
}
void main(void)
{
    printf("La function devuelde %d", mi_funcion(5 + 2));
}