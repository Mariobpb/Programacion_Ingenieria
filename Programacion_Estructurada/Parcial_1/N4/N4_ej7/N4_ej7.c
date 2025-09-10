/*
Ejercicio 7: ¿Qué imprime?.
¿Qué imprime el siguiente fragmento de código? Compruébalo.
int mi_funcion(int x)
{
x=x*5;
return x;
}
void main(void){
int y=3, x=4;
printf(“La function devuelde %d”, mi_funcion(y));
printf(“La variable vale %d”, x);
}
*/

#include <stdio.h>

int mi_funcion(int x)
{
    x = x * 5;
    return x;
}
void main(void)
{
    int y = 3, x = 4;
    printf("La function devuelde %d", mi_funcion(y));
    printf("La variable vale %d", x);
}