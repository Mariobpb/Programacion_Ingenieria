/*
Ejercicio 4: ¿Qué imprime?.
¿Qué imprime el siguiente fragmento de código? Compruébalo.
int mi_funcion(int x)
{
return x*x;
}
void main(void){
int x=3;
mi_funcion(x);
printf(“La function devuelde %d”, mi_funcion(x));
printf(“La variable vale %d”, x);
}
*/

#include <stdio.h>

int mi_funcion(int x)
{
    return x * x;
}
void main(void)
{
    int x = 3;
    mi_funcion(x);
    printf("La function devuelde %d", mi_funcion(x));
    printf("La variable vale %d", x);
}
